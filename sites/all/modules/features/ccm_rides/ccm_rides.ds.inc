<?php
/**
 * @file
 * ccm_rides.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ccm_rides_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ride|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ride';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_endpoint_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Endpoint',
        ),
      ),
    ),
    'field_route' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Download GPX',
        ),
      ),
    ),
    'field_route_geojson' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Download GeoJSON',
        ),
      ),
    ),
  );
  $export['node|ride|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ccm_rides_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ride|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ride';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_ride_date',
        1 => 'field_endpoint_address',
        2 => 'field_distance',
        3 => 'field_attendees',
        4 => 'field_ride_recap_link',
        5 => 'field_route_geojson',
        6 => 'field_route',
      ),
      'right' => array(
        7 => 'field_route_geofield',
      ),
    ),
    'fields' => array(
      'field_ride_date' => 'left',
      'field_endpoint_address' => 'left',
      'field_distance' => 'left',
      'field_attendees' => 'left',
      'field_ride_recap_link' => 'left',
      'field_route_geojson' => 'left',
      'field_route' => 'left',
      'field_route_geofield' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|ride|default'] = $ds_layout;

  return $export;
}
