<?php

/**
 * @file
 * This file holds style plugin for OpenLayers Views
 *
 * @ingroup openlayers
 */

/**
 * @class
 * Extension of the Views Plugin Style for OpenLayers
 *
 * This class extended the default views plugin class to provide
 * a style plugin for the Open Layers module.
 */
class geofile_views_plugin_style_map extends views_plugin_style {

   /**
   * Render the map features.
   *
   * Overrides views_plugin_style->render
   */
  function render() {
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);
    $handlers = $this->display->handler->get_handlers('field');

    foreach ($sets as $title => $records) {
      foreach ($records as $id => $record) {
        $this->view->row_index = $id;
        if (is_object($this->view->field[$this->options['data_source']['file']])) {
          $field_array = $this->view->field[$this->options['data_source']['file']]->get_value($record);
          foreach($field_array as $key => $item) {
            $items[] = $item;
          }
        }
      }
    }

    $options = $this->options;
    $html = _geofile_openlayers_formatter($options['map_preset'], $options['layer_type'], $items, $options, $options['hybrid_mode']);

    // If we are not in preview, just return the data
    if (empty($this->view->live_preview)) {
      return $html;
    }
    else {
      $output = t('The following is a dump of the data that is rendered from this display. It is used for debugging purposes only.') . '
        ' . var_export($items, TRUE);
      return $output;
    }
  }

  /**
   * Set default options
   *
   * Overrides views_plugin_style->option_definition
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['data_source'] = array('default' => 'file');
    return $options;
  }

  /**
   * Options form
   *
   * Overrides views_plugin_style->options_form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Get list of fields in this view & flag available geodata fields
    $handlers = $this->display->handler->get_handlers('field');

    // Check for any fields, as the view needs them
    if (empty($handlers)) {
      $form['error_markup'] = array(
        '#value' => t('You need to enable at least one field before you can '
          . 'configure your field settings'),
        '#prefix' => '<div class="error form-item description">',
        '#suffix' => '</div>',
      );
      return;
    }

    $fields = array();
    foreach ($handlers as $field_id => $handler) {
      $fields[$field_id] = $handler->ui_name();
    }

    $form['data_source'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Data Source'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['data_source']['file'] = array(
      '#type' => 'select',
      '#title' => t('File field'),
      '#description' => t('Choose the file field'),
      '#options' => $fields,
      '#default_value' => $this->options['data_source']['file'],
    );

    $instance['display']['views']['type'] = 'geofile_file';
    $instance['display']['views']['settings'] = $this->options;

    $form += geofile_field_formatter_settings_form(array(), $instance, 'views', $form, $form_state);

  }

}
