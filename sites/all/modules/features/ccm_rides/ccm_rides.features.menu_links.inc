<?php
/**
 * @file
 * ccm_rides.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ccm_rides_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:rides
  $menu_links['main-menu:rides'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'rides',
    'router_path' => 'rides',
    'link_title' => 'Rides',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Rides');


  return $menu_links;
}
