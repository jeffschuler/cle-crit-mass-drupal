<?php

/**
 * Implements hook_features_export_options().
 */
function custom_pagers_features_export_options() {
  $result = db_select('custom_pager', 'cp')->fields('cp', array('pid', 'title'))->execute();
  $options = array();
  foreach ($result as $row) {
    $options[$row->pid] = $row->title;
  }
  return $options;
}

/**
 * Implements hook_features_export().
 */
function custom_pagers_features_export($data, &$export, $module_name) {
  $export['dependencies']['custom_pagers'] = 'custom_pagers';
  foreach ($data as $component) {
    $export['features']['custom_pagers'][$component] = $component;
  }
  return array();
}

/**
 * Implements hook_features_export_render().
 */
function custom_pagers_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '  $custom_pagers = array();';
  $code[] = '';
  foreach ($data as $sys_name) {
    $item = _custom_pagers_get_data($sys_name);
    $code[] = '  $custom_pagers[] = '. features_var_export($item, '  ') .';';
  }
  $code[] = '  return $custom_pagers;';
  $code = implode("\n", $code);
  return array('default_custom_pagers' => $code);
}

/**
 * Implements hook_features_rebuild().
 */
function custom_pagers_features_rebuild($module) {
  $items = module_invoke($module, 'default_custom_pagers');
  foreach ($items as $item) {
    $saved = _custom_pagers_set_data($item);
  }
}

/**
 * Implements hook_features_revert().
 */
function custom_pagers_features_revert($module) {
  custom_pagers_features_rebuild($module);
}

/**
 * Getter for Custom Pagers feature data.
 */
function _custom_pagers_get_data($pid) {
  $data = array();
  $result = db_select('custom_pager', 'cp')
    ->fields('cp', array('pid', 'title', 'list_php', 'view', 'args', 'position', 'visibility_php', 'node_type', 'reverse_list'))
    ->condition('pid', $pid)
    ->execute();
  foreach ($result as $row) {
    $data['pid'] = $row->pid;
    $data['title'] = $row->title;
    $data['list_php'] = $row->list_php;
    $data['view'] = $row->view;
    $data['args'] = $row->args;
    $data['position'] = $row->position;
    $data['visibility_php'] = $row->visibility_php;
    $data['node_type'] = $row->node_type;
    $data['reverse_list'] = $row->reverse_list;
  }
  return $data;
}

/**
 * Setter for Custom Pagers feature data.
 */
function _custom_pagers_set_data($items) {
  db_delete('custom_pager')
    ->condition('pid', $items['pid'])
    ->execute();

  db_insert('custom_pager')
    ->fields(array('pid'=>$items['pid'],
      'title'=>$items['title'],
      'list_php'=>$items['list_php'],
      'view'=>$items['view'],
      'args'=>$items['args'],
      'position'=>$items['position'],
      'visibility_php'=>$items['visibility_php'],
      'node_type'=>$items['node_type'],
      'reverse_list'=>$items['reverse_list'],
    ))
    ->execute();
  return true;
}