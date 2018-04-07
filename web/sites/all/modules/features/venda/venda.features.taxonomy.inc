<?php
/**
 * @file
 * venda.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function venda_taxonomy_default_vocabularies() {
  return array(
    'countries' => array(
      'name' => 'Страны',
      'machine_name' => 'countries',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'expense_type' => array(
      'name' => 'Тип расхода',
      'machine_name' => 'expense_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'manufacturers' => array(
      'name' => 'Производители',
      'machine_name' => 'manufacturers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'payment_type' => array(
      'name' => 'Тип оплаты',
      'machine_name' => 'payment_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
