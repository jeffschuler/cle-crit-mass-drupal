<?php
/**
 * @file
 * ccm_rides.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ccm_rides_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ride_importer';
  $feeds_importer->config = array(
    'name' => 'Ride Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'ride',
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'Date',
            'target' => 'field_ride_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Trace Type',
            'target' => 'field_trace_type',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Route Link',
            'target' => 'field_route_link:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Endpoint',
            'target' => 'field_endpoint_info',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Recap Link',
            'target' => 'field_ride_recap_link:url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Notes',
            'target' => 'field_notes',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Attendees',
            'target' => 'field_attendees',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Distance (mi)',
            'target' => 'field_distance',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ride_importer'] = $feeds_importer;

  return $export;
}
