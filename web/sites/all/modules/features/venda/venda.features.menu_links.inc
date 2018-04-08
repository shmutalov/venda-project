<?php
/**
 * @file
 * venda.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function venda_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_--:http://appteca.uz/ru/documentation.
  $menu_links['main-menu_--:http://appteca.uz/ru/documentation'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://appteca.uz/ru/documentation',
    'router_path' => '',
    'link_title' => 'Инструкция по использованию',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_--:http://appteca.uz/ru/documentation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_-:http://appteca.uz/ru',
  );
  // Exported menu link: main-menu_--:http://appteca.uz/ru/faq.
  $menu_links['main-menu_--:http://appteca.uz/ru/faq'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://appteca.uz/ru/faq',
    'router_path' => '',
    'link_title' => 'Часто задаваемые вопросы',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_--:http://appteca.uz/ru/faq',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_-:http://appteca.uz/ru',
  );
  // Exported menu link: main-menu_--:https://login.appteca.uz/ru/user.
  $menu_links['main-menu_--:https://login.appteca.uz/ru/user'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://login.appteca.uz/ru/user',
    'router_path' => '',
    'link_title' => 'Войти в систему',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => 'btn-danger',
        'style' => '',
      ),
      'identifier' => 'main-menu_--:https://login.appteca.uz/ru/user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_-:http://appteca.uz/ru.
  $menu_links['main-menu_-:http://appteca.uz/ru'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://appteca.uz/ru',
    'router_path' => '',
    'link_title' => 'О программе',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_-:http://appteca.uz/ru',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_-:http://appteca.uz/ru/medicaments/search.
  $menu_links['main-menu_-:http://appteca.uz/ru/medicaments/search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://appteca.uz/ru/medicaments/search',
    'router_path' => '',
    'link_title' => 'Поиск лекарства',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_-:http://appteca.uz/ru/medicaments/search',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_-:http://appteca.uz/ru/vitrina.
  $menu_links['main-menu_-:http://appteca.uz/ru/vitrina'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://appteca.uz/ru/vitrina',
    'router_path' => '',
    'link_title' => 'Интернет-витрина',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_-:http://appteca.uz/ru/vitrina',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_:http://appteca.uz/ru/devices.
  $menu_links['main-menu_:http://appteca.uz/ru/devices'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://appteca.uz/ru/devices',
    'router_path' => '',
    'link_title' => 'Оборудование',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_:http://appteca.uz/ru/devices',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_:http://appteca.uz/ru/pricing.
  $menu_links['main-menu_:http://appteca.uz/ru/pricing'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://appteca.uz/ru/pricing',
    'router_path' => '',
    'link_title' => 'Цены',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_:http://appteca.uz/ru/pricing',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: management_--:admin/config/people/accounts/display/full.
  $menu_links['management_--:admin/config/people/accounts/display/full'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/accounts/display/full',
    'router_path' => 'admin/config/people/accounts/display/full',
    'link_title' => 'Учётная запись пользователя',
    'options' => array(
      'identifier' => 'management_--:admin/config/people/accounts/display/full',
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_-:admin/config/people/accounts/display',
  );
  // Exported menu link: management_-:admin/structure/profiles.
  $menu_links['management_-:admin/structure/profiles'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/profiles',
    'router_path' => 'admin/structure/profiles',
    'link_title' => 'Типы профилей',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage profiles, including fields.',
      ),
      'identifier' => 'management_-:admin/structure/profiles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_account-settings:admin/config/people/accounts.
  $menu_links['management_account-settings:admin/config/people/accounts'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/accounts',
    'router_path' => 'admin/config/people/accounts',
    'link_title' => 'Account settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure default behavior of users, including registration requirements, e-mails, fields, and user pictures.',
      ),
      'identifier' => 'management_account-settings:admin/config/people/accounts',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/people',
  );
  // Exported menu link: management_actions:admin/config/system/actions.
  $menu_links['management_actions:admin/config/system/actions'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/actions',
    'router_path' => 'admin/config/system/actions',
    'link_title' => 'Actions',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage the actions defined for your site.',
      ),
      'identifier' => 'management_actions:admin/config/system/actions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_adminimal-menu:admin/config/administration/adminimal_menu.
  $menu_links['management_adminimal-menu:admin/config/administration/adminimal_menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration/adminimal_menu',
    'router_path' => 'admin/config/administration/adminimal_menu',
    'link_title' => 'Adminimal menu',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust adminimal menu settings.',
      ),
      'identifier' => 'management_adminimal-menu:admin/config/administration/adminimal_menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/administration',
  );
  // Exported menu link: management_administration-menu:admin/config/administration/admin_menu.
  $menu_links['management_administration-menu:admin/config/administration/admin_menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration/admin_menu',
    'router_path' => 'admin/config/administration/admin_menu',
    'link_title' => 'Administration menu',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust administration menu settings.',
      ),
      'identifier' => 'management_administration-menu:admin/config/administration/admin_menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/administration',
  );
  // Exported menu link: management_administration:admin.
  $menu_links['management_administration:admin'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin',
    'router_path' => 'admin',
    'link_title' => 'Administration',
    'options' => array(
      'identifier' => 'management_administration:admin',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 0,
  );
  // Exported menu link: management_administration:admin/config/administration.
  $menu_links['management_administration:admin/config/administration'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration',
    'router_path' => 'admin/config/administration',
    'link_title' => 'Administration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administration tools.',
      ),
      'identifier' => 'management_administration:admin/config/administration',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_appearance:admin/appearance.
  $menu_links['management_appearance:admin/appearance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/appearance',
    'router_path' => 'admin/appearance',
    'link_title' => 'Appearance',
    'options' => array(
      'attributes' => array(
        'title' => 'Select and configure your themes.',
      ),
      'identifier' => 'management_appearance:admin/appearance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -6,
    'customized' => 0,
    'parent_identifier' => 'management_:admin',
  );
  // Exported menu link: management_authcache:admin/config/system/authcache.
  $menu_links['management_authcache:admin/config/system/authcache'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/authcache',
    'router_path' => 'admin/config/system/authcache',
    'link_title' => 'Authcache',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure authenticated user page caching.',
      ),
      'identifier' => 'management_authcache:admin/config/system/authcache',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_available-updates:admin/reports/updates.
  $menu_links['management_available-updates:admin/reports/updates'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/updates',
    'router_path' => 'admin/reports/updates',
    'link_title' => 'Available updates',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about available updates for your installed modules and themes.',
      ),
      'identifier' => 'management_available-updates:admin/reports/updates',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_blocks:admin/structure/block.
  $menu_links['management_blocks:admin/structure/block'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Blocks',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure what block content appears in your site\'s sidebars and other regions.',
      ),
      'identifier' => 'management_blocks:admin/structure/block',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_cache-expiration:admin/config/system/expire.
  $menu_links['management_cache-expiration:admin/config/system/expire'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/expire',
    'router_path' => 'admin/config/system/expire',
    'link_title' => 'Cache Expiration',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for expiration of cached pages.',
      ),
      'identifier' => 'management_cache-expiration:admin/config/system/expire',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_ckeditor:admin/config/content/ckeditor.
  $menu_links['management_ckeditor:admin/config/content/ckeditor'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/ckeditor',
    'router_path' => 'admin/config/content/ckeditor',
    'link_title' => 'CKEditor',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the rich text editor.',
      ),
      'identifier' => 'management_ckeditor:admin/config/content/ckeditor',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/content',
  );
  // Exported menu link: management_clean-urls:admin/config/search/clean-urls.
  $menu_links['management_clean-urls:admin/config/search/clean-urls'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/clean-urls',
    'router_path' => 'admin/config/search/clean-urls',
    'link_title' => 'Clean URLs',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable clean URLs for your site.',
      ),
      'identifier' => 'management_clean-urls:admin/config/search/clean-urls',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/search',
  );
  // Exported menu link: management_clientside-validation:admin/config/validation/clientside_validation.
  $menu_links['management_clientside-validation:admin/config/validation/clientside_validation'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/validation/clientside_validation',
    'router_path' => 'admin/config/validation/clientside_validation',
    'link_title' => 'Clientside Validation',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer clientside validation.',
      ),
      'identifier' => 'management_clientside-validation:admin/config/validation/clientside_validation',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/validation',
  );
  // Exported menu link: management_config-pages:admin/config/development/config_pages_types.
  $menu_links['management_config-pages:admin/config/development/config_pages_types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/config_pages_types',
    'router_path' => 'admin/config/development/config_pages_types',
    'link_title' => 'Config Pages',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage config_pages entity types, including adding and removing fields and the display of fields.',
      ),
      'identifier' => 'management_config-pages:admin/config/development/config_pages_types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/development',
  );
  // Exported menu link: management_configuration:admin/config.
  $menu_links['management_configuration:admin/config'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config',
    'router_path' => 'admin/config',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer settings.',
      ),
      'identifier' => 'management_configuration:admin/config',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin',
  );
  // Exported menu link: management_content-authoring:admin/config/content.
  $menu_links['management_content-authoring:admin/config/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content',
    'router_path' => 'admin/config/content',
    'link_title' => 'Content authoring',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings related to formatting and authoring content.',
      ),
      'identifier' => 'management_content-authoring:admin/config/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_content-types:admin/structure/types.
  $menu_links['management_content-types:admin/structure/types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/types',
    'router_path' => 'admin/structure/types',
    'link_title' => 'Content types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage content types, including default status, front page promotion, comment settings, etc.',
      ),
      'identifier' => 'management_content-types:admin/structure/types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_content:admin/content.
  $menu_links['management_content:admin/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => 'Find and manage content.',
      ),
      'identifier' => 'management_content:admin/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin',
  );
  // Exported menu link: management_cron:admin/config/system/cron.
  $menu_links['management_cron:admin/config/system/cron'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/cron',
    'router_path' => 'admin/config/system/cron',
    'link_title' => 'Cron',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage automatic site maintenance tasks.',
      ),
      'identifier' => 'management_cron:admin/config/system/cron',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_custom-forms:admin/config/validation/clientside_validation/custom-forms.
  $menu_links['management_custom-forms:admin/config/validation/clientside_validation/custom-forms'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/validation/clientside_validation/custom-forms',
    'router_path' => 'admin/config/validation/clientside_validation/custom-forms',
    'link_title' => 'Custom forms',
    'options' => array(
      'attributes' => array(
        'title' => 'Override settings for custom forms.',
      ),
      'identifier' => 'management_custom-forms:admin/config/validation/clientside_validation/custom-forms',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 12,
    'customized' => 0,
    'parent_identifier' => 'management_clientside-validation:admin/config/validation/clientside_validation',
  );
  // Exported menu link: management_date-and-time:admin/config/regional/date-time.
  $menu_links['management_date-and-time:admin/config/regional/date-time'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/date-time',
    'router_path' => 'admin/config/regional/date-time',
    'link_title' => 'Date and time',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure display formats for date and time.',
      ),
      'identifier' => 'management_date-and-time:admin/config/regional/date-time',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/regional',
  );
  // Exported menu link: management_date-api:admin/config/date.
  $menu_links['management_date-api:admin/config/date'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/date',
    'router_path' => 'admin/config/date',
    'link_title' => 'Date API',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for modules the use the Date API.',
      ),
      'identifier' => 'management_date-api:admin/config/date',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_default-chart-configuration:admin/config/content/charts.
  $menu_links['management_default-chart-configuration:admin/config/content/charts'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/charts',
    'router_path' => 'admin/config/content/charts',
    'link_title' => 'Default chart configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Set the default library, behavior, and style of charts.',
      ),
      'identifier' => 'management_default-chart-configuration:admin/config/content/charts',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/content',
  );
  // Exported menu link: management_development:admin/config/development.
  $menu_links['management_development:admin/config/development'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development',
    'router_path' => 'admin/config/development',
    'link_title' => 'Development',
    'options' => array(
      'attributes' => array(
        'title' => 'Development tools.',
      ),
      'identifier' => 'management_development:admin/config/development',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_email-contact-form-settings:admin/config/content/email.
  $menu_links['management_email-contact-form-settings:admin/config/content/email'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/email',
    'router_path' => 'admin/config/content/email',
    'link_title' => 'Email Contact Form Settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer flood control settings for email contact forms',
      ),
      'identifier' => 'management_email-contact-form-settings:admin/config/content/email',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/content',
  );
  // Exported menu link: management_features:admin/structure/features.
  $menu_links['management_features:admin/structure/features'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/features',
    'router_path' => 'admin/structure/features',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage features.',
      ),
      'identifier' => 'management_features:admin/structure/features',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_field-collections:admin/structure/field-collections.
  $menu_links['management_field-collections:admin/structure/field-collections'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/field-collections',
    'router_path' => 'admin/structure/field-collections',
    'link_title' => 'Field collections',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage fields on field collections.',
      ),
      'identifier' => 'management_field-collections:admin/structure/field-collections',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_field-list:admin/reports/fields.
  $menu_links['management_field-list:admin/reports/fields'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/fields',
    'router_path' => 'admin/reports/fields',
    'link_title' => 'Field list',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of fields on all entity types.',
      ),
      'identifier' => 'management_field-list:admin/reports/fields',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_field-track-changes:admin/config/system/track_field_changes.
  $menu_links['management_field-track-changes:admin/config/system/track_field_changes'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/track_field_changes',
    'router_path' => 'admin/config/system/track_field_changes',
    'link_title' => 'Field Track Changes',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable and disable which content type and fields need to be audited.',
      ),
      'identifier' => 'management_field-track-changes:admin/config/system/track_field_changes',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_file-settings:admin/config/media/file-settings.
  $menu_links['management_file-settings:admin/config/media/file-settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/file-settings',
    'router_path' => 'admin/config/media/file-settings',
    'link_title' => 'File settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure allowed file extensions, default alt and title sources, and the file upload wizard.',
      ),
      'identifier' => 'management_file-settings:admin/config/media/file-settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/media',
  );
  // Exported menu link: management_file-system:admin/config/media/file-system.
  $menu_links['management_file-system:admin/config/media/file-system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/file-system',
    'router_path' => 'admin/config/media/file-system',
    'link_title' => 'File system',
    'options' => array(
      'attributes' => array(
        'title' => 'Tell Drupal where to store uploaded files and how they are accessed.',
      ),
      'identifier' => 'management_file-system:admin/config/media/file-system',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/media',
  );
  // Exported menu link: management_file-types:admin/structure/file-types.
  $menu_links['management_file-types:admin/structure/file-types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/file-types',
    'router_path' => 'admin/structure/file-types',
    'link_title' => 'File types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage settings for the type of files used on your site.',
      ),
      'identifier' => 'management_file-types:admin/structure/file-types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_files:admin/content/file.
  $menu_links['management_files:admin/content/file'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/file',
    'router_path' => 'admin/content/file',
    'link_title' => 'Files',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage files used on your site.',
      ),
      'identifier' => 'management_files:admin/content/file',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/content',
  );
  // Exported menu link: management_global-redirect:admin/config/system/globalredirect.
  $menu_links['management_global-redirect:admin/config/system/globalredirect'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/globalredirect',
    'router_path' => 'admin/config/system/globalredirect',
    'link_title' => 'Global Redirect',
    'options' => array(
      'attributes' => array(
        'title' => 'Chose which features you would like enabled for Global Redirect',
      ),
      'identifier' => 'management_global-redirect:admin/config/system/globalredirect',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_image-styles:admin/config/media/image-styles.
  $menu_links['management_image-styles:admin/config/media/image-styles'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-styles',
    'router_path' => 'admin/config/media/image-styles',
    'link_title' => 'Image styles',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure styles that can be used for resizing or adjusting images on display.',
      ),
      'identifier' => 'management_image-styles:admin/config/media/image-styles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/media',
  );
  // Exported menu link: management_image-toolkit:admin/config/media/image-toolkit.
  $menu_links['management_image-toolkit:admin/config/media/image-toolkit'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-toolkit',
    'router_path' => 'admin/config/media/image-toolkit',
    'link_title' => 'Image toolkit',
    'options' => array(
      'attributes' => array(
        'title' => 'Choose which image toolkit to use if you have installed optional toolkits.',
      ),
      'identifier' => 'management_image-toolkit:admin/config/media/image-toolkit',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/media',
  );
  // Exported menu link: management_ip-address-blocking:admin/config/people/ip-blocking.
  $menu_links['management_ip-address-blocking:admin/config/people/ip-blocking'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/ip-blocking',
    'router_path' => 'admin/config/people/ip-blocking',
    'link_title' => 'IP address blocking',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage blocked IP addresses.',
      ),
      'identifier' => 'management_ip-address-blocking:admin/config/people/ip-blocking',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/people',
  );
  // Exported menu link: management_languages:admin/config/regional/language.
  $menu_links['management_languages:admin/config/regional/language'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/language',
    'router_path' => 'admin/config/regional/language',
    'link_title' => 'Languages',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure languages for content and the user interface.',
      ),
      'identifier' => 'management_languages:admin/config/regional/language',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/regional',
  );
  // Exported menu link: management_libraries:admin/reports/libraries.
  $menu_links['management_libraries:admin/reports/libraries'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/libraries',
    'router_path' => 'admin/reports/libraries',
    'link_title' => 'Libraries',
    'options' => array(
      'attributes' => array(
        'title' => 'An overview of libraries installed on this site.',
      ),
      'identifier' => 'management_libraries:admin/reports/libraries',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_license:admin/config/system/license.
  $menu_links['management_license:admin/config/system/license'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/license',
    'router_path' => 'admin/config/system',
    'link_title' => 'License',
    'options' => array(
      'identifier' => 'management_license:admin/config/system/license',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_logging-and-errors:admin/config/development/logging.
  $menu_links['management_logging-and-errors:admin/config/development/logging'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/logging',
    'router_path' => 'admin/config/development/logging',
    'link_title' => 'Logging and errors',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for logging and alerts modules. Various modules can route Drupal\'s system events to different destinations, such as syslog, database, email, etc.',
      ),
      'identifier' => 'management_logging-and-errors:admin/config/development/logging',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/development',
  );
  // Exported menu link: management_logintoboggan:admin/config/system/logintoboggan.
  $menu_links['management_logintoboggan:admin/config/system/logintoboggan'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/logintoboggan',
    'router_path' => 'admin/config/system/logintoboggan',
    'link_title' => 'LoginToboggan',
    'options' => array(
      'attributes' => array(
        'title' => 'Set up custom login options like instant login, login redirects, pre-authorized validation roles, etc.',
      ),
      'identifier' => 'management_logintoboggan:admin/config/system/logintoboggan',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_main-menu:admin/structure/menu/manage/main-menu.
  $menu_links['management_main-menu:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Main menu',
    'options' => array(
      'identifier' => 'management_main-menu:admin/structure/menu/manage/main-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: management_maintenance-mode:admin/config/development/maintenance.
  $menu_links['management_maintenance-mode:admin/config/development/maintenance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/maintenance',
    'router_path' => 'admin/config/development/maintenance',
    'link_title' => 'Maintenance mode',
    'options' => array(
      'attributes' => array(
        'title' => 'Take the site offline for maintenance or bring it back online.',
      ),
      'identifier' => 'management_maintenance-mode:admin/config/development/maintenance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/development',
  );
  // Exported menu link: management_management:admin/structure/menu/manage/management.
  $menu_links['management_management:admin/structure/menu/manage/management'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/management',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Management',
    'options' => array(
      'identifier' => 'management_management:admin/structure/menu/manage/management',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: management_manager-menu:admin/structure/menu/manage/menu-manager-menu.
  $menu_links['management_manager-menu:admin/structure/menu/manage/menu-manager-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-manager-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Manager menu',
    'options' => array(
      'identifier' => 'management_manager-menu:admin/structure/menu/manage/menu-manager-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: management_media-browser-settings:admin/config/media/browser.
  $menu_links['management_media-browser-settings:admin/config/media/browser'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/browser',
    'router_path' => 'admin/config/media/browser',
    'link_title' => 'Media browser settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the behavior and display of the media browser.',
      ),
      'identifier' => 'management_media-browser-settings:admin/config/media/browser',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/media',
  );
  // Exported menu link: management_media:admin/config/media.
  $menu_links['management_media:admin/config/media'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media',
    'router_path' => 'admin/config/media',
    'link_title' => 'Media',
    'options' => array(
      'attributes' => array(
        'title' => 'Media tools.',
      ),
      'identifier' => 'management_media:admin/config/media',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_menus:admin/structure/menu.
  $menu_links['management_menus:admin/structure/menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu',
    'router_path' => 'admin/structure/menu',
    'link_title' => 'Menus',
    'options' => array(
      'attributes' => array(
        'title' => 'Add new menus to your site, edit existing menus, and rename and reorganize menu links.',
      ),
      'identifier' => 'management_menus:admin/structure/menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_missing-module-message-fixer:admin/config/system/module-missing-message-fixer.
  $menu_links['management_missing-module-message-fixer:admin/config/system/module-missing-message-fixer'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/module-missing-message-fixer',
    'router_path' => 'admin/config/system/module-missing-message-fixer',
    'link_title' => 'Missing Module Message Fixer',
    'options' => array(
      'attributes' => array(
        'title' => 'This module display a list of missing module that appear after the Drupal 7.50 release and lets you fix the entries.',
      ),
      'identifier' => 'management_missing-module-message-fixer:admin/config/system/module-missing-message-fixer',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_module-filter:admin/config/user-interface/modulefilter.
  $menu_links['management_module-filter:admin/config/user-interface/modulefilter'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/modulefilter',
    'router_path' => 'admin/config/user-interface/modulefilter',
    'link_title' => 'Module filter',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure how the modules page looks and acts.',
      ),
      'identifier' => 'management_module-filter:admin/config/user-interface/modulefilter',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_-:admin/config/user-interface',
  );
  // Exported menu link: management_modules:admin/modules.
  $menu_links['management_modules:admin/modules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/modules',
    'router_path' => 'admin/modules',
    'link_title' => 'Modules',
    'options' => array(
      'attributes' => array(
        'title' => 'Extend site functionality.',
      ),
      'identifier' => 'management_modules:admin/modules',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -2,
    'customized' => 0,
    'parent_identifier' => 'management_:admin',
  );
  // Exported menu link: management_multilingual-settings:admin/config/regional/i18n.
  $menu_links['management_multilingual-settings:admin/config/regional/i18n'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/i18n',
    'router_path' => 'admin/config/regional/i18n',
    'link_title' => 'Multilingual settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure extended options for multilingual content and translations.',
      ),
      'identifier' => 'management_multilingual-settings:admin/config/regional/i18n',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/regional',
  );
  // Exported menu link: management_navigation:admin/structure/menu/manage/navigation.
  $menu_links['management_navigation:admin/structure/menu/manage/navigation'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/navigation',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Navigation',
    'options' => array(
      'identifier' => 'management_navigation:admin/structure/menu/manage/navigation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: management_nice-messages:admin/config/system/nicemessages.
  $menu_links['management_nice-messages:admin/config/system/nicemessages'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/nicemessages',
    'router_path' => 'admin/config/system/nicemessages',
    'link_title' => 'Nice messages',
    'options' => array(
      'attributes' => array(
        'title' => 'Nice messages configuration',
      ),
      'identifier' => 'management_nice-messages:admin/config/system/nicemessages',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_override-node-options-settings:admin/config/content/override-node-options.
  $menu_links['management_override-node-options-settings:admin/config/content/override-node-options'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/override-node-options',
    'router_path' => 'admin/config/content/override-node-options',
    'link_title' => 'Override Node Options Settings',
    'options' => array(
      'identifier' => 'management_override-node-options-settings:admin/config/content/override-node-options',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/content',
  );
  // Exported menu link: management_people:admin/config/people.
  $menu_links['management_people:admin/config/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people',
    'router_path' => 'admin/config/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure user accounts.',
      ),
      'identifier' => 'management_people:admin/config/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_people:admin/people.
  $menu_links['management_people:admin/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage user accounts, roles, and permissions.',
      ),
      'identifier' => 'management_people:admin/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -4,
    'customized' => 0,
    'parent_identifier' => 'management_:admin',
  );
  // Exported menu link: management_performance:admin/config/development/performance.
  $menu_links['management_performance:admin/config/development/performance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/performance',
    'router_path' => 'admin/config/development/performance',
    'link_title' => 'Performance',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable page caching for anonymous users and set CSS and JS bandwidth optimization options.',
      ),
      'identifier' => 'management_performance:admin/config/development/performance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/development',
  );
  // Exported menu link: management_recent-log-messages:admin/reports/dblog.
  $menu_links['management_recent-log-messages:admin/reports/dblog'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/dblog',
    'router_path' => 'admin/reports/dblog',
    'link_title' => 'Recent log messages',
    'options' => array(
      'attributes' => array(
        'title' => 'View events that have recently been logged.',
      ),
      'identifier' => 'management_recent-log-messages:admin/reports/dblog',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_regional-and-language:admin/config/regional.
  $menu_links['management_regional-and-language:admin/config/regional'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional',
    'router_path' => 'admin/config/regional',
    'link_title' => 'Regional and language',
    'options' => array(
      'attributes' => array(
        'title' => 'Regional settings, localization and translation.',
      ),
      'identifier' => 'management_regional-and-language:admin/config/regional',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_regional-settings:admin/config/regional/settings.
  $menu_links['management_regional-settings:admin/config/regional/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/settings',
    'router_path' => 'admin/config/regional/settings',
    'link_title' => 'Regional settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for the site\'s default time zone and country.',
      ),
      'identifier' => 'management_regional-settings:admin/config/regional/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/regional',
  );
  // Exported menu link: management_report-menu:admin/structure/menu/manage/menu-report-menu.
  $menu_links['management_report-menu:admin/structure/menu/manage/menu-report-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-report-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Report menu',
    'options' => array(
      'identifier' => 'management_report-menu:admin/structure/menu/manage/menu-report-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: management_reports:admin/reports.
  $menu_links['management_reports:admin/reports'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports',
    'router_path' => 'admin/reports',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'View reports, updates, and errors.',
      ),
      'identifier' => 'management_reports:admin/reports',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_:admin',
  );
  // Exported menu link: management_rss-publishing:admin/config/services/rss-publishing.
  $menu_links['management_rss-publishing:admin/config/services/rss-publishing'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/rss-publishing',
    'router_path' => 'admin/config/services/rss-publishing',
    'link_title' => 'RSS publishing',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the site description, the number of items per feed and whether feeds should be titles/teasers/full-text.',
      ),
      'identifier' => 'management_rss-publishing:admin/config/services/rss-publishing',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_-:admin/config/services',
  );
  // Exported menu link: management_rules:admin/config/workflow/rules.
  $menu_links['management_rules:admin/config/workflow/rules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow/rules',
    'router_path' => 'admin/config/workflow/rules',
    'link_title' => 'Rules',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage reaction rules and rule components.',
      ),
      'identifier' => 'management_rules:admin/config/workflow/rules',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/workflow',
  );
  // Exported menu link: management_search-and-metadata:admin/config/search.
  $menu_links['management_search-and-metadata:admin/config/search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search',
    'router_path' => 'admin/config/search',
    'link_title' => 'Search and metadata',
    'options' => array(
      'attributes' => array(
        'title' => 'Local site search, metadata and SEO.',
      ),
      'identifier' => 'management_search-and-metadata:admin/config/search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_site-information:admin/config/system/site-information.
  $menu_links['management_site-information:admin/config/system/site-information'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/site-information',
    'router_path' => 'admin/config/system/site-information',
    'link_title' => 'Site information',
    'options' => array(
      'attributes' => array(
        'title' => 'Change site name, e-mail address, slogan, default front page, and number of posts per page, error pages.',
      ),
      'identifier' => 'management_site-information:admin/config/system/site-information',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config/system',
  );
  // Exported menu link: management_status-report:admin/reports/status.
  $menu_links['management_status-report:admin/reports/status'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/status',
    'router_path' => 'admin/reports/status',
    'link_title' => 'Status report',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about your site\'s operation and any detected problems.',
      ),
      'identifier' => 'management_status-report:admin/reports/status',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_structure:admin/structure.
  $menu_links['management_structure:admin/structure'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure',
    'router_path' => 'admin/structure',
    'link_title' => 'Structure',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer blocks, content types, menus, etc.',
      ),
      'identifier' => 'management_structure:admin/structure',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -8,
    'customized' => 0,
    'parent_identifier' => 'management_:admin',
  );
  // Exported menu link: management_system:admin/config/system.
  $menu_links['management_system:admin/config/system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system',
    'router_path' => 'admin/config/system',
    'link_title' => 'System',
    'options' => array(
      'attributes' => array(
        'title' => 'General system related configuration.',
      ),
      'identifier' => 'management_system:admin/config/system',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_taxonomy:admin/structure/taxonomy.
  $menu_links['management_taxonomy:admin/structure/taxonomy'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy',
    'router_path' => 'admin/structure/taxonomy',
    'link_title' => 'Taxonomy',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage tagging, categorization, and classification of your content.',
      ),
      'identifier' => 'management_taxonomy:admin/structure/taxonomy',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_text-formats:admin/config/content/formats.
  $menu_links['management_text-formats:admin/config/content/formats'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/formats',
    'router_path' => 'admin/config/content/formats',
    'link_title' => 'Text formats',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure how content input by users is filtered, including allowed HTML tags. Also allows enabling of module-provided filters.',
      ),
      'identifier' => 'management_text-formats:admin/config/content/formats',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/content',
  );
  // Exported menu link: management_top-access-denied-errors:admin/reports/access-denied.
  $menu_links['management_top-access-denied-errors:admin/reports/access-denied'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/access-denied',
    'router_path' => 'admin/reports/access-denied',
    'link_title' => 'Top \'access denied\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'access denied\' errors (403s).',
      ),
      'identifier' => 'management_top-access-denied-errors:admin/reports/access-denied',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_top-page-not-found-errors:admin/reports/page-not-found.
  $menu_links['management_top-page-not-found-errors:admin/reports/page-not-found'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/page-not-found',
    'router_path' => 'admin/reports/page-not-found',
    'link_title' => 'Top \'page not found\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'page not found\' errors (404s).',
      ),
      'identifier' => 'management_top-page-not-found-errors:admin/reports/page-not-found',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_translate-interface:admin/config/regional/translate.
  $menu_links['management_translate-interface:admin/config/regional/translate'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/translate',
    'router_path' => 'admin/config/regional/translate',
    'link_title' => 'Translate interface',
    'options' => array(
      'attributes' => array(
        'title' => 'Translate the built in interface and optionally other text.',
      ),
      'identifier' => 'management_translate-interface:admin/config/regional/translate',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/regional',
  );
  // Exported menu link: management_url-aliases:admin/config/search/path.
  $menu_links['management_url-aliases:admin/config/search/path'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/path',
    'router_path' => 'admin/config/search/path',
    'link_title' => 'URL aliases',
    'options' => array(
      'attributes' => array(
        'title' => 'Change your site\'s URL paths by aliasing them.',
      ),
      'identifier' => 'management_url-aliases:admin/config/search/path',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_--:admin/config/search',
  );
  // Exported menu link: management_user-interface:admin/config/user-interface.
  $menu_links['management_user-interface:admin/config/user-interface'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface',
    'router_path' => 'admin/config/user-interface',
    'link_title' => 'User interface',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools that enhance the user interface.',
      ),
      'identifier' => 'management_user-interface:admin/config/user-interface',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_user-menu:admin/structure/menu/manage/user-menu.
  $menu_links['management_user-menu:admin/structure/menu/manage/user-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/user-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'User menu',
    'options' => array(
      'identifier' => 'management_user-menu:admin/structure/menu/manage/user-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: management_validation:admin/config/validation.
  $menu_links['management_validation:admin/config/validation'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/validation',
    'router_path' => 'admin/config/validation',
    'link_title' => 'Validation',
    'options' => array(
      'attributes' => array(
        'title' => 'Validation settings.',
      ),
      'identifier' => 'management_validation:admin/config/validation',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_views-plugins:admin/reports/views-plugins.
  $menu_links['management_views-plugins:admin/reports/views-plugins'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/views-plugins',
    'router_path' => 'admin/reports/views-plugins',
    'link_title' => 'Views plugins',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of plugins used in all views.',
      ),
      'identifier' => 'management_views-plugins:admin/reports/views-plugins',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/reports',
  );
  // Exported menu link: management_views:admin/structure/views.
  $menu_links['management_views:admin/structure/views'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/views',
    'router_path' => 'admin/structure/views',
    'link_title' => 'Views',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage customized lists of content.',
      ),
      'identifier' => 'management_views:admin/structure/views',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure',
  );
  // Exported menu link: management_web-services:admin/config/services.
  $menu_links['management_web-services:admin/config/services'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services',
    'router_path' => 'admin/config/services',
    'link_title' => 'Web services',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools related to web services.',
      ),
      'identifier' => 'management_web-services:admin/config/services',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: management_workflow:admin/config/workflow.
  $menu_links['management_workflow:admin/config/workflow'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow',
    'router_path' => 'admin/config/workflow',
    'link_title' => 'Workflow',
    'options' => array(
      'attributes' => array(
        'title' => 'Content workflow, editorial workflow tools.',
      ),
      'identifier' => 'management_workflow:admin/config/workflow',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/config',
  );
  // Exported menu link: menu-manager-menu_--:admin/structure/taxonomy/manufacturers/add.
  $menu_links['menu-manager-menu_--:admin/structure/taxonomy/manufacturers/add'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'admin/structure/taxonomy/manufacturers/add',
    'router_path' => 'admin/structure/taxonomy/%/add',
    'link_title' => 'Добавить новый производитель',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:admin/structure/taxonomy/manufacturers/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-duplicatespan:dashboard/manufacturers',
  );
  // Exported menu link: menu-manager-menu_--:dashboard/sellers/new.
  $menu_links['menu-manager-menu_--:dashboard/sellers/new'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/sellers/new',
    'router_path' => 'dashboard/sellers/new',
    'link_title' => 'Регистрация нового продавца',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:dashboard/sellers/new',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-userspan:dashboard/sellers',
  );
  // Exported menu link: menu-manager-menu_--:dashboard/warehouse/apply.
  $menu_links['menu-manager-menu_--:dashboard/warehouse/apply'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/apply',
    'router_path' => 'dashboard/warehouse/apply',
    'link_title' => 'Поступление по накладной',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:dashboard/warehouse/apply',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_--:dashboard/warehouse/expiring.
  $menu_links['menu-manager-menu_--:dashboard/warehouse/expiring'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/expiring',
    'router_path' => 'dashboard/warehouse/expiring',
    'link_title' => 'Истекающий срок годности',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:dashboard/warehouse/expiring',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_--:dashboard/warehouse/no-stock.
  $menu_links['menu-manager-menu_--:dashboard/warehouse/no-stock'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/no-stock',
    'router_path' => 'dashboard/warehouse/no-stock',
    'link_title' => 'Нет в наличии',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:dashboard/warehouse/no-stock',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_--:node/add/client.
  $menu_links['menu-manager-menu_--:node/add/client'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'node/add/client',
    'router_path' => 'node/add/client',
    'link_title' => 'Добавить новый клиент',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:node/add/client',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-tagsspan:dashboard/clients',
  );
  // Exported menu link: menu-manager-menu_--:node/add/product.
  $menu_links['menu-manager-menu_--:node/add/product'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'node/add/product',
    'router_path' => 'node/add/product',
    'link_title' => 'Добавить новый продукт',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:node/add/product',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_--:node/add/provider.
  $menu_links['menu-manager-menu_--:node/add/provider'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'node/add/provider',
    'router_path' => 'node/add/provider',
    'link_title' => 'Добавить нового поставщика',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--:node/add/provider',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-briefcasespan:dashboard/providers',
  );
  // Exported menu link: menu-manager-menu_--csv:dashboard/warehouse/export.
  $menu_links['menu-manager-menu_--csv:dashboard/warehouse/export'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/export',
    'router_path' => 'dashboard/warehouse/export',
    'link_title' => 'Экспорт в CSV',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--csv:dashboard/warehouse/export',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_--csv:dashboard/warehouse/import.
  $menu_links['menu-manager-menu_--csv:dashboard/warehouse/import'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/import',
    'router_path' => 'dashboard/warehouse/import',
    'link_title' => 'Импорт из CSV',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--csv:dashboard/warehouse/import',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_--csv:dashboard/warehouse/import/extract.
  $menu_links['menu-manager-menu_--csv:dashboard/warehouse/import/extract'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/import/extract',
    'router_path' => 'dashboard/warehouse/import/extract',
    'link_title' => 'Импорт из CSV',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_--csv:dashboard/warehouse/import/extract',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_--csv:dashboard/warehouse/import',
  );
  // Exported menu link: menu-manager-menu_-:admin/config/system/backup_migrate.
  $menu_links['menu-manager-menu_-:admin/config/system/backup_migrate'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'admin/config/system/backup_migrate',
    'router_path' => 'admin/config/system',
    'link_title' => 'Резерв. копирование',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:admin/config/system/backup_migrate',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-cogspan:dashboard/settings',
  );
  // Exported menu link: menu-manager-menu_-:dashboard/reports/date.
  $menu_links['menu-manager-menu_-:dashboard/reports/date'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/reports/date',
    'router_path' => 'dashboard/reports/date',
    'link_title' => 'По дате',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:dashboard/reports/date',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-equalizerspan:dashboard/reports',
  );
  // Exported menu link: menu-manager-menu_-:dashboard/reports/hours.
  $menu_links['menu-manager-menu_-:dashboard/reports/hours'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/reports/hours',
    'router_path' => 'dashboard/reports/hours',
    'link_title' => 'По часам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:dashboard/reports/hours',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-equalizerspan:dashboard/reports',
  );
  // Exported menu link: menu-manager-menu_-:dashboard/reports/products.
  $menu_links['menu-manager-menu_-:dashboard/reports/products'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/reports/products',
    'router_path' => 'dashboard/reports/products',
    'link_title' => 'По продуктам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:dashboard/reports/products',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-equalizerspan:dashboard/reports',
  );
  // Exported menu link: menu-manager-menu_-:dashboard/reports/providers.
  $menu_links['menu-manager-menu_-:dashboard/reports/providers'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/reports/providers',
    'router_path' => 'dashboard/reports/providers',
    'link_title' => 'По поставщикам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:dashboard/reports/providers',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-equalizerspan:dashboard/reports',
  );
  // Exported menu link: menu-manager-menu_-:dashboard/reports/sellers.
  $menu_links['menu-manager-menu_-:dashboard/reports/sellers'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/reports/sellers',
    'router_path' => 'dashboard/reports/sellers',
    'link_title' => 'По продавцам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:dashboard/reports/sellers',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-equalizerspan:dashboard/reports',
  );
  // Exported menu link: menu-manager-menu_-:dashboard/warehouse/denied-products.
  $menu_links['menu-manager-menu_-:dashboard/warehouse/denied-products'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/denied-products',
    'router_path' => 'dashboard/warehouse/denied-products',
    'link_title' => 'Отказной лист',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:dashboard/warehouse/denied-products',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_-:dashboard/warehouse/revoke.
  $menu_links['menu-manager-menu_-:dashboard/warehouse/revoke'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse/revoke',
    'router_path' => 'dashboard/warehouse/revoke',
    'link_title' => 'Списание товаров',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:dashboard/warehouse/revoke',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
  );
  // Exported menu link: menu-manager-menu_-:node/add/encashment.
  $menu_links['menu-manager-menu_-:node/add/encashment'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'node/add/encashment',
    'router_path' => 'node/add/encashment',
    'link_title' => 'Добавить сумму',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:node/add/encashment',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_:dashboard/reports/encashment',
  );
  // Exported menu link: menu-manager-menu_-:user.
  $menu_links['menu-manager-menu_-:user'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Настройки профиля',
    'options' => array(
      'alter' => TRUE,
      'html' => 1,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_-:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-cogspan:dashboard/settings',
  );
  // Exported menu link: menu-manager-menu_:dashboard/providers/contracts.
  $menu_links['menu-manager-menu_:dashboard/providers/contracts'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/providers/contracts',
    'router_path' => 'dashboard/providers/contracts',
    'link_title' => 'Договоры',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_:dashboard/providers/contracts',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-briefcasespan:dashboard/providers',
  );
  // Exported menu link: menu-manager-menu_:dashboard/providers/waybills.
  $menu_links['menu-manager-menu_:dashboard/providers/waybills'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/providers/waybills',
    'router_path' => 'dashboard/providers',
    'link_title' => 'Накладные',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_:dashboard/providers/waybills',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-briefcasespan:dashboard/providers',
  );
  // Exported menu link: menu-manager-menu_:dashboard/reports/encashment.
  $menu_links['menu-manager-menu_:dashboard/reports/encashment'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/reports/encashment',
    'router_path' => 'dashboard/reports/encashment',
    'link_title' => 'Расходы',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_:dashboard/reports/encashment',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-equalizerspan:dashboard/reports',
  );
  // Exported menu link: menu-manager-menu_span-classglyphicon-glyphicon-briefcasespan:dashboard/providers.
  $menu_links['menu-manager-menu_span-classglyphicon-glyphicon-briefcasespan:dashboard/providers'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/providers',
    'router_path' => 'dashboard/providers',
    'link_title' => '<span class="glyphicon glyphicon-briefcase"></span>Поставщики',
    'options' => array(
      'html' => 1,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-briefcasespan:dashboard/providers',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-manager-menu_span-classglyphicon-glyphicon-cogspan:dashboard/settings.
  $menu_links['menu-manager-menu_span-classglyphicon-glyphicon-cogspan:dashboard/settings'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/settings',
    'router_path' => 'dashboard/settings',
    'link_title' => '<span class="glyphicon glyphicon-cog"></span>Настройки',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-cogspan:dashboard/settings',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: menu-manager-menu_span-classglyphicon-glyphicon-duplicatespan:dashboard/manufacturers.
  $menu_links['menu-manager-menu_span-classglyphicon-glyphicon-duplicatespan:dashboard/manufacturers'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/manufacturers',
    'router_path' => 'dashboard/manufacturers',
    'link_title' => '<span class="glyphicon glyphicon-duplicate"></span>Производители',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-duplicatespan:dashboard/manufacturers',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-manager-menu_span-classglyphicon-glyphicon-scalespan:dashboard/sell.
  $menu_links['menu-manager-menu_span-classglyphicon-glyphicon-scalespan:dashboard/sell'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/sell',
    'router_path' => 'dashboard/sell',
    'link_title' => '<span class="glyphicon glyphicon-scale"></span>Касса',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-scalespan:dashboard/sell',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse.
  $menu_links['menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/warehouse',
    'router_path' => 'dashboard/warehouse',
    'link_title' => '<span class="glyphicon glyphicon-shopping-cart"></span>Склад',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-shopping-cartspan:dashboard/warehouse',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-manager-menu_span-classglyphicon-glyphicon-tagsspan:dashboard/clients.
  $menu_links['menu-manager-menu_span-classglyphicon-glyphicon-tagsspan:dashboard/clients'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/clients',
    'router_path' => 'dashboard/clients',
    'link_title' => '<span class="glyphicon glyphicon-tags"></span>Клиенты',
    'options' => array(
      'html' => 1,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-tagsspan:dashboard/clients',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-manager-menu_span-classglyphicon-glyphicon-userspan:dashboard/sellers.
  $menu_links['menu-manager-menu_span-classglyphicon-glyphicon-userspan:dashboard/sellers'] = array(
    'menu_name' => 'menu-manager-menu',
    'link_path' => 'dashboard/sellers',
    'router_path' => 'dashboard/sellers',
    'link_title' => '<span class="glyphicon glyphicon-user"></span>Продавцы',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-manager-menu_span-classglyphicon-glyphicon-userspan:dashboard/sellers',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-report-menu_-:dashboard/reports.
  $menu_links['menu-report-menu_-:dashboard/reports'] = array(
    'menu_name' => 'menu-report-menu',
    'link_path' => 'dashboard/reports',
    'router_path' => 'dashboard/reports',
    'link_title' => 'Все транзакции',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-report-menu_-:dashboard/reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-report-menu_-:dashboard/reports/date.
  $menu_links['menu-report-menu_-:dashboard/reports/date'] = array(
    'menu_name' => 'menu-report-menu',
    'link_path' => 'dashboard/reports/date',
    'router_path' => 'dashboard/reports/date',
    'link_title' => 'По дате',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-report-menu_-:dashboard/reports/date',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-report-menu_-:dashboard/reports/hours.
  $menu_links['menu-report-menu_-:dashboard/reports/hours'] = array(
    'menu_name' => 'menu-report-menu',
    'link_path' => 'dashboard/reports/hours',
    'router_path' => 'dashboard/reports/hours',
    'link_title' => 'По часам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-report-menu_-:dashboard/reports/hours',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-report-menu_-:dashboard/reports/products.
  $menu_links['menu-report-menu_-:dashboard/reports/products'] = array(
    'menu_name' => 'menu-report-menu',
    'link_path' => 'dashboard/reports/products',
    'router_path' => 'dashboard/reports/products',
    'link_title' => 'По продуктам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-report-menu_-:dashboard/reports/products',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-report-menu_-:dashboard/reports/providers.
  $menu_links['menu-report-menu_-:dashboard/reports/providers'] = array(
    'menu_name' => 'menu-report-menu',
    'link_path' => 'dashboard/reports/providers',
    'router_path' => 'dashboard/reports/providers',
    'link_title' => 'По поставщикам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-report-menu_-:dashboard/reports/providers',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-report-menu_-:dashboard/reports/sellers.
  $menu_links['menu-report-menu_-:dashboard/reports/sellers'] = array(
    'menu_name' => 'menu-report-menu',
    'link_path' => 'dashboard/reports/sellers',
    'router_path' => 'dashboard/reports/sellers',
    'link_title' => 'По продавцам',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-report-menu_-:dashboard/reports/sellers',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: navigation_--:dashboard/warehouse/apply.
  $menu_links['navigation_--:dashboard/warehouse/apply'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/warehouse/apply',
    'router_path' => 'dashboard/warehouse/apply',
    'link_title' => 'Поступление по накладной',
    'options' => array(
      'identifier' => 'navigation_--:dashboard/warehouse/apply',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_--csv:dashboard/warehouse/export.
  $menu_links['navigation_--csv:dashboard/warehouse/export'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/warehouse/export',
    'router_path' => 'dashboard/warehouse/export',
    'link_title' => 'Экспорт в CSV',
    'options' => array(
      'identifier' => 'navigation_--csv:dashboard/warehouse/export',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_--csv:dashboard/warehouse/import.
  $menu_links['navigation_--csv:dashboard/warehouse/import'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/warehouse/import',
    'router_path' => 'dashboard/warehouse/import',
    'link_title' => 'Импорт из CSV',
    'options' => array(
      'identifier' => 'navigation_--csv:dashboard/warehouse/import',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_--csv:dashboard/warehouse/import/extract.
  $menu_links['navigation_--csv:dashboard/warehouse/import/extract'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/warehouse/import/extract',
    'router_path' => 'dashboard/warehouse/import/extract',
    'link_title' => 'Импорт из CSV',
    'options' => array(
      'identifier' => 'navigation_--csv:dashboard/warehouse/import/extract',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_--csv:dashboard/warehouse/import',
  );
  // Exported menu link: navigation_-:dashboard/settings.
  $menu_links['navigation_-:dashboard/settings'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/settings',
    'router_path' => 'dashboard/settings',
    'link_title' => 'Настройки сайта',
    'options' => array(
      'identifier' => 'navigation_-:dashboard/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_-:dashboard/warehouse/revoke.
  $menu_links['navigation_-:dashboard/warehouse/revoke'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/warehouse/revoke',
    'router_path' => 'dashboard/warehouse/revoke',
    'link_title' => 'Списание товаров',
    'options' => array(
      'identifier' => 'navigation_-:dashboard/warehouse/revoke',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_-:node/add/missing-product.
  $menu_links['navigation_-:node/add/missing-product'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/missing-product',
    'router_path' => 'node/add/missing-product',
    'link_title' => 'Отказной товар',
    'options' => array(
      'identifier' => 'navigation_-:node/add/missing-product',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_-:node/add/revoked-product.
  $menu_links['navigation_-:node/add/revoked-product'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/revoked-product',
    'router_path' => 'node/add/revoked-product',
    'link_title' => 'Списанный товар',
    'options' => array(
      'identifier' => 'navigation_-:node/add/revoked-product',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_-:node/add/transaction-product.
  $menu_links['navigation_-:node/add/transaction-product'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/transaction-product',
    'router_path' => 'node/add/transaction-product',
    'link_title' => 'Продукт транзакции',
    'options' => array(
      'identifier' => 'navigation_-:node/add/transaction-product',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:dashboard/sell.
  $menu_links['navigation_:dashboard/sell'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/sell',
    'router_path' => 'dashboard/sell',
    'link_title' => 'Касса',
    'options' => array(
      'identifier' => 'navigation_:dashboard/sell',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_:dashboard/sellers/new.
  $menu_links['navigation_:dashboard/sellers/new'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/sellers/new',
    'router_path' => 'dashboard/sellers/new',
    'link_title' => '',
    'options' => array(
      'identifier' => 'navigation_:dashboard/sellers/new',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_:dashboard/warehouse/export/get-batches.
  $menu_links['navigation_:dashboard/warehouse/export/get-batches'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard/warehouse/export/get-batches',
    'router_path' => 'dashboard/warehouse/export/get-batches',
    'link_title' => '',
    'options' => array(
      'identifier' => 'navigation_:dashboard/warehouse/export/get-batches',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_--csv:dashboard/warehouse/export',
  );
  // Exported menu link: navigation_:node/add/branch.
  $menu_links['navigation_:node/add/branch'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/branch',
    'router_path' => 'node/add/branch',
    'link_title' => 'Филиал',
    'options' => array(
      'identifier' => 'navigation_:node/add/branch',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/client.
  $menu_links['navigation_:node/add/client'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/client',
    'router_path' => 'node/add/client',
    'link_title' => 'Клиент',
    'options' => array(
      'identifier' => 'navigation_:node/add/client',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/contract.
  $menu_links['navigation_:node/add/contract'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/contract',
    'router_path' => 'node/add/contract',
    'link_title' => 'Договор',
    'options' => array(
      'identifier' => 'navigation_:node/add/contract',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/encashment.
  $menu_links['navigation_:node/add/encashment'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/encashment',
    'router_path' => 'node/add/encashment',
    'link_title' => 'Расход',
    'options' => array(
      'identifier' => 'navigation_:node/add/encashment',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/page.
  $menu_links['navigation_:node/add/page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Страница',
    'options' => array(
      'identifier' => 'navigation_:node/add/page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/product.
  $menu_links['navigation_:node/add/product'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/product',
    'router_path' => 'node/add/product',
    'link_title' => 'Продукт',
    'options' => array(
      'identifier' => 'navigation_:node/add/product',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/product-batch.
  $menu_links['navigation_:node/add/product-batch'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/product-batch',
    'router_path' => 'node/add/product-batch',
    'link_title' => 'Партия',
    'options' => array(
      'identifier' => 'navigation_:node/add/product-batch',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/provider.
  $menu_links['navigation_:node/add/provider'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/provider',
    'router_path' => 'node/add/provider',
    'link_title' => 'Поставщик',
    'options' => array(
      'identifier' => 'navigation_:node/add/provider',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/transaction.
  $menu_links['navigation_:node/add/transaction'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/transaction',
    'router_path' => 'node/add/transaction',
    'link_title' => 'Транзакция',
    'options' => array(
      'identifier' => 'navigation_:node/add/transaction',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_:node/add/waybill.
  $menu_links['navigation_:node/add/waybill'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/waybill',
    'router_path' => 'node/add/waybill',
    'link_title' => 'Накладная',
    'options' => array(
      'identifier' => 'navigation_:node/add/waybill',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_-:node/add',
  );
  // Exported menu link: navigation_add-content:node/add.
  $menu_links['navigation_add-content:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'identifier' => 'navigation_add-content:node/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_add-file:file/add.
  $menu_links['navigation_add-file:file/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'file/add',
    'router_path' => 'file/add',
    'link_title' => 'Add file',
    'options' => array(
      'identifier' => 'navigation_add-file:file/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_charts-examples:charts/examples.
  $menu_links['navigation_charts-examples:charts/examples'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'charts/examples',
    'router_path' => 'charts/examples',
    'link_title' => 'Charts examples',
    'options' => array(
      'identifier' => 'navigation_charts-examples:charts/examples',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_compose-tips:filter/tips.
  $menu_links['navigation_compose-tips:filter/tips'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(
      'identifier' => 'navigation_compose-tips:filter/tips',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<span class="glyphicon glyphicon-briefcase"></span>Поставщики');
  t('<span class="glyphicon glyphicon-cog"></span>Настройки');
  t('<span class="glyphicon glyphicon-duplicate"></span>Производители');
  t('<span class="glyphicon glyphicon-scale"></span>Касса');
  t('<span class="glyphicon glyphicon-shopping-cart"></span>Склад');
  t('<span class="glyphicon glyphicon-tags"></span>Клиенты');
  t('<span class="glyphicon glyphicon-user"></span>Продавцы');
  t('Account settings');
  t('Actions');
  t('Add content');
  t('Add file');
  t('Adminimal menu');
  t('Administration');
  t('Administration menu');
  t('Appearance');
  t('Authcache');
  t('Available updates');
  t('Blocks');
  t('CKEditor');
  t('Cache Expiration');
  t('Charts examples');
  t('Clean URLs');
  t('Clientside Validation');
  t('Compose tips');
  t('Config Pages');
  t('Configuration');
  t('Content');
  t('Content authoring');
  t('Content types');
  t('Cron');
  t('Custom forms');
  t('Date API');
  t('Date and time');
  t('Default chart configuration');
  t('Development');
  t('Email Contact Form Settings');
  t('Features');
  t('Field Track Changes');
  t('Field collections');
  t('Field list');
  t('File settings');
  t('File system');
  t('File types');
  t('Files');
  t('Global Redirect');
  t('IP address blocking');
  t('Image styles');
  t('Image toolkit');
  t('Languages');
  t('Libraries');
  t('License');
  t('Log out');
  t('Logging and errors');
  t('LoginToboggan');
  t('Main menu');
  t('Maintenance mode');
  t('Management');
  t('Manager menu');
  t('Media');
  t('Media browser settings');
  t('Menus');
  t('Missing Module Message Fixer');
  t('Module filter');
  t('Modules');
  t('Multilingual settings');
  t('Navigation');
  t('Nice messages');
  t('Override Node Options Settings');
  t('People');
  t('Performance');
  t('RSS publishing');
  t('Recent log messages');
  t('Regional and language');
  t('Regional settings');
  t('Report menu');
  t('Reports');
  t('Rules');
  t('Search and metadata');
  t('Site information');
  t('Status report');
  t('Structure');
  t('System');
  t('Taxonomy');
  t('Text formats');
  t('Top \'access denied\' errors');
  t('Top \'page not found\' errors');
  t('Translate interface');
  t('URL aliases');
  t('User account');
  t('User interface');
  t('User menu');
  t('Validation');
  t('Views');
  t('Views plugins');
  t('Web services');
  t('Workflow');
  t('Войти в систему');
  t('Все транзакции');
  t('Добавить нового поставщика');
  t('Добавить новый клиент');
  t('Добавить новый продукт');
  t('Добавить новый производитель');
  t('Добавить сумму');
  t('Договор');
  t('Договоры');
  t('Импорт из CSV');
  t('Инструкция по использованию');
  t('Интернет-витрина');
  t('Истекающий срок годности');
  t('Касса');
  t('Клиент');
  t('Накладная');
  t('Накладные');
  t('Настройки профиля');
  t('Настройки сайта');
  t('Нет в наличии');
  t('О программе');
  t('Оборудование');
  t('Отказной лист');
  t('Отказной товар');
  t('Партия');
  t('По дате');
  t('По поставщикам');
  t('По продавцам');
  t('По продуктам');
  t('По часам');
  t('Поиск лекарства');
  t('Поставщик');
  t('Поступление по накладной');
  t('Продукт');
  t('Продукт транзакции');
  t('Расход');
  t('Расходы');
  t('Регистрация нового продавца');
  t('Резерв. копирование');
  t('Списание товаров');
  t('Списанный товар');
  t('Страница');
  t('Типы профилей');
  t('Транзакция');
  t('Учётная запись пользователя');
  t('Филиал');
  t('Цены');
  t('Часто задаваемые вопросы');
  t('Экспорт в CSV');

  return $menu_links;
}
