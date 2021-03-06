<?php

/**
 * @file
 * All users who have signed up for a given node.
 */

$view = new view;
$view->name = 'signup_user_list';
$view->description = 'List of all users signed up for a given node';
$view->tag = 'Signup';
$view->view_php = '';
$view->base_table = 'signup_log';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE;
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'uid' => array(
    'label' => 'Signup user',
    'required' => 1,
    'id' => 'uid',
    'table' => 'signup_log',
    'field' => 'uid',
    'relationship' => 'none',
  ),
  'nid' => array(
    'label' => 'Signup node',
    'required' => 1,
    'id' => 'nid',
    'table' => 'signup_log',
    'field' => 'nid',
    'relationship' => 'none',
  ),
));
$handler->override_option('fields', array(
  'name' => array(
    'label' => 'Username',
    'link_to_user' => 1,
    'exclude' => 0,
    'id' => 'name',
    'table' => 'users',
    'field' => 'name',
    'relationship' => 'uid',
  ),
  'signup_time' => array(
    'label' => 'Signup time',
    'date_format' => 'small',
    'custom_date_format' => '',
    'exclude' => 0,
    'id' => 'signup_time',
    'table' => 'signup_log',
    'field' => 'signup_time',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'nid' => array(
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'signup_status',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'nid',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_signup_status' => 'any',
    'validate_argument_signup_node_access' => 1,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('access', array(
  'type' => 'perm',
  'perm' => 'view all signups',
));
$handler->override_option('items_per_page', 100);
$handler->override_option('use_pager', 1);
$handler->override_option('style_plugin', 'table');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 0,
  'order' => 'asc',
  'columns' => array(
    'name' => 'name',
    'signup_time' => 'signup_time',
  ),
  'info' => array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'signup_time' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  ),
  'default' => 'signup_time',
));
