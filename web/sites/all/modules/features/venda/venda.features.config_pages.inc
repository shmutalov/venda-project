<?php
/**
 * @file
 * venda.features.config_pages.inc
 */

/**
 * Implements hook_config_pages_default_data().
 */
function venda_config_pages_default_data() {
  $config_pages = array();

  // Exported format: license-.
  $config_pages['license-'] = array(
    'context' => '',
    'data' => '',
    'field_apteka_id' => array(
      'und' => array(
        0 => array(
          'value' => 'chorsu',
          'format' => NULL,
          'safe_value' => 'chorsu',
        ),
      ),
    ),
    'field_exchange_rate' => array(
      'und' => array(
        0 => array(
          'value' => 8100,
        ),
      ),
    ),
    'field_st_last_check_no' => array(
      'und' => array(
        0 => array(
          'value' => 2446,
        ),
      ),
    ),
    'type' => 'license',
  );

  return $config_pages;
}
