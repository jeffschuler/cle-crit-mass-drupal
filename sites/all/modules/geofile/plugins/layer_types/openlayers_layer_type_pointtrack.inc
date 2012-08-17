<?php
/**
 * @file
 * KML Layer Type
 */

/**
 * Define the Ctools plugin options.
 */
$plugin = array(
  'title' => t('KML Track'),
  'description' => t('<a href="!url">KML track</a> overlay.',
    array('!url' => 'http://en.wikipedia.org/wiki/Keyhole_Markup_Language')),
  'layer_type' => array(
    'file' => 'openlayers_layer_type_pointtrack.inc',
    'class' => 'openlayers_layer_type_pointtrack',
    'parent' => 'openlayers_layer_type',
  ),
);

/**
 * OpenLayers KML Layer Type class
 */
class openlayers_layer_type_pointtrack extends openlayers_layer_type {
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
      'layer_type' => 'openlayer_layer_type_pointtrack',
      'layer_handler' => 'pointtrack',
      'projection' => array('4326'),
      'baselayer' => FALSE,
      'vector' => TRUE,
      'formatOptions' => array(
        'extractStyles' => TRUE,
        'extractAttributes' => TRUE,
        'extractTracks' => TRUE,
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
        '#description' => t('The URL of the KML file.'),
        '#maxlength' => 1024,
        '#default_value' => isset($this->data['url']) ?
          $this->data['url'] : ''
      ),
      'formatOptions' => array(
        'extractStyles' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Styles'),
          '#description' => t('Extract styles from KML.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractStyles']) ?
            $this->data['formatOptions']['extractStyles'] : TRUE,
        ),
        'extractAttributes' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Attributes'),
          '#description' => t('Extract attributes from KML.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractAttributes']) ?
            $this->data['formatOptions']['extractAttributes'] : TRUE,
        ),
        'extractTracks' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract tracks'),
          '#description' => t('Extract tracks from KML.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractTracks']) ?
            $this->data['formatOptions']['extractTracks'] : TRUE,
        ),
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_pointtrack'
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'geofile_views')
      . '/plugins/layer_types/openlayers_layer_type_pointtrack.js');
    return $this->options;
  }
}
