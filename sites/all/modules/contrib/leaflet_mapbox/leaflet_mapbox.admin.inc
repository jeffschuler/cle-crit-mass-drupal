<?php

/**
 * @file
 * Leaflet MapBox module admin file.
 */

function leaflet_mapbox_configuration_form($form, &$form_state) {
  $form['leaflet_mapbox_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Map label'),
    '#required' => TRUE,
    '#default_value' => variable_get('leaflet_mapbox_label', ''),
  );
  $form['leaflet_mapbox_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Map code'),
    '#required' => TRUE,
    '#default_value' => variable_get('leaflet_mapbox_code', ''),
  );
  $form['leaflet_mapbox_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Map description'),
    '#default_value' => variable_get('leaflet_mapbox_description', ''),
  );
  return system_settings_form($form);
}
