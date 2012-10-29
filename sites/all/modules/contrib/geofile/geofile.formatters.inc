<?php

/**
 * @file
 * Drupal field formatter hooks and helper functions.
 */

/**
 * Implements hook_field_formatter_info().
 */
function geofile_field_formatter_info() {
  $formatters = array(
    'geofile_file' => array(
      'label' => t('Geofile Map'),
      'field types' => array('file'),
      'settings' => array(
        'data' => 'full',
        'map_preset' => 'geofile_formatter_map',
        'layer_type' => 'auto',
        'hybrid_mode' => 'single',
        'openlayers_layer_type_kml' => array(
          'extractStyles' => TRUE,
          'extractTracks' => TRUE,
          'extractAttributes' => TRUE,
          'maxDepth' => 1,
        ),
        'openlayers_layer_type_gml' => array(
          'extractWaypoints' => TRUE,
          'extractRoutes' => TRUE,
          'extractAttributes' => TRUE,
          'extractTracks' => TRUE,
        ),
      ),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function geofile_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  // Map preset formatter
  if ($display['type'] == 'geofile_file' && module_exists('openlayers')) {
    // Get preset options, filtered to those which have the GeoField placeholder layer
    $presets = openlayers_presets();
    $preset_options = array();
    foreach ($presets as $preset) {
      if (in_array('geofile_hybrid', $preset->data['layers'])) {
        $preset_options[$preset->name] = $preset->title;
      }
    }

    $layer_types = openlayers_layer_types();

    foreach (openlayers_layer_types() as $key => $plugin) {

      $options['auto'] = t('Autodetect with file extension');

      if ($plugin['module'] == 'openlayers' && $plugin['name'] == 'openlayers_layer_type_kml') {

      }
      elseif ($plugin['module'] != 'geofile_views' || $plugin['name'] == 'geofile_views_file') {
        continue;
      }

      $class = ctools_plugin_get_class($plugin, 'layer_type');
      if ($class) {
        $options[$key] = $plugin['title'];
      }
    }

    $element['map_preset'] = array(
      '#title' => t('OpenLayers Preset'),
      '#type' => 'select',
      '#default_value' => $settings['map_preset'] ? $settings['map_preset'] : 'geofile_formatter_map',
      '#required' => TRUE,
      '#options' => $preset_options,
      '#description' => t('Select which OpenLayers map you would like to use. Only maps which have the geofile placeholder layer may be selected. If your preferred map is not here, add the geofile placeholder layer to it first.'),
    );

    $element['layer_type'] = array(
      '#title' => t('OpenLayers Layer'),
      '#type' => 'select',
      '#default_value' => $settings['layer_type'] ? $settings['layer_type'] : '',
      '#required' => TRUE,
      '#options' => $options,
      '#description' => t('Select which OpenLayers map you would like to use. Only maps which have the geofile placeholder layer may be selected. If your preferred map is not here, add the geofile placeholder layer to it first.'),
    );

    $element['hybrid_mode'] = array(
      '#title' => t('Geofile Hybrid Mode'),
      '#type' => 'select',
      '#default_value' => $settings['hybrid_mode'] ? $settings['hybrid_mode'] : 'single',
      '#required' => TRUE,
      '#options' => array('single' => 'Single', 'multi' => 'Multi'),
    );

    $element['openlayers_layer_type_kml'] = array(
      '#type' => 'fieldset',
      '#title' => 'KML',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    $element['openlayers_layer_type_gml'] = array(
      '#type' => 'fieldset',
      '#title' => 'GPX',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    $element['openlayers_layer_type_kml']['extractStyles'] = array(
      '#type' => 'checkbox',
      '#title' => t('Extract Styles'),
      '#description' => t('Extract styles from KML.'),
      '#default_value' => isset(
      $settings['openlayers_layer_type_kml']['extractStyles']) ?
        $settings['openlayers_layer_type_kml']['extractStyles'] : TRUE,
    );
    $element['openlayers_layer_type_kml']['extractAttributes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Extract Attributes'),
      '#description' => t('Extract attributes from KML.'),
      '#default_value' => isset(
      $settings['openlayers_layer_type_kml']['extractAttributes']) ?
        $settings['openlayers_layer_type_kml']['extractAttributes'] : TRUE,
    );
    $element['openlayers_layer_type_kml']['maxDepth'] = array(
      '#type' => 'textfield',
      '#title' => t('Max depth'),
      '#description' => t('Max depth.'),
      '#default_value' => isset(
      $settings['openlayers_layer_type_kml']['maxDepth']) ?
        $settings['openlayers_layer_type_kml']['maxDepth'] : 1,
    );
    $element['openlayers_layer_type_kml']['projection'] = array(
      '#type' => 'hidden',
      '#value' => array('4326'),
    );

    $element['openlayers_layer_type_gml']['extractWaypoints'] = array(
      '#type' => 'checkbox',
      '#title' => t('Extract Waypoints'),
      '#description' => t('Extract waypoints from GPX.'),
      '#default_value' => isset(
      $settings['openlayers_layer_type_gml']['extractWaypoints']) ?
        $settings['openlayers_layer_type_gml']['extractWaypoints'] : TRUE,
    );
    $element['openlayers_layer_type_gml']['extractRoutes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Extract Routes'),
      '#description' => t('Extract routes from GPX.'),
      '#default_value' => isset(
      $settings['openlayers_layer_type_gml']['extractRoutes']) ?
        $settings['openlayers_layer_type_gml']['extractRoutes'] : TRUE,
    );
    $element['openlayers_layer_type_gml']['extractAttributes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Extract Attributes'),
      '#description' => t('Extract attributes from KML.'),
      '#default_value' => isset(
      $settings['openlayers_layer_type_gml']['extractAttributes']) ?
        $settings['openlayers_layer_type_gml']['extractAttributes'] : TRUE,
    );
    $element['openlayers_layer_type_gml']['extractTracks'] = array(
      '#type' => 'checkbox',
      '#title' => t('Extract Tracks'),
      '#description' => t('Extract tracks from KML.'),
      '#default_value' => isset(
      $settings['openlayers_layer_type_gml']['extractTracks']) ?
        $settings['openlayers_layer_type_gml']['extractTracks'] : TRUE,
    );
    $element['openlayers_layer_type_gml']['projection'] = array(
      '#type' => 'hidden',
      '#value' => array('4326'),
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function geofile_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  if ($display['type'] == 'geofile_file') {
    if (!empty($settings['map_preset'])) {
      $openlayers_presets = openlayers_preset_options();
      $summary[] = t('Openlayers Map: @data', array('@data' => $openlayers_presets[$settings['map_preset']]));
    }

    $summary[] = t('Layer: @value', array('@value' => $settings['layer_type']));
    $summary[] = t('Hybrid mode: @value', array('@value' => $settings['hybrid_mode']));
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 */
function geofile_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'geofile_file':
      $map_name = $display['settings']['map_preset'] ? $display['settings']['map_preset'] : 'geofile_formatter_map';
      $layer_type = $display['settings']['layer_type'] ? $display['settings']['layer_type'] : 'auto';
      $hybrid_mode = $display['settings']['hybrid_mode'] ? $display['settings']['hybrid_mode'] : 'single';
      $element[0] = array('#markup' => _geofile_openlayers_formatter($map_name, $layer_type, $items, $display['settings'], $hybrid_mode));
      return $element;
  }

  return $element;
}

function _geofile_openlayers_formatter($map_name, $layer_type, $items, $options, $hybrid_mode) {
  $preset = openlayers_preset_load($map_name);
  $map = openlayers_build_map($preset->data);
  $layers = openlayers_layer_types();
  $hybrid = openlayers_layer_type_load('geofile_hybrid');

  if ($hybrid_mode == 'single') {
    $map['layers']['geofile_hybrid'] = $hybrid->data;
  }

  foreach ($items as $key => $delta) {
    $layer_embbed_type = _geofile_get_layer_type_from_uri($delta, $layer_type);
    $layer_class = ctools_plugin_get_class($layers[$layer_embbed_type], 'layer_type');
    $layer_embbed = _geofile_create_embbed_layer($layer_class, $delta, $options);

    if ($hybrid_mode == 'single') {
      $hybrid_name = 'geofile_hybrid';
      $map['layers'][$hybrid_name]['layers'][] = $layer_embbed;
    }
    else {
      $hybrid_name = 'geofile_hybrid_' . $key;
      $map['layers'][$hybrid_name] = $hybrid->data;
      $map['layers'][$hybrid_name]['title'] = $layer_embbed['title'];
      $map['layers'][$hybrid_name]['layers'][] = $layer_embbed;

      if (isset($map['layer_styles']['geofile_hybrid'])) {
        $map['layer_styles'][$hybrid_name] = $map['layer_styles']['geofile_hybrid'];
      }

      if (isset($map['layer_styles_select']['geofile_hybrid'])) {
        $map['layer_styles_select'][$hybrid_name] = $map['layer_styles_select']['geofile_hybrid'];
      }

      if ($map['layer_activated']['geofile_hybrid'] == 'geofile_hybrid') {
        $map['layer_activated'][$hybrid_name] = $hybrid_name;
      }
      if ($map['layer_switcher']['geofile_hybrid'] == 'geofile_hybrid') {
        $map['layer_switcher'][$hybrid_name] = $hybrid_name;
      }
      if (isset($map['behaviors']['openlayers_behavior_popup']) && $map['behaviors']['openlayers_behavior_popup']['layers']['geofile_hybrid'] == 'geofile_hybrid') {
        $map['behaviors']['openlayers_behavior_popup']['layers'][$hybrid_name] = $hybrid_name;
      }
      if (isset($map['behaviors']['openlayers_behavior_zoomtolayer']) && $map['behaviors']['openlayers_behavior_zoomtolayer']['zoomtolayer'] == 'geofile_hybrid') {
        $map['behaviors']['openlayers_behavior_zoomtolayer']['zoomtolayer'] = $hybrid_name;
      }
    }

    if (isset($map['behaviors']['openlayers_behavior_layerswitcher'])) {
      $map['layer_switcher'][$hybrid_name] = $hybrid_name;
    }

    drupal_add_js(drupal_get_path("module", $layers[$layer_class]['module']) . '/plugins/layer_types/' . $layer_class . '.js');
  }

  drupal_add_js(drupal_get_path("module", 'geofile') . '/plugins/layer_types/geofile_hybrid.js');

  if (!isset($map['layers']['geofile_hybrid'])) {
    drupal_set_message(t('Trying to render a geofile formatter on a map without the placeholder layer'), 'error');
  }

  // Return themed map if no errors found
  if (empty($map['errors'])) {
    $js = array('openlayers' => array('maps' => array($map['id'] => $map)));
    drupal_add_js($js, 'setting');

    // Push map through theme function and return
    $output = theme('openlayers_map', array(
      'map' => $map,
      'map_name' => $map_name
    ));
  }
  return $output;
}

function _geofile_create_embbed_layer($layer_class, $item, $options) {
  $layer_embbed = openlayers_layer_type_load($layer_class);
  $layer_embbed->data['url'] = file_create_url($item['uri']);
  $layer_embbed->data['formatOptions'] = $options[$layer_class];
  $layer_embbed->data['title'] = basename($item['uri']);
  return $layer_embbed->data;
}

function _geofile_get_layer_type_from_uri($item, $layer_type) {
  $file = $item['uri'];
  $ext = pathinfo($file, PATHINFO_EXTENSION);

  if ($layer_type == 'auto') {
    if (in_array($ext, array('kml', 'kmz'))) {
      $layer_embbed_type = 'openlayers_layer_type_kml';
    }
    if (in_array($ext, array('gpx'))) {
      $layer_embbed_type = 'openlayers_layer_type_gml';
    }
  }

  return $layer_embbed_type;
}
