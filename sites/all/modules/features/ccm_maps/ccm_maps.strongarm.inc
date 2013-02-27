<?php
/**
 * @file
 * ccm_maps.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ccm_maps_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'leaflet_mapbox_code';
  $strongarm->value = 'websubstrate.CleCritMass-base';
  $export['leaflet_mapbox_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'leaflet_mapbox_description';
  $strongarm->value = '';
  $export['leaflet_mapbox_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'leaflet_mapbox_label';
  $strongarm->value = 'Cleveland Critical Mass - Base';
  $export['leaflet_mapbox_label'] = $strongarm;

  return $export;
}
