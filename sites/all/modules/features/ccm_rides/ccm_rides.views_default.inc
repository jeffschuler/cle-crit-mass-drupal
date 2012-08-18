<?php
/**
 * @file
 * ccm_rides.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ccm_rides_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'rides';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rides';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_ride_date' => 'field_ride_date',
    'field_attendees' => 'field_attendees',
    'field_distance' => 'field_distance',
    'field_endpoint_address' => 'field_endpoint_address',
    'field_endpoint_geolocation' => 'field_endpoint_geolocation',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ride_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attendees' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_distance' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_endpoint_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_endpoint_geolocation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Ride Date */
  $handler->display->display_options['fields']['field_ride_date']['id'] = 'field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['table'] = 'field_data_field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['field'] = 'field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_ride_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_ride_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_ride_date']['field_api_classes'] = 0;
  /* Field: Content: Attendees */
  $handler->display->display_options['fields']['field_attendees']['id'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['table'] = 'field_data_field_attendees';
  $handler->display->display_options['fields']['field_attendees']['field'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_attendees']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_attendees']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_attendees']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_attendees']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_attendees']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_attendees']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_attendees']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_attendees']['field_api_classes'] = 0;
  /* Field: Content: Distance */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['label'] = 'Distance (mi)';
  $handler->display->display_options['fields']['field_distance']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_distance']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_distance']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_distance']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_distance']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_distance']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_distance']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_distance']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_distance']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_distance']['field_api_classes'] = 0;
  /* Field: Content: Endpoint Address */
  $handler->display->display_options['fields']['field_endpoint_address']['id'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['table'] = 'field_data_field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['field'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_endpoint_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_endpoint_address']['field_api_classes'] = 0;
  /* Field: Content: Endpoint Geolocation */
  $handler->display->display_options['fields']['field_endpoint_geolocation']['id'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['table'] = 'field_data_field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['field'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['label'] = 'Endpoint Lat/Lon';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  $handler->display->display_options['fields']['field_endpoint_geolocation']['field_api_classes'] = 0;
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ride' => 'ride',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'rides';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Rides';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_ride_date';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_ride_date';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_endpoint_geolocation';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_ride_date';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'field_ride_date';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_endpoint_address';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Ride Date */
  $handler->display->display_options['fields']['field_ride_date']['id'] = 'field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['table'] = 'field_data_field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['field'] = 'field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_ride_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_ride_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ride_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ride_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_ride_date']['field_api_classes'] = 0;
  /* Field: Content: Attendees */
  $handler->display->display_options['fields']['field_attendees']['id'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['table'] = 'field_data_field_attendees';
  $handler->display->display_options['fields']['field_attendees']['field'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_attendees']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_attendees']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_attendees']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_attendees']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_attendees']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_attendees']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_attendees']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_attendees']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_attendees']['field_api_classes'] = 0;
  /* Field: Content: Distance */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['label'] = 'Distance (mi)';
  $handler->display->display_options['fields']['field_distance']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_distance']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_distance']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_distance']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_distance']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_distance']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_distance']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_distance']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_distance']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_distance']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_distance']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_distance']['field_api_classes'] = 0;
  /* Field: Content: Endpoint Address */
  $handler->display->display_options['fields']['field_endpoint_address']['id'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['table'] = 'field_data_field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['field'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_endpoint_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_endpoint_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_endpoint_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_endpoint_address']['field_api_classes'] = 0;
  /* Field: Content: Endpoint Geolocation */
  $handler->display->display_options['fields']['field_endpoint_geolocation']['id'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['table'] = 'field_data_field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['field'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['label'] = 'Endpoint Lat/Lon';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  $handler->display->display_options['fields']['field_endpoint_geolocation']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'ride-destinations.geojson';
  $export['rides'] = $view;

  return $export;
}
