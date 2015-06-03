<?php
/**
 * @file
 * dccr_ftr_2015.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dccr_ftr_2015_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_dccr2015_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 0,
    'toggle_secondary_menu' => 0,
    'default_logo' => 0,
    'logo_path' => 'sites/all/themes/dccr2015/images/main-logo.png',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => 'sites/all/themes/dccr2015/images/favico.gif',
    'favicon_upload' => '',
    'html5shim' => 0,
    'respond_js' => 0,
    'normalize_css' => 0,
    'magic_css_excludes' => '',
    'magic_footer_js' => 0,
    'magic_library_head' => 0,
    'magic_experimental_js' => 0,
    'magic_js_excludes' => '',
    'favicon_mimetype' => 'image/gif',
  );
  $export['theme_dccr2015_settings'] = $strongarm;

  return $export;
}
