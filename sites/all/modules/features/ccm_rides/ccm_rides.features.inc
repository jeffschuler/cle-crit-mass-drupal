<?php
/**
 * @file
 * ccm_rides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccm_rides_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ccm_rides_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_custom_pagers().
 */
function ccm_rides_default_custom_pagers() {
  $custom_pagers = array();

  $custom_pagers[] = array(
    'pid' => '1',
    'title' => 'Rides',
    'list_php' => '',
    'view' => 'rides',
    'args' => '',
    'position' => 'top',
    'visibility_php' => '',
    'node_type' => 'ride',
    'reverse_list' => '0',
  );
  return $custom_pagers;
}

/**
 * Implements hook_node_info().
 */
function ccm_rides_node_info() {
  $items = array(
    'ride' => array(
      'name' => t('Ride'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
