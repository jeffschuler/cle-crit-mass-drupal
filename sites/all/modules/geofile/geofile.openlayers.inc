<?php

/**
 * @file
 * Provides hooks for integration with OpenLayers (http://drupal.org/project/openlayers)
 */

/**
 * Implements hook_openlayers_maps().
 */
function geofile_openlayers_maps() {
  $formatter = new stdClass();
  $formatter->api_version = 1;
  $formatter->name = 'geofile_formatter_map';
  $formatter->title = t('Geofile Formatter Map');
  $formatter->description = t('A Map Used for Geofile Output');
  $formatter->data = array(
    'width' => '100%',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 0',
        'zoom' => '1',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'geofile_hybrid' => 'geofile_hybrid',
    ),
    'layer_weight' => array(
      'geofile_hybrid' => '0',
    ),
    'layer_styles' => array(
      'geofile_hybrid' => '0',
    ),
    'layer_styles_select' => array(
      'geofile_hybrid' => '0',
    ),
    'layer_activated' => array(
      'geofile_hybrid' => 'geofile_hybrid',
    ),
    'layer_switcher' => array(
      'geofile_hybrid' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
    'map_name' => 'geofile_formatter_map',
  );

  return array(
    'geofile_formatter_map' => $formatter,
  );
}

/**
 * Formatter layers
 */
function geofile_openlayers_layers() {
  $layers = array();
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'geofile_hybrid';
  $layer->title = 'Placeholder for Geofile Hybrid Formatter';
  $layer->description = '';
  $layer->data = array(
    'layer_type' => 'geofile_hybrid',
    'projection' => array('4326'),
    'features' => array(),
  );
  $layers[$layer->name] = $layer;
  return $layers;
}
