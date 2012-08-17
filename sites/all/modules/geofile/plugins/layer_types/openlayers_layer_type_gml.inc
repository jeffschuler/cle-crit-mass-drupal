<?php
/**
 * @file
 * KML Layer Type
 */

/**
 * Define the Ctools plugin options.
 */
$plugin = array(
  'title' => t('GML Track'),
  'description' => t('<a href="!url">KML track</a> overlay.',
    array('!url' => 'http://en.wikipedia.org/wiki/Keyhole_Markup_Language')),
  'layer_type' => array(
    'file' => 'openlayers_layer_type_gml.inc',
    'class' => 'openlayers_layer_type_gml',
    'parent' => 'openlayers_layer_type',
  ),
);

/**
 * OpenLayers GML Layer Type class
 */
class openlayers_layer_type_gml extends openlayers_layer_type {
  function __construct($layer = array(), $map = array()) {
    parent::__construct($layer, $map);
    if (isset($this->data)) {
      $this->data += $this->options_init();
    }
    else {
      $this->data = $this->options_init();
    }
  }

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_type' => 'gml',
      'layer_handler' => 'gml',
      'projection' => array('4326'),
      'baselayer' => FALSE,
      'vector' => TRUE,
      'url' => NULL,
      'formatOptions' => array(
        'extractWaypoints' => TRUE,
        'extractTracks' => TRUE,
        'extractRoutes' => TRUE,
        'extractAttributes' => TRUE
      ),
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'url' => array(
        '#type' => 'textfield',
        '#title' => t('URL'),
        '#description' => t('The URL of the GML file.'),
        '#maxlength' => 1024,
        '#default_value' => isset($this->data['url']) ?
          $this->data['url'] : ''
      ),
      'formatOptions' => array(
        'extractWaypoints' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Waypoints'),
          '#description' => t('Extract waypoints from GML.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractWaypoints']) ?
            $this->data['formatOptions']['extractWaypoints'] : TRUE,
        ),
        'extractTracks' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Tracks'),
          '#description' => t('Extract tracks from GML.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractTracks']) ?
            $this->data['formatOptions']['extractTracks'] : TRUE,
        ),
        'extractRoutes' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Routes'),
          '#description' => t('Extract routes from GML.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractRoutes']) ?
            $this->data['formatOptions']['extractRoutes'] : TRUE,
        ),
        'extractAttributes' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Attributes'),
          '#description' => t('Extract attributes from GML.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractAttributes']) ?
            $this->data['formatOptions']['extractAttributes'] : TRUE,
        ),
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_gml'
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'geofile_views')
      . '/plugins/layer_types/openlayers_layer_type_gml.js');
    return $this->options;
  }
}
