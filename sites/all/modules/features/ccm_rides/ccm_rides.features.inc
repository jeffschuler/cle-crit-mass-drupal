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
