<?php
/**
 * @file
 * dccr_ftr_2015.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dccr_ftr_2015_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dccr_ftr_2015_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_context_default_contexts_alter().
 */
function dccr_ftr_2015_context_default_contexts_alter(&$data) {
  if (isset($data['sitewide'])) {
    $data['sitewide']->reactions['block']['blocks']['block-1'] = array(
      'module' => 'block',
      'delta' => 1,
      'region' => 'footer',
      'weight' => -10,
    ); /* WAS: '' */
    $data['sitewide']->reactions['block']['blocks']['block-4'] = array(
      'module' => 'block',
      'delta' => 4,
      'region' => 'header',
      'weight' => -22,
    ); /* WAS: '' */
    $data['sitewide']->reactions['block']['blocks']['dccr_blocks-dccr_main_logo']['region'] = 'utility_bar'; /* WAS: 'featured' */
    $data['sitewide']->reactions['block']['blocks']['dccr_blocks-dccr_main_logo']['weight'] = -10; /* WAS: -7 */
    $data['sitewide']->reactions['block']['blocks']['menu-menu-left-menu']['region'] = 'header'; /* WAS: 'featured' */
    $data['sitewide']->reactions['block']['blocks']['menu-menu-left-menu']['weight'] = -23; /* WAS: -8 */
    $data['sitewide']->reactions['block']['blocks']['menu-menu-right-menu']['region'] = 'header'; /* WAS: 'featured' */
    $data['sitewide']->reactions['block']['blocks']['menu-menu-right-menu']['weight'] = -21; /* WAS: -6 */
    unset($data['sitewide']->reactions['block']['blocks']['dccr_blocks-dccr_login_link']);
    unset($data['sitewide']->reactions['block']['blocks']['views-sponsors-block_2']);
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function dccr_ftr_2015_strongarm_alter(&$data) {
  if (isset($data['site_frontpage'])) {
    $data['site_frontpage']->value = 'node/1'; /* WAS: 'home' */
  }
}
