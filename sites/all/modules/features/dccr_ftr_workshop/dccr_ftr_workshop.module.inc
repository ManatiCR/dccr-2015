<?php
/**
 * @file
 * Extra-functionality to workshop feature.
 */

/**
 * Implements hook_field_extra_fields().
 */
function dccr_ftr_workshop_field_extra_fields() {
  $extra['node']['workshop']['display']['extra_field_workshop_register'] = array(
    'label' => t('Workshop Register'),
    'description' => t('Provides a Flag link'),
    'weight' => 0,
  );
  $extra['node']['workshop']['display']['extra_field_workshop_attendants'] = array(
    'label' => t('Workshop Attendants'),
    'description' => t('Provides a linki to workshop attendants'),
    'weight' => 0,
  );
  return $extra;
}

/**
 * Implements hook_node_view().
 */
function dccr_ftr_workshop_node_view($node, $view_mode, $langcode) {
  if ($node->type == 'workshop') {
    $node->content['extra_field_workshop_register'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => dccr_ftr_workshop_register_link($node),
    );
    $node->content['extra_field_workshop_attendants'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => dccr_ftr_workshop_attendants_link($node),
    );
  }
}

/**
 * Returns workshop register flag link only if it should be printed.
 */
function dccr_ftr_workshop_register_link($node) {
  global $user;
  $wrapper = entity_metadata_wrapper('node', $node);
  $flag_registered = flag_get_flag('dccr_registration_complete');
  if ($flag_registered->is_flagged($user->uid)) {
    if ($wrapper->field_availability->value() > 0) {
      return flag_create_link('workshop_registration', $wrapper->getIdentifier());
    }
    else {
      $flag_workshop = flag_get_flag('workshop_registration');
      $markup = '<div>' . t('This workshop is full') . '</div>';
      if ($flag_workshop && $flag_workshop->is_flagged($wrapper->getIdentifier(), $user->uid)) {
        $markup .= flag_create_link('workshop_registration', $wrapper->getIdentifier());
      }
      return $markup;
    }
  }
}

/**
 * Returns a link for attendants view if user has drupal_administrator role.
 */
function dccr_ftr_workshop_attendants_link($node) {
  $markup = '';
  $role = user_role_load_by_name('drupal_administrator');
  if (user_has_role($role->rid)) {
    $markup = '<div class="attendants-link">' . l(t('View attendants'), 'workshops-attendants/' . $node->nid) . '</div>';
  }
  return $markup;
}

/**
 * Implements hook_flag_flag().
 */
function dccr_ftr_workshop_flag_flag($flag, $content_id, $account, $flagging) {
  if ($flag->name == 'workshop_registration') {
    dccr_ftr_workshop_countdown('flag', $content_id);
  }
}

/**
 * Implements hook_flag_unflag().
 */
function dccr_ftr_workshop_flag_unflag($flag, $content_id, $account, $flagging) {
  if ($flag->name == 'workshop_registration') {
    dccr_ftr_workshop_countdown('unflag', $content_id);
  }
}

/**
 * Implements hook_preprocess_node().
 */
function dccr_ftr_workshop_preprocess_node(&$variables) {
  if ($variables['type'] == 'workshop' && $variables['view_mode'] == 'teaser') {
    $variables['content']['field_speaker'][0]['#suffix'] = ' /&nbsp';
    $variables['content']['field_availability'][0]['#suffix'] = ' ' . t('spaces left.');
    $variables['content']['title'][0]['#markup'] = '<h2>' . l(check_plain($variables['title']), 'node/' . $variables['nid']) . '</h2>';
  }
}

/**
 * Implements hook_date_limit_format_alter().
 */
function dccr_ftr_workshop_date_limit_format_alter(&$format, $granularity) {
  if ($format == '\d\e \d\e\l \a \l\a\s g a') {
    $format = 'g a';
  }
  elseif ($format == '\a\t G:i') {
    $format = 'G:i';
  }
}

/**
 * Update availability field for a workshop when flagged/unflagged.
 */
