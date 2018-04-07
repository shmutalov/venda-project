<?php
/**
 * @file
 * venda.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function venda_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_currency_settings|config_pages|license|form';
  $field_group->group_name = 'group_currency_settings';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'license';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Валютные настройки',
    'weight' => '0',
    'children' => array(
      0 => 'field_exchange_rate',
      1 => 'field_currency_warehouse',
      2 => 'field_currency_pos',
      3 => 'field_rate_show',
      4 => 'field_rate_round',
      5 => 'field_rate_round_side',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Валютные настройки',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-currency-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_currency_settings|config_pages|license|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_licence_settings|config_pages|license|form';
  $field_group->group_name = 'group_licence_settings';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'license';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Лицензия',
    'weight' => '3',
    'children' => array(
      0 => 'field_organization',
      1 => 'field_contact_name',
      2 => 'field_mac_address',
      3 => 'field_lk',
      4 => 'field_contract_no',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Лицензия',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-st-license',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_licence_settings|config_pages|license|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_st_printer|config_pages|license|form';
  $field_group->group_name = 'group_st_printer';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'license';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Настройки интерфейса',
    'weight' => '1',
    'children' => array(
      0 => 'field_st_last_check_no',
      1 => 'field_st_app_type',
      2 => 'field_apteka_id',
      3 => 'field_highlight_expired',
      4 => 'field_field_highlight_warning',
      5 => 'field_highlight_time',
      6 => 'field_kass_auto_update',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Настройки интерфейса',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-st-printer field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_st_printer|config_pages|license|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Валютные настройки');
  t('Лицензия');
  t('Настройки интерфейса');

  return $field_groups;
}
