<?php

/**
 * Implementation of hook_node_info().
 */
function feature_ideas_node_info() {
  $items = array(
    'idea' => array(
      'name' => t('Idea'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Describe your idea'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function feature_ideas_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}