/**
 * OpenLayers Views Vector Layer Handler
 */
(function($) {

    Drupal.openlayers.layer.geofile_hybrid = function(title, map, options) {

        var layer, layer_embed, i, layerCount;

        options.projection = 'EPSG:' + options.projection;
        options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);

        layer = new OpenLayers.Layer.Vector(title, options);

        function get_format(layer_embed){
            if (layer_embed['layer_handler'] == 'kml') {
                return new OpenLayers.Format.KML(layer_embed['formatOptions']);
            }else if (layer_embed['layer_handler'] == 'gml') {
                return new OpenLayers.Format.GPX(layer_embed['formatOptions']);
            }
        }

        function get_callback(layer_embed, last){
            var features
                , last = last || false
                , callback = function(response) {
                    features = get_format(layer_embed).read(response.responseText);
                    if (features) {
                        layer.addFeatures(features);
                    }
                    if (last){
                        // need to patch openlayers for this.
                        layer.events.triggerEvent('loadend');
                    }
                };
            return callback;
        }

        layerCount = options.layers.length;
        for (i=0; i<layerCount; i++) {
            layer_embed = options.layers[i];
            layer_embed['formatOptions'].internalProjection = new OpenLayers.Projection('EPSG:' + map.projection);
            layer_embed['formatOptions'].externalProjection = new OpenLayers.Projection(options.projection);
            OpenLayers.Request.GET({ url: layer_embed['url'], callback: get_callback(layer_embed, i==layerCount-1) });
        }

        return layer;

    };

})(jQuery);
