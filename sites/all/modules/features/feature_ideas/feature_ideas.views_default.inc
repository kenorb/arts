<?php

/**
 * Implementation of hook_views_default_views().
 */
function feature_ideas_views_default_views() {
  $views = array();

  // Exported view: Ideas
  $view = new view;
  $view->name = 'Ideas';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'ideas';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Ideas';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'sort' => array(
      'bef_format' => 'default',
      'combine' => 0,
      'reset' => 0,
      'reset_label' => '',
    ),
    'pager' => array(
      'bef_format' => 'default',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => '',
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'body' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => '',
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20,50,100,200,500';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 1;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'vud_node_widget' => 'vud_node_widget',
    'title' => 'title',
    'teaser' => 'teaser',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'vud_node_widget' => array(
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'teaser' => array(
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['empty'] = FALSE;
  $handler->display->display_options['header']['area_1']['content'] = ' <a href=\'/node/add/idea\' class=\'share\'>Share your idea</a>';
  /* Relationship: Node: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['required'] = 0;
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => 'average',
  );
  /* Relationship: User: Nodes authored */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'users';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Vote Up/Down: Node Widget */
  $handler->display->display_options['fields']['vud_node_widget']['id'] = 'vud_node_widget';
  $handler->display->display_options['fields']['vud_node_widget']['table'] = 'node';
  $handler->display->display_options['fields']['vud_node_widget']['field'] = 'vud_node_widget';
  $handler->display->display_options['fields']['vud_node_widget']['label'] = 'Vote';
  $handler->display->display_options['fields']['vud_node_widget']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['vud_node_widget']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vud_node_widget']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vud_node_widget']['empty_zero'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Idea';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Node: Teaser */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['teaser']['field'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['label'] = '';
  $handler->display->display_options['fields']['teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['external'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['teaser']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['teaser']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['teaser']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitted by';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['value']['expose']['label'] = 'Most popular';
  /* Sort criterion: Node: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Most recent';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'idea' => 'idea',
  );
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Idea */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['ui_name'] = 'Idea';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Idea';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['title']['case'] = 0;
  /* Filter: Node: Body */
  $handler->display->display_options['filters']['body']['id'] = 'body';
  $handler->display->display_options['filters']['body']['table'] = 'node_revisions';
  $handler->display->display_options['filters']['body']['field'] = 'body';
  $handler->display->display_options['filters']['body']['operator'] = 'contains';
  $handler->display->display_options['filters']['body']['exposed'] = TRUE;
  $handler->display->display_options['filters']['body']['expose']['operator'] = 'body_op';
  $handler->display->display_options['filters']['body']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['body']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['body']['expose']['identifier'] = 'body';
  $handler->display->display_options['filters']['body']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['body']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['body']['case'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ideas';
  $handler->display->display_options['path'] = 'ideas/list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ideas';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['Ideas'] = array(
    t('Defaults'),
    t('Ideas'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Text area'),
    t(' <a href=\'/node/add/idea\' class=\'share\'>Share your idea</a>'),
    t('Vote results'),
    t('nodes'),
    t('Vote'),
    t('Idea'),
    t('Submitted by'),
    t('Most popular'),
    t('Most recent'),
    t('Description'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
