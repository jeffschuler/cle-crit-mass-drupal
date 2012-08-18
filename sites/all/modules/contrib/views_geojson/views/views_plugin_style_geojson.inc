<?php

/**
 * @file
 * Views style plugin to render nodes in the GeoJSON format.
 *
 * @see views_plugin_style_geojson.inc
 */

/**
 * Implementation of views_plugin_style
 */
class views_plugin_style_geojson extends views_plugin_style {
  /*
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['data_source'] = array(
      'contains' => array(
        'value' => array('default' => 'asc'),
        'latitude' => array('default' => 0),
        'longitude' => array('default' => 0),
        'geofield' => array('default' => 0),
        'wkt' => array('default' => 0),
        'name_field' => array('default' => 0),
        'description_field' => array('default' => 0),
      ),
    );
    $options['attributes'] = array('default' => NULL, 'translatable' => FALSE);
    $options['jsonp_prefix'] = array('default' => NULL, 'translatable' => FALSE);
    $options['content_type'] = array('default' => 'default', 'translatable' => FALSE);
    $options['using_views_api_mode'] = array('default' => FALSE, 'translatable' => FALSE);
    return $options;
  }

  /**
   * Provide a form for setting options.
   *
   * @param array $form
   * @param array $form_state
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // If this is a page display, notify the user.
    // @todo At the next major release, remove support for using this display
    //       plugin with 'page' displays.
    if ($this->display->display_plugin == 'page') {
      $form['note'] = array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Using the GeoJSON display style on "Page" displays is deprecated, but will continue to work until the next release. Instead, the GeoJSON display style should be used with a "Feed" display.') . '</p>',
      );
    }

    // Get list of fields in this view & flag available geodata fields.
    $handlers = $this->display->handler->get_handlers('field');
    if (empty($handlers)) {
      $form['error_markup'] = array(
        '#value' => t('You need to enable at least one field before you can configure your field settings'),
        '#prefix' => '<div class="error form-item description">',
        '#suffix' => '</div>',
      );
      return;
    }

    // Go through fields
    $fields = array();
    foreach ($handlers as $field_id => $handler) {
      $fields[$field_id] = $handler->definition['title'];
      $fields_info[$field_id]['type'] = (!empty($handler->field_info['type']) ? $handler->field_info['type'] : NULL);
    }

    // Default data source
    $data_source_options = array(
      'latlon' => t('Other: Lat/Lon Point'),
      'geofield' => t('Geofield'),
      'wkt' => t('WKT'),
    );

    // Data Source options
    $form['data_source'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Data Source'),
//      '#collapsible' => TRUE,
//      '#collapsed' => FALSE,
    );
    $form['data_source']['value'] = array(
      '#type' => 'select',
      '#multiple' => FALSE,
      '#title' => t('Map Data Sources'),
      '#description' => t('Choose which sources of data that the map will provide features for.'),
      '#options' => $data_source_options,
      '#default_value' => $this->options['data_source']['value'],
    );
    // Other Lat and Lon data sources
    if (count($fields > 0)) {
      $form['data_source']['latitude'] = array(
        '#type' => 'select',
        '#title' => t('Latitude Field'),
        '#description' => t('Choose a field for Latitude.  This should be a field that is a decimal or float value.'),
        '#options' => $fields,
        '#default_value' => $this->options['data_source']['latitude'],
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-style-options-data-source-value' => array('latlon')),
      );
      $form['data_source']['longitude'] = array(
        '#type' => 'select',
        '#title' => t('Longitude Field'),
        '#description' => t('Choose a field for Longitude.  This should be a field that is a decimal or float value.'),
        '#options' => $fields,
        '#default_value' => $this->options['data_source']['longitude'],
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-style-options-data-source-value' => array('latlon')),
      );

      // Get Geofield-type fields
      $geofield_fields = array();
      foreach ($fields as $field_id => $field) {
        if ($fields_info[$field_id]['type'] == 'geofield') {
          $geofield_fields[$field_id] = $field;
        }
      }

      // Geofield
      $form['data_source']['geofield'] = array(
        '#type' => 'select',
        '#title' => t('Geofield'),
        '#description' => t('Choose a Geofield field. Any formatter will do; we\'ll access Geofield\'s underlying WKT format.'),
        '#options' => $geofield_fields,
        '#default_value' => $this->options['data_source']['geofield'],
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-style-options-data-source-value' => array('geofield')),
      );

      // WKT
      $form['data_source']['wkt'] = array(
        '#type' => 'select',
        '#title' => t('WKT'),
        '#description' => t('Choose a WKT format field.'),
        '#options' => $fields,
        '#default_value' => $this->options['data_source']['wkt'],
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-style-options-data-source-value' => array('wkt')),
      );
    }
    $form['data_source']['name_field'] = array(
        '#type' => 'select',
        '#title' => t('Title Field'),
        '#description' => t('Choose the field to appear as title on tooltips.'),
        '#options' => array_merge(array('' => ''), $fields),
        '#default_value' => $this->options['data_source']['name_field'],
    );

    // For node content, we can render the node using a specific view mode.
    if ($this->view->base_table == 'node') {
      $form['data_source']['description_field'] = array(
        '#type'           => 'select',
        '#title'          => t('Description'),
        '#description'    => t('Choose the field or rendering method to appear as
          description on tooltips.'),
        '#required'       => FALSE,
        '#options'        => array_merge(array(
          ''                => '',
          '#node'           => '<' . t('Entire node') . '>'
        ), $fields),
        '#default_value'  => $this->options['data_source']['description_field'],
      );

      // Available view modes. @TODO: Make this Content Type aware.
      $available_view_modes = array();
      $entity_info = entity_get_info();
      // Get the machine names of the view modes
      $view_modes_machine_names[] = array_keys($entity_info['node']['view modes']);
      // Get the labels (human readable) of the view modes
      foreach ($entity_info['node']['view modes'] as $key => $view_mode) {
        $view_modes_labels[] = $view_mode['label'];
      }
      // Combine the view mode machine name with its label.
      // @TODO: Could this be done better?
      $entities_to_display = array_combine($view_modes_machine_names[0], $view_modes_labels);
      // Output the form
      $form['data_source']['view_mode'] = array(
        '#type'          => 'select',
        '#title'         => t('View mode'),
        '#description'   => t('View modes are ways of displaying nodes.'),
        '#options'       => $entities_to_display,
        '#default_value' => !empty($this->options['data_source']['view_mode']) ?
            $this->options['data_source']['view_mode'] : 'full',
        '#states'        => array(
          'visible' => array(
            ':input[name="style_options[data_source][description_field]"]' => array('value' => '#node'),
          ),
        ),
      );
    }

    // Attributes and variable styling description
    $form['attributes'] = array(
      '#type' => 'fieldset',
      '#title' => t('Attributes and Styling'),
      '#description' => t('Attributes are field data attached to each feature.  This can be used with styling to create Variable styling.'),
//      '#collapsible' => TRUE,
//      '#collapsed' => TRUE,
    );
    $form['jsonp_prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('JSONP prefix'),
      '#default_value' => $this->options['jsonp_prefix'],
      '#description' => t('If used the JSON output will be enclosed with parentheses and prefixed by this label, as in the JSONP format.'),
    );
    $form['content_type'] = array(
      '#type'           => 'radios',
      '#title'          => t('Content-Type'),
      '#options'        => array(
        'default'       => t("Default: application/json"),
        'text/json'     => t('text/json'),
      ),
      '#default_value'  => $this->options['content_type'],
      '#description'    => t('The Content-Type header that will be sent with the JSON output.')
    );

    if ($this->display->display_plugin == 'page') {
      $form['using_views_api_mode'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Views API mode'),
        '#default_value'  => $this->options['using_views_api_mode'],
        '#description'    => t('Not using View API mode means the JSON gets output directly and the server ceases normal page processing.  Using it means the server does not cease processing after outputting the JSON.  This allows the Views API to be used with the view without having to prematurely terminate page processing.'),
      );
    }

    // Make array of attributes
    $variable_fields = array();
    // Add name and description
    if (!empty($this->options['data_source']['name_field'])) {
      $variable_fields['name'] = '${name}';
    }
    if (!empty($this->options['data_source']['description_field'])) {
      $variable_fields['description'] = '${description}';
    }
    // Go through fields
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      if (($field != $this->options['data_source']['name_field']) && ($field != $this->options['data_source']['description_field'])) {
        $variable_fields[$field] = '${' . $field . '}';
        $variable_fields[$field . '_rendered'] = '${' . $field . '_rendered}';
      }
    }
    $form['attributes']['styling'] = array(
      '#type' => 'markup',
      '#value' => '
        <p>' . t('Any fields that you add to this view will be attached to their respective feature (point, line, polygon) as attributes.  These attributes can then be used to add variable styling to your themes.  This is accomplished by using the %syntax syntax in the values for a style.  The following is a list of formatted variables that are currently available; these can be placed right in the style interface.  The %rendered one means that it has been processed by Views and may have a different value.', array('%syntax' => '${field_name}', '%rendered' => '_rendered')) . '</p>
        ' . theme('item_list', $variable_fields) . '
        <p>' . t('Please note that this does not apply to Grouped Displays.') . '</p>
      ',
    );
  }

  /**
   * Overrides view_style_plugin::render()
   */
  function render() {
    $args = func_get_args();
    $results = array_shift($args);

    $features = array(
      'type' => 'FeatureCollection',
      'features' => array(),
    );

    // Render each row.
    foreach ($results as $i => $row) {
      $this->view->row_index = $i;
      $features['features'][] = _views_geojson_render_fields($this->view, $row, $i);
    }
    unset($this->view->row_index);

    // Render the collection to JSON.
    $json = drupal_json_encode($features);
    if (!empty($this->options['jsonp_prefix'])) {
      $json = $this->options['jsonp_prefix'] . "($json)";
    }

    if (empty($this->view->preview)) {
      // Change the content type header since we're sending a JSON response.
      $content_type = ($this->options['content_type'] == 'default') ? 'application/json' : $this->options['content_type'];
      drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
    }
    elseif ($this->display->display_plugin == 'page') {
      // Pretty-print the JSON. This only works for 'page' displays.
      $json = _views_geojson_encode_formatted($features);
      if (!empty($this->options['jsonp_prefix'])) {
        $json = $this->options['jsonp_prefix'] . "($json)";
      }
      $json = "<code>$json</code>";
    }

    if ($this->display->display_plugin == 'page' && !$this->options['using_views_api_mode']) {
      // Page display prints and exits; this is BAD (prevents caching) but
      // supports legacy configurations.
      print $json;
      exit;
    }
    else {
      // Everything else returns output.
      return $json;
    }
  }

}