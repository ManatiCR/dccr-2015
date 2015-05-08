<?php
/**
 * @file
 * dccr_ftr_landing_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dccr_ftr_landing_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dccr_ftr_landing_pages_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function dccr_ftr_landing_pages_paragraphs_info() {
  $items = array(
    'embed_paragraph' => array(
      'name' => 'Embed',
      'bundle' => 'embed_paragraph',
      'locked' => '1',
    ),
    'image_paragraph' => array(
      'name' => 'Image',
      'bundle' => 'image_paragraph',
      'locked' => '1',
    ),
    'image_with_caption' => array(
      'name' => 'Image with Caption',
      'bundle' => 'image_with_caption',
      'locked' => '1',
    ),
    'simple_paragraph' => array(
      'name' => 'Simple Paragraph',
      'bundle' => 'simple_paragraph',
      'locked' => '1',
    ),
  );
  return $items;
}
