/**
 * @file
 * Layer handler for KML layers
 */

/**
 * Openlayer layer handler for KML layer
 */
(function($) {

    Drupal.openlayers.layer.gml = function(title, map, options) {

        var features = null;
        options.projection = 'EPSG:' + options.projection;
        options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
        //var layer = new OpenLayers.Layer.Vector(title, options);

        // KML Projection handling and formating options
        var kml_options = options.formatOptions;
        kml_options.internalProjection = new OpenLayers.Projection('EPSG:' + map.projection);
        kml_options.externalProjection = new OpenLayers.Projection(options.projection);

        var layer = new OpenLayers.Layer.GML(title, options.url, {
            format: OpenLayers.Format.GPX,
            //style: {strokeColor: "green", strokeWidth: 5, strokeOpacity: 0.5},
            projection: new OpenLayers.Projection("EPSG:4326")
        });

        return layer;
    };

})(jQuery);