function dccr_ftr_workshop_countdown($action, $content_id) {
  $wrapper = entity_metadata_wrapper('node', $content_id);
  if ($wrapper->source->value()) {
    $translations = translation_node_get_translations($wrapper->source->value()->tnid);
    foreach ($translations as $node) {
      if ($wrapper->source->value()->tnid != $node->nid) {
        $t_wrapper = entity_metadata_wrapper('node', $node->nid);
        $t_availability = $t_wrapper->field_availability->value();
        if ($action == 'flag') {
          $t_availability--;
        }
        elseif ($action == 'unflag') {
          $t_availability++;
        }
        $t_wrapper->field_availability->set($t_availability);
        $t_wrapper->save();
        break;
      }
    }
  }
  $actual_availability = $wrapper->field_availability->value();
  if ($action == 'flag') {
    $actual_availability--;
  }
  elseif ($action == 'unflag') {
    $actual_availability++;
  }
  $wrapper->field_availability->set($actual_availability);
  $wrapper->save();
}

/**
 * Implements hook_cron().
 */
function dccr_ftr_workshop_cron() {
  $week_before = strtotime('-7 day', DCCR_CAMP_START_DATE);
  $three_days_before = strtotime('-3 day', DCCR_CAMP_START_DATE);
  if ($week_before <= REQUEST_TIME && !variable_get('reminder_week_before', FALSE)) {
    variable_set('reminder_week_before', TRUE);
    dccr_ftr_workshop_invoke_reminder('7');
  }
  elseif ($three_days_before <= REQUEST_TIME && !variable_get('reminder_three_days_before', FALSE)) {
    variable_set('reminder_three_days_before', TRUE);
    dccr_ftr_workshop_invoke_reminder('3');
  }
}

/**
 * Invoke the rule event dccr_ftr_workshop_nofications.
 */
function dccr_ftr_workshop_invoke_reminder($days) {
  $result = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'workshop', '=')
    ->condition('status', 1, '=')
    ->execute();
  $workshops_nids = $result->fetchCol();
  $workshops = node_load_multiple($workshops_nids);

  foreach ($workshops_nids as $nid) {
    $users_uids = dccr_ftr_workshop_get_workshop_flaggers($nid);
    $users = user_load_multiple($users_uids);
    foreach ($users_uids as $uid) {
      rules_invoke_event('dccr_ftr_workshop_nofications', $workshops[$nid], $users[$uid], $days);
    }
  }
}

/**
 * Get the user who flagged a node.
 */
function dccr_ftr_workshop_get_workshop_flaggers($nid) {
  $result = db_select('flagging', 'f')
    ->fields('f', array('uid'))
    ->condition('entity_type', 'node', '=')
    ->condition('entity_id', $nid, '=')
    ->execute();
  return $result->fetchCol();
}

/**
 * Implements hook_rules_event_info().
 */
function dccr_ftr_workshop_rules_event_info() {
  return array(
    'dccr_ftr_workshop_nofications' => array(
      'label' => t('Time to execute Workshop email reminder'),
      'module' => 'dccr_ftr_workshop',
      'variables' => array(
        'workshop_node' => array(
          'type' => 'node',
          'label' => t('The Workshop node'),
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('User to remind'),
        ),
        'days' => array(
          'type' => 'text',
          'label' => t('Days to the camp'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_date_formats().
 */
function dccr_ftr_workshop_date_formats() {
  return array(
    array(
      'type' => 'workshop_reminder',
      'format' => 'l, F dS, Y \a\t G:i',
      'locales' => array('en', 'en-us'),
    ),
    array(
      'type' => 'workshop_reminder',
      'format' => 'd \d\e F \d\e\l Y \a \l\a\s g:s a',
      'locales' => array('es'),
    ),
  );
}

/**
 * Implements hook_date_format_types().
 */
function dccr_ftr_workshop_date_format_types() {
  return array(
    'workshop_reminder' => t('Workshop Notification'),
  );
}

/**
 * Returns form for unregister user from workshop.
 */
function dccr_ftr_workshop_unregister_form($form, $form_state, $nid, $user) {
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $nid,
  );
  $form['user'] = array(
    '#type' => 'value',
    '#value' => $user,
  );
  $form['unregister'] = array(
    '#type' => 'submit',
    '#value' => t('Unregister'),
    '#submit' => array('dccr_ftr_workshop_unregister_form_submit'),
  );

  return $form;
}

/**
 * Submit handler for dccr_ftr_workshop_unregister_form.
 */
function dccr_ftr_workshop_unregister_form_submit($form, $form_state) {
  $values = $form_state['values'];
  $nid = $values['nid'];
  $user = $values['user'];
  $flag_name = 'workshop_registration';
  flag('unflag', $flag_name, $nid, $user, TRUE);
}
