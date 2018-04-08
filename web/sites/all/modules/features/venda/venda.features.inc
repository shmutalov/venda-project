<?php
/**
 * @file
 * venda.features.inc
 */

/**
 * Implements hook_default_config_pages_type().
 */
function venda_default_config_pages_type() {
  $items = array();
  $items['license'] = entity_import('config_pages_type', '{
    "type" : "license",
    "label" : "\\u041d\\u0430\\u0441\\u0442\\u0440\\u043e\\u0439\\u043a\\u0438 \\u0441\\u0430\\u0439\\u0442\\u0430",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "dashboard\\/settings", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    }
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function venda_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function venda_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function venda_image_default_styles() {
  $styles = array();

  // Exported image style: square_thumbnail.
  $styles['square_thumbnail'] = array(
    'label' => 'square_thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'weight' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function venda_node_info() {
  $items = array(
    'branch' => array(
      'name' => t('Филиал'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'client' => array(
      'name' => t('Клиент'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Имя клиента'),
      'help' => '',
    ),
    'contract' => array(
      'name' => t('Договор'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Договор №'),
      'help' => '',
    ),
    'encashment' => array(
      'name' => t('Расход'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'missing_product' => array(
      'name' => t('Отказной товар'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Страница'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Продукт'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'product_batch' => array(
      'name' => t('Партия'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
    'provider' => array(
      'name' => t('Поставщик'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название поставщика'),
      'help' => '',
    ),
    'revoked_product' => array(
      'name' => t('Списанный товар'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'transaction' => array(
      'name' => t('Транзакция'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
    'transaction_product' => array(
      'name' => t('Продукт транзакции'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
    'waybill' => array(
      'name' => t('Накладная'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Накладная №'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function venda_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "\\u0418\\u043d\\u0444\\u043e\\u0440\\u043c\\u0430\\u0446\\u0438\\u044f \\u043e \\u043c\\u0430\\u0433\\u0430\\u0437\\u0438\\u043d\\u0435",
    "weight" : "0",
    "data" : { "registration" : 0, "use_one_page" : 1 }
  }');
  return $items;
}
