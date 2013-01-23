<?php

/**
 * @file MapBox layer type definition for OpenLayers
 */
class openlayers_layer_type_mapbox extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'url_jsonp' => '',
      'tilejson' => '',
      'serverResolutions' => openlayers_get_resolutions('900913'),
      'maxExtent' => openlayers_get_extent('900913'),
      'projection' => array('900913'),
      'layername' => '',
      'baselayer' => TRUE,
      'layer_handler' => 'MapBox',
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    if (!isset($this->data)) {
      $this->data = $this->options_init();
    }
    return array(
      'url_jsonp' => array(
        '#type' => 'textfield',
        '#title' => t('url_jsonp'),
        '#description' => t('', array()),
        '#default_value' => $this->data['url_jsonp'],
      ),
      'tilejson' => array(
        '#type' => 'textarea',
        '#title' => t('tilejson'),
        '#description' => t('Leave empty to get auto-populated.', array()),
        '#default_value' => $this->data['tilejson'],
      ),
      'layername' => array(
        '#type' => 'textfield',
        '#title' => t('Override Layer Name'),
        '#description' => t('', array()),
        '#default_value' => $this->data['layername']
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_mapbox',
      ),
      'baselayer' => array(
        '#type' => 'checkbox',
        '#default_value' => $this->data['baselayer'],
        '#title' => t('BaseLayer'),
        '#description' => t('Uncheck to make this map an overlay.'),
      ),
      'projection' => array(
        '0' => array(
          '#type' => 'hidden',
          '#value' => '900913',
        ),
      ),
    );
  }

  /**
   * Override to_record().
   */
  function to_record() {
    // Trim.
    foreach (array('url_jsonp', 'tilejson', 'layername') as $key) {
      $this->data[$key] = trim($this->data[$key]);
    }

    // Get tilejson.
    if (!empty($this->data['url_jsonp']) && empty($this->data['tilejson'])) {
      $result = drupal_http_request($this->data['url_jsonp'], array());
      if ($result->code == 200 && strpos($result->data, 'grid(') === 0 && strrpos($result->data, ');') === strlen($result->data) - 2) {
        $this->data['tilejson'] = drupal_substr($result->data, 5, -2);
      }
      else {
        // TODO
      }
    }

    return parent::to_record();
  }

  /**
   * Render.
   */
  function render(&$map) {
    $this->data['tilejson'] = drupal_json_decode($this->data['tilejson']);

    if (empty($this->data['layername'])) {
      unset($this->data['layername']);
    }

    drupal_add_js(libraries_get_path('wax') . '/dist/wax.ol.min.js');

    drupal_add_js(drupal_get_path('module', 'mapbox') . '/includes/layer_types/mapbox.js');
    drupal_add_css(drupal_get_path('module', 'mapbox') . '/js/mapbox.css');
    return $this->options;
  }
}
