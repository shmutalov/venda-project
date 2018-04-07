<?php
/**
 * @file
 * venda.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function venda_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => 2,
  );

  // Exported role: seller.
  $roles['seller'] = array(
    'name' => 'seller',
    'weight' => 3,
  );

  // Exported role: warehouse manager.
  $roles['warehouse manager'] = array(
    'name' => 'warehouse manager',
    'weight' => 5,
  );

  return $roles;
}
