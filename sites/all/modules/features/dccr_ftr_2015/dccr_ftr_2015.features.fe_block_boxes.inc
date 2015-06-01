<?php
/**
 * @file
 * dccr_ftr_2015.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function dccr_ftr_2015_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'contacto';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'contacto_footer';
  $fe_block_boxes->body = '<p>Si tienes dudas contacta a los organizadores</p>
<p>---</p>
<p><a href="mailto:info@drupalcostarica.com">info@drupalcostarica.com</a></p>
<p> <a href="tel:+506-2234-6622">+506 2234-6622</a></p>';

  $export['contacto_footer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'encabezado de inicio';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'encabezado_de_inicio';
  $fe_block_boxes->body = '<header><h1>El evento web más grande del país</h1><p>Se habla de Drupal, front-end, Back-end, negocios, proyectos y más.</p></header><div class="content-wrapper">
<div class="content-inner">
<div class="left">
<p class="fechas">29 de Julio, <strong>talleres</strong> (Cupo Limitado)</p>
<p class="centra-boton"><a class="boton-basico">ver talleres</a><p/>
</div>
<div class="right">
<p class="fechas">30 y 31 de Julio, <strong>conferencias</strong></p>
<p class="centra-boton"><a class="boton-basico">ver agenda</a><p/>
</div>
</div>
<p class="boton-wrapper"><a class="boton-negro" href="#">Registrarme en el evento</a></p>
</div>';

  $export['encabezado_de_inicio'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'logo leyenda';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'logo_leyenda';
  $fe_block_boxes->body = '<p>29 al 31 de julio </ br>Sede Patrocinadores Universidad de Costa Rica</p>';

  $export['logo_leyenda'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'UCR map';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'mapa_ucr';
  $fe_block_boxes->body = '<iframe width="1200" height="400" frameborder="0" style="border:0"
src="https://www.google.com/maps/embed/v1/place?q=Ciudad%20de%20la%20Investigacion%2C%20Sabanilla%2C%20San%20Jose%2C%20Costa%20Rica&key=AIzaSyC1WtX40GST0Nc7JxiweLxNCv62aeUOrsE"></iframe> ';

  $export['mapa_ucr'] = $fe_block_boxes;

  return $export;
}
