/**
 * @file
 * Layer handler for KML layers
 */

/**
 * Openlayer layer handler for KML layer
 */
(function($) {

    Drupal.openlayers.layer.pointtrack = function(title, map, options) {

        var features = null;
        options.projection = 'EPSG:' + options.projection;
        options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
        options.dataFrom = OpenLayers.Layer.PointTrack.TARGET_NODE;
        options.styleFrom = OpenLayers.Layer.PointTrack.TARGET_NODE;
        options.eventListeners = {
            'beforefeaturesadded': function(e) {
                var fid, points = [], feature;
                for (var i=0, len=e.features.length; i<len; i++) {
                    feature = e.features[i];
                    if (feature.fid !== fid || i === len-1) {
                        fid = feature.fid;
                        this.addNodes(points, {silent: true});
                        points = [];
                    }
                    points.push(feature);
                }
                return false;
            }
        };

        var layer = new OpenLayers.Layer.PointTrack(title, options);

        // KML Projection handling and formating options
        var kml_options = options.formatOptions;
        kml_options.internalProjection = new OpenLayers.Projection('EPSG:' + map.projection);
        kml_options.externalProjection = new OpenLayers.Projection(options.projection);

        // Use an AJAX like call to get data from URL
        OpenLayers.loadURL(options.url, {}, null, function (response) {
            var format = new OpenLayers.Format.KML(kml_options);
            var features = format.read(response.responseText);
            // Add features, if needed
            if (features) {
                layer.addFeatures(features);
            }
        });

        return layer;
    };

})(jQuery);
