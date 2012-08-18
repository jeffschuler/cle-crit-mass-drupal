<?php
/**
 * @file
 * OpenLayers Views Vector Layer Type
 */

/**
 * Ctools plugin definition
 */
$plugin = array(
  'title' => t('Geofile Hybrid Layer'),
  'description' => t('Geofile Hybrid Layer'),
  'layer_type' => array(
    'file' => 'geofile_hybrid.inc',
    'class' => 'geofile_layer_type_geofile_hybrid',
    'parent' => 'openlayers_layer_type',
  ),
  'plugin module' => 'geofile',
);

class geofile_layer_type_geofile_hybrid extends openlayers_layer_type {
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
      'title' => 'geofile_hybrid',
      'layer_type' => 'geofile_hybrid',
      'layer_handler' => 'geofile_hybrid',
      'vector' => TRUE,
      'layers' => array(),
      'projection' => array('4326'),
      'baselayer' => FALSE,
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
    );
  }

  function get_files($view_name, $display_name) {
    /*
    if ($view = views_get_view($view_name)) {
      $args = array();
      // Retrieve args/filters from current view
      // to pass on to our vector layer.
      $current_view = views_get_current_view();
      if (!empty($current_view)) {
        $args = $current_view->args;
        if (isset($current_view->exposed_input)) {
          $view->set_exposed_input($current_view->exposed_input);
        }
      }
      $files = $view->execute_display($display_name, $args);

      // Get dynamic title from view
      $this->title = $view->get_title();

      $view->destroy();
    }
    return isset($files) ? $files : array();
    */
  }

  /**
   * Render.
   */
  function render(&$map) {
    /*
    drupal_add_js(drupal_get_path('module', 'geofile_views') .
      '/plugins/layer_types/geofile_hybrid.js');

    $files = $this->get_files($this->data['views']['view'],
      $this->data['views']['display']);
    $this->data['files'] = $files;
    */
    return $this->options;
  }
}
