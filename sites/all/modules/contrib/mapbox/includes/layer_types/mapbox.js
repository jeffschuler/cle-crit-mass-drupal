(function($) {

/**
 * For OpenLayers 0.x and 2.x
 */
Drupal.openlayers.layer.MapBox = function(title, map, options) {
  // Returns a new OpenLayers.Layer.XYZ object, configured per TileJSON snippet.
  var layer = new wax.ol.connector(options.tilejson);

  var styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
  layer.styleMap = styleMap;

  // Override layer name.
  if (options.layername !== undefined) {
    layer.setName(options.layername);
  }

  return layer;
};

})(jQuery);
