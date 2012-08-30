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

  $view = new view();
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
  $handler->display->display_options['title'] = 'Rides List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Ride Date */
  $handler->display->display_options['fields']['field_ride_date']['id'] = 'field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['table'] = 'field_data_field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['field'] = 'field_ride_date';
  $handler->display->display_options['fields']['field_ride_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_ride_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ride_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_ride_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Trace Type */
  $handler->display->display_options['fields']['field_trace_type']['id'] = 'field_trace_type';
  $handler->display->display_options['fields']['field_trace_type']['table'] = 'field_data_field_trace_type';
  $handler->display->display_options['fields']['field_trace_type']['field'] = 'field_trace_type';
  /* Field: Content: Endpoint Address */
  $handler->display->display_options['fields']['field_endpoint_address']['id'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['table'] = 'field_data_field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['field'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_endpoint_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Attendees */
  $handler->display->display_options['fields']['field_attendees']['id'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['table'] = 'field_data_field_attendees';
  $handler->display->display_options['fields']['field_attendees']['field'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Distance */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['label'] = 'Distance (mi)';
  $handler->display->display_options['fields']['field_distance']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Header';
  $handler->display->display_options['header']['area']['content'] = '<p>If <em>Trace Type</em> is empty, we don\'t have the route for this ride. If you can help, please <a href="/contact">Contact</a>.</p>
<p>See <a href="/about">About</a> for data attribution.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'rides';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Rides List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: GeoJSON */
  $handler = $view->new_display('feed', 'GeoJSON', 'feed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['fields']['field_ride_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_ride_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_ride_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Attendees */
  $handler->display->display_options['fields']['field_attendees']['id'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['table'] = 'field_data_field_attendees';
  $handler->display->display_options['fields']['field_attendees']['field'] = 'field_attendees';
  $handler->display->display_options['fields']['field_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Distance */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['label'] = 'Distance (mi)';
  $handler->display->display_options['fields']['field_distance']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_distance']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Endpoint Address */
  $handler->display->display_options['fields']['field_endpoint_address']['id'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['table'] = 'field_data_field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['field'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['text'] = '[field_endpoint_address-organisation_name] - [field_endpoint_address-thoroughfare]';
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_endpoint_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Endpoint Geolocation */
  $handler->display->display_options['fields']['field_endpoint_geolocation']['id'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['table'] = 'field_data_field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['field'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['label'] = 'Endpoint Lat/Lon';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Endpoint Geolocation (field_endpoint_geolocation:wkt) */
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['id'] = 'field_endpoint_geolocation_wkt';
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['table'] = 'field_data_field_endpoint_geolocation';
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['field'] = 'field_endpoint_geolocation_wkt';
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'ride-destinations.geojson';
  $export['rides'] = $view;

  return $export;
}
