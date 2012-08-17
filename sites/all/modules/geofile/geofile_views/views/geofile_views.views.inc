<?php

/**
 * @file
 * This file holds main views functions for the openlayers_views module.
 *
 * @ingroup openlayers
 */

/**
 * Implementation of hook_views_plugins().
 */
function geofile_views_views_plugins() {
  return array(
    'module' => 'geofile_views',
    'style' => array(
      'geofile_map' => array(
        'title' => t('Geofile Map'),
        'help' => t('Displays a View as an Geofile map.'),
        'handler' => 'geofile_views_plugin_style_map',
        'path' => drupal_get_path('module', 'geofile_views') . '/includes',
        'uses fields' => TRUE,
        'uses row plugin' => FALSE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'even empty' => TRUE,
      ),
    ),
  );
}
