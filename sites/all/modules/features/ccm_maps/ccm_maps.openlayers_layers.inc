<?php
/**
 * @file
 * ccm_maps.openlayers_layers.inc
 */

/**
 * Implements hook_openlayers_layers().
 */
function ccm_maps_openlayers_layers() {
  $export = array();

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'clecritmass';
  $openlayers_layers->title = 'CleCritMass';
  $openlayers_layers->description = 'Mapbox - Cleveland Critical Mass - all';
  $openlayers_layers->data = array(
    'url_jsonp' => 'http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass.jsonp',
    'tilejson' => '{"attribution":"Map data, OpenStreetMap","basename":"CleCritMass.mbtiles","bounds":[-82.2667,41.1325,-81.1447,41.7799],"center":[-81.7037,41.5007,11],"description":"Cleveland Critical Mass rides, 8/2009 - Present. http://ccm.websubstrate.com/","download":"http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass.mbtiles","filesize":616227840,"grids":["http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.grid.json","http://b.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.grid.json","http://c.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.grid.json","http://d.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.grid.json"],"id":"websubstrate.CleCritMass","legend":"<strong>Cleveland Critical Mass</strong><br />\\nRides and destinations, 2009-present","maxzoom":17,"minzoom":0,"name":"Cleveland Critical Mass","private":false,"scheme":"xyz","template":"{{#__location__}}{{/__location__}}{{#__teaser__}}<strong>{{{name}}}</strong><br />\\n<strong>Destination:</strong> {{{description}}}<br />\\n<strong>Riders:</strong> {{{field_attendees}}}<br />\\n<strong>Distance:</strong> {{{field_distance}}} mi.{{/__teaser__}}{{#__full__}}{{/__full__}}","tilejson":"2.0.0","tiles":["http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.png","http://b.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.png","http://c.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.png","http://d.tiles.mapbox.com/v3/websubstrate.CleCritMass/{z}/{x}/{y}.png"],"version":"1.0.0","webpage":"http://tiles.mapbox.com/websubstrate/map/CleCritMass"}',
    'layername' => '',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'baselayer' => 1,
    'projection' => array(
      0 => '900913',
    ),
  );
  $export['clecritmass'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'clecritmass_base';
  $openlayers_layers->title = 'CleCritMass-base';
  $openlayers_layers->description = 'Mapbox - Cleveland Critical Mass - base';
  $openlayers_layers->data = array(
    'url_jsonp' => 'http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass-base.jsonp',
    'tilejson' => '{"attribution":"Map data, OpenStreetMap","bounds":[-82.2667,41.1325,-81.1447,41.7799],"center":[-81.7037,41.5007,11],"description":"Cleveland Critical Mass base map.\\nhttp://ccm.websubstrate.com/","filesize":598054912,"id":"websubstrate.CleCritMass-base","legend":null,"maxzoom":17,"minzoom":0,"name":"Cleveland Critical Mass - Base","scheme":"xyz","tilejson":"2.0.0","tiles":["http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass-base/{z}/{x}/{y}.png","http://b.tiles.mapbox.com/v3/websubstrate.CleCritMass-base/{z}/{x}/{y}.png","http://c.tiles.mapbox.com/v3/websubstrate.CleCritMass-base/{z}/{x}/{y}.png","http://d.tiles.mapbox.com/v3/websubstrate.CleCritMass-base/{z}/{x}/{y}.png"],"version":"1.0.0","webpage":"http://tiles.mapbox.com/websubstrate/map/CleCritMass-base"}',
    'layername' => '',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'baselayer' => 1,
    'projection' => array(
      0 => '900913',
    ),
  );
  $export['clecritmass_base'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'clecritmass_data';
  $openlayers_layers->title = 'CleCritMass-data';
  $openlayers_layers->description = 'Mapbox - Cleveland Critical Mass - data';
  $openlayers_layers->data = array(
    'url_jsonp' => 'http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass-data.jsonp',
    'tilejson' => '{"attribution":"Map data, OpenStreetMap","bounds":[-82.2667,41.1325,-81.1447,41.7799],"center":[-81.7037,41.5007,11],"description":"Cleveland Critical Mass rides, 8/2009 - Present. http://ccm.websubstrate.com/","filesize":31203328,"grids":["http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.grid.json","http://b.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.grid.json","http://c.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.grid.json","http://d.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.grid.json"],"id":"websubstrate.CleCritMass-data","legend":"<strong>Cleveland Critical Mass</strong><br />\\nRides and destinations, 2009-present","maxzoom":17,"minzoom":0,"name":"Cleveland Critical Mass - Data","scheme":"xyz","template":"{{#__location__}}{{/__location__}}{{#__teaser__}}<strong>{{{name}}}</strong><br />\\n<strong>Destination:</strong> {{{description}}}<br />\\n<strong>Riders:</strong> {{{field_attendees}}}<br />\\n<strong>Distance:</strong> {{{field_distance}}} mi.{{/__teaser__}}{{#__full__}}{{/__full__}}","tilejson":"2.0.0","tiles":["http://a.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.png","http://b.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.png","http://c.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.png","http://d.tiles.mapbox.com/v3/websubstrate.CleCritMass-data/{z}/{x}/{y}.png"],"version":"1.0.0","webpage":"http://tiles.mapbox.com/websubstrate/map/CleCritMass-data"}',
    'layername' => '',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'baselayer' => 1,
    'projection' => array(
      0 => '900913',
    ),
  );
  $export['clecritmass_data'] = $openlayers_layers;

  return $export;
}
