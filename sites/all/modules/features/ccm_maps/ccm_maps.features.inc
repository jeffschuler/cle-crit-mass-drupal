<?php
/**
 * @file
 * ccm_maps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccm_maps_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
