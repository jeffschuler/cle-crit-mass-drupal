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
    'field_trace_type' => 'field_trace_type',
    'field_endpoint_address' => 'field_endpoint_address',
    'field_attendees' => 'field_attendees',
    'field_distance' => 'field_distance',
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
    'field_trace_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_endpoint_address' => array(
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
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Missing';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>These rides are missing route information. If you can supply GPS track data or know what the route was, please <a href="/contact">let us know</a>!</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  /* Field: Content: Distance (mi) */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['label'] = 'Distance';
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
  $handler->display->display_options['header']['area']['content'] = '<p>If <em>Trace Type</em> is empty, we don\'t have the route for this ride. If you can help, please <a href="/contact">drop a line</a>.</p>
<p>See <a href="/about">About</a> for more info on where this data came from and how it got here.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Ride Date (field_ride_date) */
  $handler->display->display_options['sorts']['field_ride_date_value']['id'] = 'field_ride_date_value';
  $handler->display->display_options['sorts']['field_ride_date_value']['table'] = 'field_data_field_ride_date';
  $handler->display->display_options['sorts']['field_ride_date_value']['field'] = 'field_ride_date_value';
  $handler->display->display_options['sorts']['field_ride_date_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'rides';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Rides List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: GeoJSON */
  $handler = $view->new_display('page', 'GeoJSON', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_endpoint_address_1';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_endpoint_address_1';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_endpoint_geolocation';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_endpoint_address_1';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'field_ride_date';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_endpoint_address';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Endpoint Address */
  $handler->display->display_options['fields']['field_endpoint_address_1']['id'] = 'field_endpoint_address_1';
  $handler->display->display_options['fields']['field_endpoint_address_1']['table'] = 'field_data_field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address_1']['field'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_endpoint_address_1']['type'] = 'organisation_name';
  $handler->display->display_options['fields']['field_endpoint_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Endpoint Address */
  $handler->display->display_options['fields']['field_endpoint_address_2']['id'] = 'field_endpoint_address_2';
  $handler->display->display_options['fields']['field_endpoint_address_2']['table'] = 'field_data_field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address_2']['field'] = 'field_endpoint_address';
  $handler->display->display_options['fields']['field_endpoint_address_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address_2']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_endpoint_address_2']['type'] = 'thoroughfare';
  $handler->display->display_options['fields']['field_endpoint_address_2']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
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
  $handler->display->display_options['fields']['field_ride_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_ride_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_ride_date']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['text'] = '[field_endpoint_address-organisation_name] - [field_endpoint_address-thoroughfare]';
  $handler->display->display_options['fields']['field_endpoint_address']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_address']['element_default_classes'] = FALSE;
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
  /* Field: Content: Distance (mi) */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Endpoint Geolocation */
  $handler->display->display_options['fields']['field_endpoint_geolocation']['id'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['table'] = 'field_data_field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['field'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_endpoint_geolocation']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['settings'] = array(
    'data' => 'full',
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Endpoint Geolocation (field_endpoint_geolocation:wkt) */
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['id'] = 'field_endpoint_geolocation_wkt';
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['table'] = 'field_data_field_endpoint_geolocation';
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['field'] = 'field_endpoint_geolocation_wkt';
  $handler->display->display_options['filters']['field_endpoint_geolocation_wkt']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'ride-destinations.geojson';

  /* Display: Destinations */
  $handler = $view->new_display('page', 'Destinations', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ride Destinations';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'field_endpoint_geolocation';
  $handler->display->display_options['style_options']['name_field'] = 'field_ride_date';
  $handler->display->display_options['style_options']['description_field'] = 'field_endpoint_address';
  $handler->display->display_options['style_options']['map'] = 'mapbox-streets';
  $handler->display->display_options['style_options']['height'] = '600';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Distance (mi) */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Endpoint Geolocation */
  $handler->display->display_options['fields']['field_endpoint_geolocation']['id'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['table'] = 'field_data_field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['field'] = 'field_endpoint_geolocation';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_endpoint_geolocation']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['path'] = 'destinations';

  /* Display: Missing Routes Page */
  $handler = $view->new_display('page', 'Missing Routes Page', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Missing Routes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Route (field_route:fid) */
  $handler->display->display_options['filters']['field_route_fid']['id'] = 'field_route_fid';
  $handler->display->display_options['filters']['field_route_fid']['table'] = 'field_data_field_route';
  $handler->display->display_options['filters']['field_route_fid']['field'] = 'field_route_fid';
  $handler->display->display_options['filters']['field_route_fid']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'missing-routes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Missing Routes';
  $handler->display->display_options['menu']['description'] = 'List of rides missing route information or GPS data.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['rides'] = $view;

  return $export;
}
