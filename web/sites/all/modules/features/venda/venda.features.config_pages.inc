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
    'field_contact_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Admin',
          'format' => NULL,
          'safe_value' => 'Admin',
        ),
      ),
    ),
    'field_contract_no' => array(
      'und' => array(
        0 => array(
          'value' => 'VD0001',
          'format' => NULL,
          'safe_value' => 'VD0001',
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
    'field_lk' => array(
      'und' => array(
        0 => array(
          'value' => '1651-1256-6234-8331',
          'format' => NULL,
          'safe_value' => '1651-1256-6234-8331',
        ),
      ),
    ),
    'field_mac_address' => array(
      'und' => array(
        0 => array(
          'value' => '285A-3C7D',
          'format' => NULL,
          'safe_value' => '285A-3C7D',
        ),
      ),
    ),
    'field_organization' => array(
      'und' => array(
        0 => array(
          'value' => 'COMSOFT',
          'format' => NULL,
          'safe_value' => 'COMSOFT',
        ),
      ),
    ),
    'field_st_last_check_no' => array(
      'und' => array(
        0 => array(
          'value' => 16,
        ),
      ),
    ),
    'type' => 'license',
  );

  return $config_pages;
}
