<?php
/**
 * @file
 * dccr_ftr_2015.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function dccr_ftr_2015_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: context
  $overrides["context.sitewide.reactions|block|blocks|block-1"] = array(
    'module' => 'block',
    'delta' => 1,
    'region' => 'footer',
    'weight' => -10,
  );
  $overrides["context.sitewide.reactions|block|blocks|block-4"] = array(
    'module' => 'block',
    'delta' => 4,
    'region' => 'header',
    'weight' => -22,
  );
  $overrides["context.sitewide.reactions|block|blocks|dccr_blocks-dccr_login_link"]["DELETED"] = TRUE;
  $overrides["context.sitewide.reactions|block|blocks|dccr_blocks-dccr_main_logo|region"] = 'utility_bar';
  $overrides["context.sitewide.reactions|block|blocks|dccr_blocks-dccr_main_logo|weight"] = -10;
  $overrides["context.sitewide.reactions|block|blocks|menu-menu-left-menu|region"] = 'header';
  $overrides["context.sitewide.reactions|block|blocks|menu-menu-left-menu|weight"] = -23;
  $overrides["context.sitewide.reactions|block|blocks|menu-menu-right-menu|region"] = 'header';
  $overrides["context.sitewide.reactions|block|blocks|menu-menu-right-menu|weight"] = -21;
  $overrides["context.sitewide.reactions|block|blocks|views-sponsors-block_2"]["DELETED"] = TRUE;

  // Exported overrides for: variable
  $overrides["variable.site_frontpage.value"] = 'node/1';

 return $overrides;
}
