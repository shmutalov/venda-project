<?php
/**
 * @file
 * venda.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function venda_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-manager-menu.
  $menus['menu-manager-menu'] = array(
    'menu_name' => 'menu-manager-menu',
    'title' => 'Manager menu',
    'description' => '',
  );
  // Exported menu: menu-report-menu.
  $menus['menu-report-menu'] = array(
    'menu_name' => 'menu-report-menu',
    'title' => 'Report menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Manager menu');
  t('Report menu');

  return $menus;
}
