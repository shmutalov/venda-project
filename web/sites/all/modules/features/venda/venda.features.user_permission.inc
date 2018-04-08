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

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access example charts'.
  $permissions['access example charts'] = array(
    'name' => 'access example charts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'charts',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer charts'.
  $permissions['administer charts'] = array(
    'name' => 'administer charts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'charts',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer config_pages types'.
  $permissions['administer config_pages types'] = array(
    'name' => 'administer config_pages types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_pages',
  );

  // Exported permission: 'administer config_pagess'.
  $permissions['administer config_pagess'] = array(
    'name' => 'administer config_pagess',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'config_pages',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer module missing message fixer'.
  $permissions['administer module missing message fixer'] = array(
    'name' => 'administer module missing message fixer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_missing_message_fixer',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nicemessages'.
  $permissions['administer nicemessages'] = array(
    'name' => 'administer nicemessages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nicemessages',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer override node options'.
  $permissions['administer override node options'] = array(
    'name' => 'administer override node options',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer profiles'.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer track field changes'.
  $permissions['administer track field changes'] = array(
    'name' => 'administer track field changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'track_field_changes',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change other user\'s password'.
  $permissions['change other user\'s password'] = array(
    'name' => 'change other user\'s password',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'useraccount_permissions',
  );

  // Exported permission: 'change own password'.
  $permissions['change own password'] = array(
    'name' => 'change own password',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'useraccount_permissions',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create branch content'.
  $permissions['create branch content'] = array(
    'name' => 'create branch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create client content'.
  $permissions['create client content'] = array(
    'name' => 'create client content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create contract content'.
  $permissions['create contract content'] = array(
    'name' => 'create contract content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create encashment content'.
  $permissions['create encashment content'] = array(
    'name' => 'create encashment content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

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

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create missing_product content'.
  $permissions['create missing_product content'] = array(
    'name' => 'create missing_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create product content'.
  $permissions['create product content'] = array(
    'name' => 'create product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create product_batch content'.
  $permissions['create product_batch content'] = array(
    'name' => 'create product_batch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create provider content'.
  $permissions['create provider content'] = array(
    'name' => 'create provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create revoked_product content'.
  $permissions['create revoked_product content'] = array(
    'name' => 'create revoked_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create transaction content'.
  $permissions['create transaction content'] = array(
    'name' => 'create transaction content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create transaction_product content'.
  $permissions['create transaction_product content'] = array(
    'name' => 'create transaction_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create waybill content'.
  $permissions['create waybill content'] = array(
    'name' => 'create waybill content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any branch content'.
  $permissions['delete any branch content'] = array(
    'name' => 'delete any branch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any client content'.
  $permissions['delete any client content'] = array(
    'name' => 'delete any client content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any contract content'.
  $permissions['delete any contract content'] = array(
    'name' => 'delete any contract content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any encashment content'.
  $permissions['delete any encashment content'] = array(
    'name' => 'delete any encashment content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any missing_product content'.
  $permissions['delete any missing_product content'] = array(
    'name' => 'delete any missing_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any product content'.
  $permissions['delete any product content'] = array(
    'name' => 'delete any product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any product_batch content'.
  $permissions['delete any product_batch content'] = array(
    'name' => 'delete any product_batch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any provider content'.
  $permissions['delete any provider content'] = array(
    'name' => 'delete any provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any revoked_product content'.
  $permissions['delete any revoked_product content'] = array(
    'name' => 'delete any revoked_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any transaction content'.
  $permissions['delete any transaction content'] = array(
    'name' => 'delete any transaction content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any transaction_product content'.
  $permissions['delete any transaction_product content'] = array(
    'name' => 'delete any transaction_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any waybill content'.
  $permissions['delete any waybill content'] = array(
    'name' => 'delete any waybill content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own branch content'.
  $permissions['delete own branch content'] = array(
    'name' => 'delete own branch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own client content'.
  $permissions['delete own client content'] = array(
    'name' => 'delete own client content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own contract content'.
  $permissions['delete own contract content'] = array(
    'name' => 'delete own contract content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own encashment content'.
  $permissions['delete own encashment content'] = array(
    'name' => 'delete own encashment content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own missing_product content'.
  $permissions['delete own missing_product content'] = array(
    'name' => 'delete own missing_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own product content'.
  $permissions['delete own product content'] = array(
    'name' => 'delete own product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own product_batch content'.
  $permissions['delete own product_batch content'] = array(
    'name' => 'delete own product_batch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own provider content'.
  $permissions['delete own provider content'] = array(
    'name' => 'delete own provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own revoked_product content'.
  $permissions['delete own revoked_product content'] = array(
    'name' => 'delete own revoked_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own transaction content'.
  $permissions['delete own transaction content'] = array(
    'name' => 'delete own transaction content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own transaction_product content'.
  $permissions['delete own transaction_product content'] = array(
    'name' => 'delete own transaction_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own waybill content'.
  $permissions['delete own waybill content'] = array(
    'name' => 'delete own waybill content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in countries'.
  $permissions['delete terms in countries'] = array(
    'name' => 'delete terms in countries',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in expense_type'.
  $permissions['delete terms in expense_type'] = array(
    'name' => 'delete terms in expense_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in manufacturers'.
  $permissions['delete terms in manufacturers'] = array(
    'name' => 'delete terms in manufacturers',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in payment_type'.
  $permissions['delete terms in payment_type'] = array(
    'name' => 'delete terms in payment_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any branch content'.
  $permissions['edit any branch content'] = array(
    'name' => 'edit any branch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any client content'.
  $permissions['edit any client content'] = array(
    'name' => 'edit any client content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any contract content'.
  $permissions['edit any contract content'] = array(
    'name' => 'edit any contract content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any encashment content'.
  $permissions['edit any encashment content'] = array(
    'name' => 'edit any encashment content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any license config_pages'.
  $permissions['edit any license config_pages'] = array(
    'name' => 'edit any license config_pages',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'config_pages',
  );

  // Exported permission: 'edit any main profile'.
  $permissions['edit any main profile'] = array(
    'name' => 'edit any main profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit any missing_product content'.
  $permissions['edit any missing_product content'] = array(
    'name' => 'edit any missing_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any product content'.
  $permissions['edit any product content'] = array(
    'name' => 'edit any product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any product_batch content'.
  $permissions['edit any product_batch content'] = array(
    'name' => 'edit any product_batch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any provider content'.
  $permissions['edit any provider content'] = array(
    'name' => 'edit any provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any revoked_product content'.
  $permissions['edit any revoked_product content'] = array(
    'name' => 'edit any revoked_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any transaction content'.
  $permissions['edit any transaction content'] = array(
    'name' => 'edit any transaction content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any transaction_product content'.
  $permissions['edit any transaction_product content'] = array(
    'name' => 'edit any transaction_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any waybill content'.
  $permissions['edit any waybill content'] = array(
    'name' => 'edit any waybill content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
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

  // Exported permission: 'edit other user\'s email address'.
  $permissions['edit other user\'s email address'] = array(
    'name' => 'edit other user\'s email address',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'useraccount_permissions',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own branch content'.
  $permissions['edit own branch content'] = array(
    'name' => 'edit own branch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own client content'.
  $permissions['edit own client content'] = array(
    'name' => 'edit own client content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own contract content'.
  $permissions['edit own contract content'] = array(
    'name' => 'edit own contract content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own email address'.
  $permissions['edit own email address'] = array(
    'name' => 'edit own email address',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'useraccount_permissions',
  );

  // Exported permission: 'edit own encashment content'.
  $permissions['edit own encashment content'] = array(
    'name' => 'edit own encashment content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
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

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own main profile'.
  $permissions['edit own main profile'] = array(
    'name' => 'edit own main profile',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own missing_product content'.
  $permissions['edit own missing_product content'] = array(
    'name' => 'edit own missing_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own product content'.
  $permissions['edit own product content'] = array(
    'name' => 'edit own product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own product_batch content'.
  $permissions['edit own product_batch content'] = array(
    'name' => 'edit own product_batch content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own provider content'.
  $permissions['edit own provider content'] = array(
    'name' => 'edit own provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own revoked_product content'.
  $permissions['edit own revoked_product content'] = array(
    'name' => 'edit own revoked_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own transaction content'.
  $permissions['edit own transaction content'] = array(
    'name' => 'edit own transaction content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own transaction_product content'.
  $permissions['edit own transaction_product content'] = array(
    'name' => 'edit own transaction_product content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own user account'.
  $permissions['edit own user account'] = array(
    'name' => 'edit own user account',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'useraccount_permissions',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own waybill content'.
  $permissions['edit own waybill content'] = array(
    'name' => 'edit own waybill content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in countries'.
  $permissions['edit terms in countries'] = array(
    'name' => 'edit terms in countries',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in expense_type'.
  $permissions['edit terms in expense_type'] = array(
    'name' => 'edit terms in expense_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in manufacturers'.
  $permissions['edit terms in manufacturers'] = array(
    'name' => 'edit terms in manufacturers',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in payment_type'.
  $permissions['edit terms in payment_type'] = array(
    'name' => 'edit terms in payment_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'enter all revision log entry'.
  $permissions['enter all revision log entry'] = array(
    'name' => 'enter all revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter branch revision log entry'.
  $permissions['enter branch revision log entry'] = array(
    'name' => 'enter branch revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter client revision log entry'.
  $permissions['enter client revision log entry'] = array(
    'name' => 'enter client revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter contract revision log entry'.
  $permissions['enter contract revision log entry'] = array(
    'name' => 'enter contract revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter encashment revision log entry'.
  $permissions['enter encashment revision log entry'] = array(
    'name' => 'enter encashment revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter missing_product revision log entry'.
  $permissions['enter missing_product revision log entry'] = array(
    'name' => 'enter missing_product revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter page revision log entry'.
  $permissions['enter page revision log entry'] = array(
    'name' => 'enter page revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter product revision log entry'.
  $permissions['enter product revision log entry'] = array(
    'name' => 'enter product revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter product_batch revision log entry'.
  $permissions['enter product_batch revision log entry'] = array(
    'name' => 'enter product_batch revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter provider revision log entry'.
  $permissions['enter provider revision log entry'] = array(
    'name' => 'enter provider revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter revoked_product revision log entry'.
  $permissions['enter revoked_product revision log entry'] = array(
    'name' => 'enter revoked_product revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter transaction revision log entry'.
  $permissions['enter transaction revision log entry'] = array(
    'name' => 'enter transaction revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter transaction_product revision log entry'.
  $permissions['enter transaction_product revision log entry'] = array(
    'name' => 'enter transaction_product revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter waybill revision log entry'.
  $permissions['enter waybill revision log entry'] = array(
    'name' => 'enter waybill revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'export taxonomy by csv'.
  $permissions['export taxonomy by csv'] = array(
    'name' => 'export taxonomy by csv',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_csv',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import taxonomy by csv'.
  $permissions['import taxonomy by csv'] = array(
    'name' => 'import taxonomy by csv',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_csv',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'override all authored by option'.
  $permissions['override all authored by option'] = array(
    'name' => 'override all authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override all authored on option'.
  $permissions['override all authored on option'] = array(
    'name' => 'override all authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override all promote to front page option'.
  $permissions['override all promote to front page option'] = array(
    'name' => 'override all promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override all published option'.
  $permissions['override all published option'] = array(
    'name' => 'override all published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override all revision option'.
  $permissions['override all revision option'] = array(
    'name' => 'override all revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override all sticky option'.
  $permissions['override all sticky option'] = array(
    'name' => 'override all sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override branch authored by option'.
  $permissions['override branch authored by option'] = array(
    'name' => 'override branch authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override branch authored on option'.
  $permissions['override branch authored on option'] = array(
    'name' => 'override branch authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override branch promote to front page option'.
  $permissions['override branch promote to front page option'] = array(
    'name' => 'override branch promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override branch published option'.
  $permissions['override branch published option'] = array(
    'name' => 'override branch published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override branch revision option'.
  $permissions['override branch revision option'] = array(
    'name' => 'override branch revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override branch sticky option'.
  $permissions['override branch sticky option'] = array(
    'name' => 'override branch sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override client authored by option'.
  $permissions['override client authored by option'] = array(
    'name' => 'override client authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override client authored on option'.
  $permissions['override client authored on option'] = array(
    'name' => 'override client authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override client promote to front page option'.
  $permissions['override client promote to front page option'] = array(
    'name' => 'override client promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override client published option'.
  $permissions['override client published option'] = array(
    'name' => 'override client published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override client revision option'.
  $permissions['override client revision option'] = array(
    'name' => 'override client revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override client sticky option'.
  $permissions['override client sticky option'] = array(
    'name' => 'override client sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contract authored by option'.
  $permissions['override contract authored by option'] = array(
    'name' => 'override contract authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contract authored on option'.
  $permissions['override contract authored on option'] = array(
    'name' => 'override contract authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contract promote to front page option'.
  $permissions['override contract promote to front page option'] = array(
    'name' => 'override contract promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contract published option'.
  $permissions['override contract published option'] = array(
    'name' => 'override contract published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contract revision option'.
  $permissions['override contract revision option'] = array(
    'name' => 'override contract revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contract sticky option'.
  $permissions['override contract sticky option'] = array(
    'name' => 'override contract sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override encashment authored by option'.
  $permissions['override encashment authored by option'] = array(
    'name' => 'override encashment authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override encashment authored on option'.
  $permissions['override encashment authored on option'] = array(
    'name' => 'override encashment authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override encashment promote to front page option'.
  $permissions['override encashment promote to front page option'] = array(
    'name' => 'override encashment promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override encashment published option'.
  $permissions['override encashment published option'] = array(
    'name' => 'override encashment published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override encashment revision option'.
  $permissions['override encashment revision option'] = array(
    'name' => 'override encashment revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override encashment sticky option'.
  $permissions['override encashment sticky option'] = array(
    'name' => 'override encashment sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override missing_product authored by option'.
  $permissions['override missing_product authored by option'] = array(
    'name' => 'override missing_product authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override missing_product authored on option'.
  $permissions['override missing_product authored on option'] = array(
    'name' => 'override missing_product authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override missing_product promote to front page option'.
  $permissions['override missing_product promote to front page option'] = array(
    'name' => 'override missing_product promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override missing_product published option'.
  $permissions['override missing_product published option'] = array(
    'name' => 'override missing_product published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override missing_product revision option'.
  $permissions['override missing_product revision option'] = array(
    'name' => 'override missing_product revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override missing_product sticky option'.
  $permissions['override missing_product sticky option'] = array(
    'name' => 'override missing_product sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page authored by option'.
  $permissions['override page authored by option'] = array(
    'name' => 'override page authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page authored on option'.
  $permissions['override page authored on option'] = array(
    'name' => 'override page authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page promote to front page option'.
  $permissions['override page promote to front page option'] = array(
    'name' => 'override page promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page published option'.
  $permissions['override page published option'] = array(
    'name' => 'override page published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page revision option'.
  $permissions['override page revision option'] = array(
    'name' => 'override page revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page sticky option'.
  $permissions['override page sticky option'] = array(
    'name' => 'override page sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product authored by option'.
  $permissions['override product authored by option'] = array(
    'name' => 'override product authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product authored on option'.
  $permissions['override product authored on option'] = array(
    'name' => 'override product authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product promote to front page option'.
  $permissions['override product promote to front page option'] = array(
    'name' => 'override product promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product published option'.
  $permissions['override product published option'] = array(
    'name' => 'override product published option',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product revision option'.
  $permissions['override product revision option'] = array(
    'name' => 'override product revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product sticky option'.
  $permissions['override product sticky option'] = array(
    'name' => 'override product sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product_batch authored by option'.
  $permissions['override product_batch authored by option'] = array(
    'name' => 'override product_batch authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product_batch authored on option'.
  $permissions['override product_batch authored on option'] = array(
    'name' => 'override product_batch authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product_batch promote to front page option'.
  $permissions['override product_batch promote to front page option'] = array(
    'name' => 'override product_batch promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product_batch published option'.
  $permissions['override product_batch published option'] = array(
    'name' => 'override product_batch published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product_batch revision option'.
  $permissions['override product_batch revision option'] = array(
    'name' => 'override product_batch revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override product_batch sticky option'.
  $permissions['override product_batch sticky option'] = array(
    'name' => 'override product_batch sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override provider authored by option'.
  $permissions['override provider authored by option'] = array(
    'name' => 'override provider authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override provider authored on option'.
  $permissions['override provider authored on option'] = array(
    'name' => 'override provider authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override provider promote to front page option'.
  $permissions['override provider promote to front page option'] = array(
    'name' => 'override provider promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override provider published option'.
  $permissions['override provider published option'] = array(
    'name' => 'override provider published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override provider revision option'.
  $permissions['override provider revision option'] = array(
    'name' => 'override provider revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override provider sticky option'.
  $permissions['override provider sticky option'] = array(
    'name' => 'override provider sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override revoked_product authored by option'.
  $permissions['override revoked_product authored by option'] = array(
    'name' => 'override revoked_product authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override revoked_product authored on option'.
  $permissions['override revoked_product authored on option'] = array(
    'name' => 'override revoked_product authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override revoked_product promote to front page option'.
  $permissions['override revoked_product promote to front page option'] = array(
    'name' => 'override revoked_product promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override revoked_product published option'.
  $permissions['override revoked_product published option'] = array(
    'name' => 'override revoked_product published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override revoked_product revision option'.
  $permissions['override revoked_product revision option'] = array(
    'name' => 'override revoked_product revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override revoked_product sticky option'.
  $permissions['override revoked_product sticky option'] = array(
    'name' => 'override revoked_product sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction authored by option'.
  $permissions['override transaction authored by option'] = array(
    'name' => 'override transaction authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction authored on option'.
  $permissions['override transaction authored on option'] = array(
    'name' => 'override transaction authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction promote to front page option'.
  $permissions['override transaction promote to front page option'] = array(
    'name' => 'override transaction promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction published option'.
  $permissions['override transaction published option'] = array(
    'name' => 'override transaction published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction revision option'.
  $permissions['override transaction revision option'] = array(
    'name' => 'override transaction revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction sticky option'.
  $permissions['override transaction sticky option'] = array(
    'name' => 'override transaction sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction_product authored by option'.
  $permissions['override transaction_product authored by option'] = array(
    'name' => 'override transaction_product authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction_product authored on option'.
  $permissions['override transaction_product authored on option'] = array(
    'name' => 'override transaction_product authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction_product promote to front page option'.
  $permissions['override transaction_product promote to front page option'] = array(
    'name' => 'override transaction_product promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction_product published option'.
  $permissions['override transaction_product published option'] = array(
    'name' => 'override transaction_product published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction_product revision option'.
  $permissions['override transaction_product revision option'] = array(
    'name' => 'override transaction_product revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override transaction_product sticky option'.
  $permissions['override transaction_product sticky option'] = array(
    'name' => 'override transaction_product sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override waybill authored by option'.
  $permissions['override waybill authored by option'] = array(
    'name' => 'override waybill authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override waybill authored on option'.
  $permissions['override waybill authored on option'] = array(
    'name' => 'override waybill authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override waybill promote to front page option'.
  $permissions['override waybill promote to front page option'] = array(
    'name' => 'override waybill promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override waybill published option'.
  $permissions['override waybill published option'] = array(
    'name' => 'override waybill published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override waybill revision option'.
  $permissions['override waybill revision option'] = array(
    'name' => 'override waybill revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override waybill sticky option'.
  $permissions['override waybill sticky option'] = array(
    'name' => 'override waybill sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'show format selection for config_pages'.
  $permissions['show format selection for config_pages'] = array(
    'name' => 'show format selection for config_pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for profile2'.
  $permissions['show format selection for profile2'] = array(
    'name' => 'show format selection for profile2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'toggle nicemessages'.
  $permissions['toggle nicemessages'] = array(
    'name' => 'toggle nicemessages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nicemessages',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unique_field_perm_admin'.
  $permissions['unique_field_perm_admin'] = array(
    'name' => 'unique_field_perm_admin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'unique_field',
  );

  // Exported permission: 'unique_field_perm_bypass'.
  $permissions['unique_field_perm_bypass'] = array(
    'name' => 'unique_field_perm_bypass',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'unique_field',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any main profile'.
  $permissions['view any main profile'] = array(
    'name' => 'view any main profile',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'profile2',
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

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'manager' => 'manager',
      'seller' => 'seller',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own main profile'.
  $permissions['view own main profile'] = array(
    'name' => 'view own main profile',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
      'warehouse manager' => 'warehouse manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
