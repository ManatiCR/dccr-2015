<?php
/**
 * @file
 * dccr_ftr_2015.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dccr_ftr_2015_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = '';
  $context->tag = 'Inicio';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'above_content',
          'weight' => '-10',
        ),
        'views-conferencistas-block' => array(
          'module' => 'views',
          'delta' => 'conferencistas-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-comunidad-block' => array(
          'module' => 'views',
          'delta' => 'comunidad-block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-sponsors-block_1' => array(
          'module' => 'views',
          'delta' => 'sponsors-block_1',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Inicio');
  $export['homepage'] = $context;

  return $export;
}
