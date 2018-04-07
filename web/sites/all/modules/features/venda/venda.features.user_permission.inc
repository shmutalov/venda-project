<?php
/**
 * @file
 * venda.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function venda_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_field_trc_refund_reason'.
  $permissions['create field_field_trc_refund_reason'] = array(
    'name' => 'create field_field_trc_refund_reason',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_parent_manager'.
  $permissions['create field_parent_manager'] = array(
    'name' => 'create field_parent_manager',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_trc_check_no'.
  $permissions['create field_trc_check_no'] = array(
    'name' => 'create field_trc_check_no',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'manager' => 'manager',
      'seller' => 'seller',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_trc_price_base'.
  $permissions['create field_trc_price_base'] = array(
    'name' => 'create field_trc_price_base',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_trc_product'.
  $permissions['create field_trc_product'] = array(
    'name' => 'create field_trc_product',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_trc_refund_amount'.
  $permissions['create field_trc_refund_amount'] = array(
    'name' => 'create field_trc_refund_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_trc_server_node_id'.
  $permissions['create field_trc_server_node_id'] = array(
    'name' => 'create field_trc_server_node_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_trc_type'.
  $permissions['create field_trc_type'] = array(
    'name' => 'create field_trc_type',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_trc_uploaded_server'.
  $permissions['create field_trc_uploaded_server'] = array(
    'name' => 'create field_trc_uploaded_server',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_field_trc_refund_reason'.
  $permissions['edit field_field_trc_refund_reason'] = array(
    'name' => 'edit field_field_trc_refund_reason',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_parent_manager'.
  $permissions['edit field_parent_manager'] = array(
    'name' => 'edit field_parent_manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trc_check_no'.
  $permissions['edit field_trc_check_no'] = array(
    'name' => 'edit field_trc_check_no',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trc_price_base'.
  $permissions['edit field_trc_price_base'] = array(
    'name' => 'edit field_trc_price_base',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trc_product'.
  $permissions['edit field_trc_product'] = array(
    'name' => 'edit field_trc_product',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trc_refund_amount'.
  $permissions['edit field_trc_refund_amount'] = array(
    'name' => 'edit field_trc_refund_amount',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trc_server_node_id'.
  $permissions['edit field_trc_server_node_id'] = array(
    'name' => 'edit field_trc_server_node_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trc_type'.
  $permissions['edit field_trc_type'] = array(
    'name' => 'edit field_trc_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trc_uploaded_server'.
  $permissions['edit field_trc_uploaded_server'] = array(
    'name' => 'edit field_trc_uploaded_server',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_field_trc_refund_reason'.
  $permissions['edit own field_field_trc_refund_reason'] = array(
    'name' => 'edit own field_field_trc_refund_reason',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_parent_manager'.
  $permissions['edit own field_parent_manager'] = array(
    'name' => 'edit own field_parent_manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trc_check_no'.
  $permissions['edit own field_trc_check_no'] = array(
    'name' => 'edit own field_trc_check_no',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trc_price_base'.
  $permissions['edit own field_trc_price_base'] = array(
    'name' => 'edit own field_trc_price_base',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trc_product'.
  $permissions['edit own field_trc_product'] = array(
    'name' => 'edit own field_trc_product',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trc_refund_amount'.
  $permissions['edit own field_trc_refund_amount'] = array(
    'name' => 'edit own field_trc_refund_amount',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trc_server_node_id'.
  $permissions['edit own field_trc_server_node_id'] = array(
    'name' => 'edit own field_trc_server_node_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trc_type'.
  $permissions['edit own field_trc_type'] = array(
    'name' => 'edit own field_trc_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trc_uploaded_server'.
  $permissions['edit own field_trc_uploaded_server'] = array(
    'name' => 'edit own field_trc_uploaded_server',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_field_trc_refund_reason'.
  $permissions['view field_field_trc_refund_reason'] = array(
    'name' => 'view field_field_trc_refund_reason',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_parent_manager'.
  $permissions['view field_parent_manager'] = array(
    'name' => 'view field_parent_manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trc_check_no'.
  $permissions['view field_trc_check_no'] = array(
    'name' => 'view field_trc_check_no',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trc_price_base'.
  $permissions['view field_trc_price_base'] = array(
    'name' => 'view field_trc_price_base',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trc_product'.
  $permissions['view field_trc_product'] = array(
    'name' => 'view field_trc_product',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trc_refund_amount'.
  $permissions['view field_trc_refund_amount'] = array(
    'name' => 'view field_trc_refund_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trc_server_node_id'.
  $permissions['view field_trc_server_node_id'] = array(
    'name' => 'view field_trc_server_node_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trc_type'.
  $permissions['view field_trc_type'] = array(
    'name' => 'view field_trc_type',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trc_uploaded_server'.
  $permissions['view field_trc_uploaded_server'] = array(
    'name' => 'view field_trc_uploaded_server',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_field_trc_refund_reason'.
  $permissions['view own field_field_trc_refund_reason'] = array(
    'name' => 'view own field_field_trc_refund_reason',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_parent_manager'.
  $permissions['view own field_parent_manager'] = array(
    'name' => 'view own field_parent_manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trc_check_no'.
  $permissions['view own field_trc_check_no'] = array(
    'name' => 'view own field_trc_check_no',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trc_price_base'.
  $permissions['view own field_trc_price_base'] = array(
    'name' => 'view own field_trc_price_base',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trc_product'.
  $permissions['view own field_trc_product'] = array(
    'name' => 'view own field_trc_product',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trc_refund_amount'.
  $permissions['view own field_trc_refund_amount'] = array(
    'name' => 'view own field_trc_refund_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trc_server_node_id'.
  $permissions['view own field_trc_server_node_id'] = array(
    'name' => 'view own field_trc_server_node_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trc_type'.
  $permissions['view own field_trc_type'] = array(
    'name' => 'view own field_trc_type',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trc_uploaded_server'.
  $permissions['view own field_trc_uploaded_server'] = array(
    'name' => 'view own field_trc_uploaded_server',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
