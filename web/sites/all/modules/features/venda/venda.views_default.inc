<?php
/**
 * @file
 * venda.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function venda_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'batches_by_product';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Все партии по продуктам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Партии';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Поле: Содержимое: Дата прибытия */
  $handler->display->display_options['fields']['field_pr_income_date']['id'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['table'] = 'field_data_field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['field'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_pr_amount']['id'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['field'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_pr_price_base']['id'] = 'field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['table'] = 'field_data_field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['field'] = 'field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_pr_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_pr_price']['id'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['table'] = 'field_data_field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['field'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_pr_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Критерий сортировки: Содержимое: Порядковый номер (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  /* Контекстный фильтр: Содержимое: Продукт (field_pb_product) */
  $handler->display->display_options['arguments']['field_pb_product_nid']['id'] = 'field_pb_product_nid';
  $handler->display->display_options['arguments']['field_pb_product_nid']['table'] = 'field_data_field_pb_product';
  $handler->display->display_options['arguments']['field_pb_product_nid']['field'] = 'field_pb_product_nid';
  $handler->display->display_options['arguments']['field_pb_product_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_pb_product_nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_pb_product_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_batch' => 'product_batch',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['batches_by_product'] = $view;

  $view = new view();
  $view->name = 'branches';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Филиалы';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Филиалы';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right"><a href="/ru/dashboard/branches/add-new?destination=dashboard/branches" class="btn btn-success">Добавить нового филиала</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Филиалы ещё не добавлены.</>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить филиала',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Поле: ID филиала */
  $handler->display->display_options['fields']['field_apteka_id']['id'] = 'field_apteka_id';
  $handler->display->display_options['fields']['field_apteka_id']['table'] = 'field_data_field_apteka_id';
  $handler->display->display_options['fields']['field_apteka_id']['field'] = 'field_apteka_id';
  $handler->display->display_options['fields']['field_apteka_id']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<span class="glyphicon glyphicon-edit" data-toggle="tooltip" data-placement="top" title="Редактировать"></span>';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = '<span class="glyphicon glyphicon-remove-circle text-danger" data-toggle="tooltip" data-placement="top" title="Удалить"></span>';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]&nbsp; 
[delete_node]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'h4 text-right';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'branch' => 'branch',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/branches';

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $export['branches'] = $view;

  $view = new view();
  $view->name = 'clients';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Клиенты';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Клиенты';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right"><a href="/ru/dashboard/clients/add-new?destination=dashboard/clients" class="btn btn-success">Добавить новый клиент</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Клиенты ещё не добавлены.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Клиент (field_trc_client) - реверс */
  $handler->display->display_options['relationships']['reverse_field_trc_client_node']['id'] = 'reverse_field_trc_client_node';
  $handler->display->display_options['relationships']['reverse_field_trc_client_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_trc_client_node']['field'] = 'reverse_field_trc_client_node';
  $handler->display->display_options['relationships']['reverse_field_trc_client_node']['label'] = 'client';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить договор',
    ),
  );
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Клиент';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Номер телефона */
  $handler->display->display_options['fields']['field_client_phone']['id'] = 'field_client_phone';
  $handler->display->display_options['fields']['field_client_phone']['table'] = 'field_data_field_client_phone';
  $handler->display->display_options['fields']['field_client_phone']['field'] = 'field_client_phone';
  $handler->display->display_options['fields']['field_client_phone']['delta_limit'] = '5';
  $handler->display->display_options['fields']['field_client_phone']['delta_offset'] = '0';
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['relationship'] = 'reverse_field_trc_client_node';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Покупки';
  $handler->display->display_options['fields']['field_trc_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price']['alter']['text'] = '[field_trc_price] сум';
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Наличные) */
  $handler->display->display_options['fields']['field_trc_payment_cash']['id'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['table'] = 'field_data_field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['field'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['relationship'] = 'reverse_field_trc_client_node';
  $handler->display->display_options['fields']['field_trc_payment_cash']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_payment_cash']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_payment_cash']['alter']['text'] = '[field_trc_payment_cash] сум';
  $handler->display->display_options['fields']['field_trc_payment_cash']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_cash']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Терминал) */
  $handler->display->display_options['fields']['field_trc_payment_terminal']['id'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['table'] = 'field_data_field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['field'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['relationship'] = 'reverse_field_trc_client_node';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_payment_terminal']['alter']['text'] = '[field_trc_payment_terminal] сум';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Долг) */
  $handler->display->display_options['fields']['field_trc_payment_owe']['id'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['table'] = 'field_data_field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['field'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['relationship'] = 'reverse_field_trc_client_node';
  $handler->display->display_options['fields']['field_trc_payment_owe']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_payment_owe']['label'] = 'Долги';
  $handler->display->display_options['fields']['field_trc_payment_owe']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_payment_owe']['alter']['text'] = '[field_trc_payment_owe] сум';
  $handler->display->display_options['fields']['field_trc_payment_owe']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_owe']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<span class="glyphicon glyphicon-edit" data-toggle="tooltip" data-placement="top" title="Редактировать"></span>';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = '<span class="glyphicon glyphicon-remove-circle text-danger" data-toggle="tooltip" data-placement="top" title="Удалить"></span>';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/ru/dashboard/reports?client=[nid]&payment_type=10342"><span class="glyphicon glyphicon-repeat text-primary" data-toggle="tooltip" data-placement="top" title="Долги"></span></a>
[edit_node] [delete_node]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'h4 text-right';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'client' => 'client',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/clients';
  $export['clients'] = $view;

  $view = new view();
  $view->name = 'contracts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Договоры';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Договоры';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right pull-right margin-top-38"><a href="/ru/dashboard/providers/contracts/add-new?destination=dashboard/providers/contracts" class="btn btn-success">Добавить новый договор</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Договоры ещё не добавлены.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить договор',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Дата договора */
  $handler->display->display_options['fields']['field_dg_date']['id'] = 'field_dg_date';
  $handler->display->display_options['fields']['field_dg_date']['table'] = 'field_data_field_dg_date';
  $handler->display->display_options['fields']['field_dg_date']['field'] = 'field_dg_date';
  $handler->display->display_options['fields']['field_dg_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Поставщик */
  $handler->display->display_options['fields']['field_dg_provider']['id'] = 'field_dg_provider';
  $handler->display->display_options['fields']['field_dg_provider']['table'] = 'field_data_field_dg_provider';
  $handler->display->display_options['fields']['field_dg_provider']['field'] = 'field_dg_provider';
  $handler->display->display_options['fields']['field_dg_provider']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dg_provider']['alter']['path'] = 'node/[field_dg_provider-nid]/edit';
  $handler->display->display_options['fields']['field_dg_provider']['type'] = 'node_reference_plain';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<span class="glyphicon glyphicon-edit" data-toggle="tooltip" data-placement="top" title="Редактировать"></span>';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = '<span class="glyphicon glyphicon-remove-circle text-danger" data-toggle="tooltip" data-placement="top" title="Удалить"></span>';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]&nbsp; 
[delete_node]&nbsp;';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'h4 text-right';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contract' => 'contract',
  );
  /* Критерий фильтра: Содержимое: Поставщик (field_dg_provider) */
  $handler->display->display_options['filters']['field_dg_provider_nid']['id'] = 'field_dg_provider_nid';
  $handler->display->display_options['filters']['field_dg_provider_nid']['table'] = 'field_data_field_dg_provider';
  $handler->display->display_options['filters']['field_dg_provider_nid']['field'] = 'field_dg_provider_nid';
  $handler->display->display_options['filters']['field_dg_provider_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dg_provider_nid']['expose']['operator_id'] = 'field_dg_provider_nid_op';
  $handler->display->display_options['filters']['field_dg_provider_nid']['expose']['label'] = 'Поставщик';
  $handler->display->display_options['filters']['field_dg_provider_nid']['expose']['operator'] = 'field_dg_provider_nid_op';
  $handler->display->display_options['filters']['field_dg_provider_nid']['expose']['identifier'] = 'provider';
  $handler->display->display_options['filters']['field_dg_provider_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Дата договора (field_dg_date) */
  $handler->display->display_options['filters']['field_dg_date_value']['id'] = 'field_dg_date_value';
  $handler->display->display_options['filters']['field_dg_date_value']['table'] = 'field_data_field_dg_date';
  $handler->display->display_options['filters']['field_dg_date_value']['field'] = 'field_dg_date_value';
  $handler->display->display_options['filters']['field_dg_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dg_date_value']['expose']['operator_id'] = 'field_dg_date_value_op';
  $handler->display->display_options['filters']['field_dg_date_value']['expose']['label'] = 'Дата';
  $handler->display->display_options['filters']['field_dg_date_value']['expose']['operator'] = 'field_dg_date_value_op';
  $handler->display->display_options['filters']['field_dg_date_value']['expose']['identifier'] = 'field_dg_date_value';
  $handler->display->display_options['filters']['field_dg_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_dg_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_dg_date_value']['year_range'] = '-0:+0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['path'] = 'dashboard/providers/contracts';
  $export['contracts'] = $view;

  $view = new view();
  $view->name = 'daily_sales';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ежедневные продажи';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ежедневные продажи';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'area';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'created';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_trc_price' => 'field_trc_price',
    'field_trc_payment_cash' => 'field_trc_payment_cash',
    'field_trc_payment_terminal' => 'field_trc_payment_terminal',
    'php' => 'php',
    'created' => 0,
    'field_trc_price_base' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'created' => '#2f7ed8',
    'field_trc_price' => '#0979d5',
    'field_trc_price_base' => '#14ce0f',
    'field_trc_payment_cash' => '#008080',
    'field_trc_payment_terminal' => '#800080',
    'php' => '#55d301',
  );
  $handler->display->display_options['style_options']['title'] = 'Ежедневные продажи';
  $handler->display->display_options['style_options']['legend_position'] = '';
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '300';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
  $handler->display->display_options['style_options']['yaxis_title'] = 'Продажи';
  $handler->display->display_options['style_options']['yaxis_min'] = '0';
  $handler->display->display_options['style_options']['yaxis_suffix'] = ' сум';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Ymd';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. продажи';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Наличные) */
  $handler->display->display_options['fields']['field_trc_payment_cash']['id'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['table'] = 'field_data_field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['field'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_payment_cash']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_trc_payment_cash']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Терминал) */
  $handler->display->display_options['fields']['field_trc_payment_terminal']['id'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['table'] = 'field_data_field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['field'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль ';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$rozn = 
	isset($data->field_data_field_trc_price_field_trc_price_value)
	? $data->field_data_field_trc_price_field_trc_price_value
	: 0;

$opt = 
	isset($data->field_data_field_trc_price_base_field_trc_price_base_value)
	? $data->field_data_field_trc_price_base_field_trc_price_base_value
	: 0;

$profit = $rozn - $opt;
return $profit;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['code'] = 'return customizer_manager_user_context_filter();';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  /* Критерий фильтра: Содержимое: Дата публикации */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['value'] = 'today - 10 days';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  /* Критерий фильтра: Содержимое: Тип транзакции (field_trc_type) */
  $handler->display->display_options['filters']['field_trc_type_value']['id'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['filters']['field_trc_type_value']['field'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['value'] = array(
    'sell' => 'sell',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'В последние 7 дней не было продаж.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $export['daily_sales'] = $view;

  $view = new view();
  $view->name = 'encashment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Расходы';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Расходы';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_enc_date' => 'field_enc_date',
    'field_enc_amount' => 'field_enc_amount',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_enc_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enc_amount' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right pull-right margin-top-38"><a href="/ru/dashboard/reports/encashment/add-new?destination=dashboard/reports/encashment" class="btn btn-success">Добавить сумму</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Данные ещё не добавлены.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Содержимое: Дата */
  $handler->display->display_options['fields']['field_enc_date']['id'] = 'field_enc_date';
  $handler->display->display_options['fields']['field_enc_date']['table'] = 'field_data_field_enc_date';
  $handler->display->display_options['fields']['field_enc_date']['field'] = 'field_enc_date';
  $handler->display->display_options['fields']['field_enc_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Сумма (в сумах) */
  $handler->display->display_options['fields']['field_enc_amount']['id'] = 'field_enc_amount';
  $handler->display->display_options['fields']['field_enc_amount']['table'] = 'field_data_field_enc_amount';
  $handler->display->display_options['fields']['field_enc_amount']['field'] = 'field_enc_amount';
  $handler->display->display_options['fields']['field_enc_amount']['label'] = 'Сумма';
  $handler->display->display_options['fields']['field_enc_amount']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_enc_amount']['alter']['text'] = '[field_enc_amount] сум';
  $handler->display->display_options['fields']['field_enc_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Тип расхода */
  $handler->display->display_options['fields']['field_enc_type']['id'] = 'field_enc_type';
  $handler->display->display_options['fields']['field_enc_type']['table'] = 'field_data_field_enc_type';
  $handler->display->display_options['fields']['field_enc_type']['field'] = 'field_enc_type';
  $handler->display->display_options['fields']['field_enc_type']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'редактировать';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'удалить';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'encashment' => 'encashment',
  );
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'От даты';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-1:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_enc_date.field_enc_date_value' => 'field_data_field_enc_date.field_enc_date_value',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'До даты';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-1:+1';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_enc_date.field_enc_date_value' => 'field_data_field_enc_date.field_enc_date_value',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/reports/encashment';

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Сумма (в сумах) */
  $handler->display->display_options['fields']['field_enc_amount']['id'] = 'field_enc_amount';
  $handler->display->display_options['fields']['field_enc_amount']['table'] = 'field_data_field_enc_amount';
  $handler->display->display_options['fields']['field_enc_amount']['field'] = 'field_enc_amount';
  $handler->display->display_options['fields']['field_enc_amount']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_enc_amount']['label'] = '';
  $handler->display->display_options['fields']['field_enc_amount']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_enc_amount']['alter']['text'] = '[field_enc_amount] сум';
  $handler->display->display_options['fields']['field_enc_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enc_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $export['encashment'] = $view;

  $view = new view();
  $view->name = 'export_csv_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Список экспортированных файлов';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Созданные файлы';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'is-imported-[field_file_is_extracted]';
  $handler->display->display_options['style_options']['columns'] = array(
    'filename' => 'filename',
    'timestamp' => 'timestamp',
    'field_file_is_extracted' => 'field_file_is_extracted',
    'filesize' => 'filesize',
    'download' => 'download',
    'delete' => 'delete',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'filename' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_is_extracted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filesize' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'download' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поле: Массовые операции: Файл */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Файл: Имя */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = 'Название файла';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Поле: Файл: Дата загрузки */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Дата создания';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['format_date_sql'] = 0;
  /* Поле: Файл: Размер */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  /* Поле: Обработчик испорчен или отсутствует */
  $handler->display->display_options['fields']['field_send_to_branch']['id'] = 'field_send_to_branch';
  $handler->display->display_options['fields']['field_send_to_branch']['table'] = 'field_data_field_send_to_branch';
  $handler->display->display_options['fields']['field_send_to_branch']['field'] = 'field_send_to_branch';
  $handler->display->display_options['fields']['field_send_to_branch']['label'] = 'Отправлен';
  $handler->display->display_options['fields']['field_send_to_branch']['empty'] = 'Нет';
  /* Поле: Файл: Ссылка на загрузку */
  $handler->display->display_options['fields']['download']['id'] = 'download';
  $handler->display->display_options['fields']['download']['table'] = 'file_managed';
  $handler->display->display_options['fields']['download']['field'] = 'download';
  $handler->display->display_options['fields']['download']['label'] = '';
  $handler->display->display_options['fields']['download']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['download']['text'] = 'скачать';
  /* Поле: Файл: Ссылка на удаление */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'file_managed';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = '';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete']['text'] = 'удалить';
  /* Поле: Файл: Ссылка */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'file_managed';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['label'] = '';
  $handler->display->display_options['fields']['link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link']['text'] = 'cчет-фактура';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[link] &nbsp; [download] &nbsp; [delete]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Файл: Дата загрузки */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Критерий фильтра: Файл: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );
  /* Критерий фильтра: Файл: Сервис (field_file_service) */
  $handler->display->display_options['filters']['field_file_service_value']['id'] = 'field_file_service_value';
  $handler->display->display_options['filters']['field_file_service_value']['table'] = 'field_data_field_file_service';
  $handler->display->display_options['filters']['field_file_service_value']['field'] = 'field_file_service_value';
  $handler->display->display_options['filters']['field_file_service_value']['value'] = array(
    'export' => 'export',
  );

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $export['export_csv_list'] = $view;

  $view = new view();
  $view->name = 'faq';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Часто задаваемые вопросы ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Часто задаваемые вопросы ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'faq-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'faq-title strong pointer';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Текст */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'faq-body hide';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faq' => 'faq',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['faq'] = $view;

  $view = new view();
  $view->name = 'get_product_last_transaction';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Get product last transaction';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Содержимое: Продукт (field_prtrc_product) */
  $handler->display->display_options['relationships']['field_prtrc_product_nid']['id'] = 'field_prtrc_product_nid';
  $handler->display->display_options['relationships']['field_prtrc_product_nid']['table'] = 'field_data_field_prtrc_product';
  $handler->display->display_options['relationships']['field_prtrc_product_nid']['field'] = 'field_prtrc_product_nid';
  $handler->display->display_options['relationships']['field_prtrc_product_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_prtrc_product_nid']['delta'] = '-1';
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_prtrc_amount']['id'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['field'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['label'] = '';
  $handler->display->display_options['fields']['field_prtrc_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prtrc_amount']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_prtrc_roz_price']['id'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['field'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['label'] = '';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prtrc_roz_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Дата обновления */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction_product' => 'transaction_product',
  );
  $export['get_product_last_transaction'] = $view;

  $view = new view();
  $view->name = 'load_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Список загруженных файлов';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Загруженные файлы';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'is-imported-[field_file_is_extracted]';
  $handler->display->display_options['style_options']['columns'] = array(
    'filename' => 'filename',
    'timestamp' => 'timestamp',
    'field_file_is_extracted' => 'field_file_is_extracted',
    'filesize' => 'filesize',
    'download' => 'download',
    'delete' => 'delete',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'filename' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_is_extracted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filesize' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'download' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p class="text-center"><br><br>
						<span class="label label-default">Файлы ещё не загружены.</span>
						<br>
						<br>
					</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Массовые операции: Файл */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Файл: Имя */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = 'Название файла';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Поле: Обработчик испорчен или отсутствует */
  $handler->display->display_options['fields']['field_received_from_server']['id'] = 'field_received_from_server';
  $handler->display->display_options['fields']['field_received_from_server']['table'] = 'field_data_field_received_from_server';
  $handler->display->display_options['fields']['field_received_from_server']['field'] = 'field_received_from_server';
  $handler->display->display_options['fields']['field_received_from_server']['label'] = 'Получен с сервера';
  $handler->display->display_options['fields']['field_received_from_server']['alter']['text'] = '<span class="glyphicon glyphicon-ok text-success"></span>';
  /* Поле: Файл: Дата загрузки */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['format_date_sql'] = 0;
  /* Поле: Файл: Извлечен */
  $handler->display->display_options['fields']['field_file_is_extracted']['id'] = 'field_file_is_extracted';
  $handler->display->display_options['fields']['field_file_is_extracted']['table'] = 'field_data_field_file_is_extracted';
  $handler->display->display_options['fields']['field_file_is_extracted']['field'] = 'field_file_is_extracted';
  $handler->display->display_options['fields']['field_file_is_extracted']['label'] = 'Импортирован';
  $handler->display->display_options['fields']['field_file_is_extracted']['type'] = 'list_key';
  /* Поле: Файл: Размер */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  /* Поле: Файл: Ссылка на загрузку */
  $handler->display->display_options['fields']['download']['id'] = 'download';
  $handler->display->display_options['fields']['download']['table'] = 'file_managed';
  $handler->display->display_options['fields']['download']['field'] = 'download';
  $handler->display->display_options['fields']['download']['label'] = '';
  $handler->display->display_options['fields']['download']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['download']['text'] = 'скачать';
  /* Поле: Файл: Ссылка на удаление */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'file_managed';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = '';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete']['text'] = 'удалить';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[download] [delete]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Файл: Дата загрузки */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Критерий фильтра: Файл: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );
  /* Критерий фильтра: Файл: Сервис (field_file_service) */
  $handler->display->display_options['filters']['field_file_service_value']['id'] = 'field_file_service_value';
  $handler->display->display_options['filters']['field_file_service_value']['table'] = 'field_data_field_file_service';
  $handler->display->display_options['filters']['field_file_service_value']['field'] = 'field_file_service_value';
  $handler->display->display_options['filters']['field_file_service_value']['value'] = array(
    'import' => 'import',
  );

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $export['load_list'] = $view;

  $view = new view();
  $view->name = 'manufacturers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Manufacturers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Производители';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right"><a href="/ru/dashboard/manufacturers/add-new?destination=dashboard/manufacturers" class="btn btn-success">Добавить новый производитель</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Производители не добавлены.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Массовые операции: Термин таксономии */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_taxonomy_term';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Поле: Термин таксономии: Ссылка на редактирование термина */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['label'] = '';
  $handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_term']['text'] = 'Редактировать';
  /* Критерий фильтра: Словарь таксономии: Машинное имя */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'manufacturers' => 'manufacturers',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/manufacturers';
  $export['manufacturers'] = $view;

  $view = new view();
  $view->name = 'package_expiring';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Срок годности истекает';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Истекающий срок годности';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'table table-striped table-hover';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_pb_product' => 'field_pb_product',
    'field_pr_amount' => 'field_pr_amount',
    'field_pr_income_date' => 'field_pr_income_date',
    'field_pr_expiry_date' => 'field_pr_expiry_date',
    'field_pr_provider' => 'field_pr_provider',
  );
  $handler->display->display_options['style_options']['default'] = 'field_pr_expiry_date';
  $handler->display->display_options['style_options']['info'] = array(
    'field_pb_product' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_amount' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_income_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_expiry_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_provider' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Таких продуктов нет.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Продукт (field_pb_product) */
  $handler->display->display_options['relationships']['field_pb_product_nid']['id'] = 'field_pb_product_nid';
  $handler->display->display_options['relationships']['field_pb_product_nid']['table'] = 'field_data_field_pb_product';
  $handler->display->display_options['relationships']['field_pb_product_nid']['field'] = 'field_pb_product_nid';
  $handler->display->display_options['relationships']['field_pb_product_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_pb_product_nid']['delta'] = '-1';
  /* Поле: Содержимое: Продукт */
  $handler->display->display_options['fields']['field_pb_product']['id'] = 'field_pb_product';
  $handler->display->display_options['fields']['field_pb_product']['table'] = 'field_data_field_pb_product';
  $handler->display->display_options['fields']['field_pb_product']['field'] = 'field_pb_product';
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_pr_amount']['id'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['field'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Дата прибытия */
  $handler->display->display_options['fields']['field_pr_income_date']['id'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['table'] = 'field_data_field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['field'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pr_income_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pr_income_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Срок годности */
  $handler->display->display_options['fields']['field_pr_expiry_date']['id'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['table'] = 'field_data_field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['field'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pr_expiry_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pr_expiry_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Поставщик */
  $handler->display->display_options['fields']['field_pr_provider']['id'] = 'field_pr_provider';
  $handler->display->display_options['fields']['field_pr_provider']['table'] = 'field_data_field_pr_provider';
  $handler->display->display_options['fields']['field_pr_provider']['field'] = 'field_pr_provider';
  $handler->display->display_options['fields']['field_pr_provider']['type'] = 'node_reference_plain';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_batch' => 'product_batch',
  );
  /* Критерий фильтра: Содержимое: Срок годности (field_pr_expiry_date) */
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['id'] = 'field_pr_expiry_date_value';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['table'] = 'field_data_field_pr_expiry_date';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['field'] = 'field_pr_expiry_date_value';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['operator_id'] = 'field_pr_expiry_date_value_op';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['label'] = 'Срок годности (меньше чем)';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['operator'] = 'field_pr_expiry_date_value_op';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['identifier'] = 'field_pr_expiry_date_value';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['default_date'] = 'now+6 month';
  /* Критерий фильтра: Содержимое: Количество (field_pr_amount) */
  $handler->display->display_options['filters']['field_pr_amount_value']['id'] = 'field_pr_amount_value';
  $handler->display->display_options['filters']['field_pr_amount_value']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['filters']['field_pr_amount_value']['field'] = 'field_pr_amount_value';
  $handler->display->display_options['filters']['field_pr_amount_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_pr_amount_value']['value']['value'] = '0';
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_pb_product_nid';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Поиск по продуктам';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/warehouse/expiring';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Подвал: Глобальный: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="text-right"><?php print l(\'Посмотреть все\', \'dashboard/warehouse/expiring\'); ?></div>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_batch' => 'product_batch',
  );
  /* Критерий фильтра: Содержимое: Срок годности (field_pr_expiry_date) */
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['id'] = 'field_pr_expiry_date_value';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['table'] = 'field_data_field_pr_expiry_date';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['field'] = 'field_pr_expiry_date_value';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['operator_id'] = 'field_pr_expiry_date_value_op';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['label'] = 'Срок годности (меньше чем)';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['operator'] = 'field_pr_expiry_date_value_op';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['identifier'] = 'field_pr_expiry_date_value';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_pr_expiry_date_value']['default_date'] = 'now+6 month';
  /* Критерий фильтра: Содержимое: Количество (field_pr_amount) */
  $handler->display->display_options['filters']['field_pr_amount_value']['id'] = 'field_pr_amount_value';
  $handler->display->display_options['filters']['field_pr_amount_value']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['filters']['field_pr_amount_value']['field'] = 'field_pr_amount_value';
  $handler->display->display_options['filters']['field_pr_amount_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_pr_amount_value']['value']['value'] = '0';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['attach_text'] = 'Экспорт на Excel-файл';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Срок-годности-истекает-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Продукт */
  $handler->display->display_options['fields']['field_pb_product']['id'] = 'field_pb_product';
  $handler->display->display_options['fields']['field_pb_product']['table'] = 'field_data_field_pb_product';
  $handler->display->display_options['fields']['field_pb_product']['field'] = 'field_pb_product';
  $handler->display->display_options['fields']['field_pb_product']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pb_product']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pb_product']['type'] = 'node_reference_plain';
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_pr_amount']['id'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['field'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Дата прибытия */
  $handler->display->display_options['fields']['field_pr_income_date']['id'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['table'] = 'field_data_field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['field'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pr_income_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pr_income_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Срок годности */
  $handler->display->display_options['fields']['field_pr_expiry_date']['id'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['table'] = 'field_data_field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['field'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pr_expiry_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pr_expiry_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['path'] = 'dashboard/warehouse/expiring/xlsx';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/warehouse/expiring';
  $handler->display->display_options['segment_size'] = '100';
  $export['package_expiring'] = $view;

  $view = new view();
  $view->name = 'prices_of_product';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'prices_of_product';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'prices_of_product';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Подвал: Глобальный: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="row"><div class="col-sm-8"><h5 class="text-warning">Пришла новая партия? Вы можете добавить новую цену и количество.</h5></div>
<div class="col-sm-4 text-right"><a class="btn btn-info" href="<?php print url(\'dashboard/warehouse/add-price\',array(\'query\'=>array(\'product\'=>arg(1)))); ?>" data-toggle="tooltip" data-placement="top" title="Переходим на новую страницу. Если вы сделали изменения на этом странице, сначала нажмите сохранить.">Добавить партию</a><p></p></div>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="row"><div class="col-sm-8"><h5 class="text-warning">Ни одна партия не добавлена.</h5></div>
<div class="col-sm-4 text-right"><a class="btn btn-info" href="<?php print url(\'dashboard/warehouse/add-price\',array(\'query\'=>array(\'product\'=>arg(1)))); ?>" data-toggle="tooltip" data-placement="top" title="Переходим на новую страницу. Если вы сделали изменения на этом странице, сначала нажмите сохранить.">Добавить партию</a><p></p></div>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_pr_amount']['id'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['field'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['label'] = 'Осталось';
  $handler->display->display_options['fields']['field_pr_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_pr_price']['id'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['table'] = 'field_data_field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['field'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['label'] = 'Цена';
  $handler->display->display_options['fields']['field_pr_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pr_price']['alter']['text'] = '[field_pr_price] сум';
  $handler->display->display_options['fields']['field_pr_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_pr_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Контекстный фильтр: Содержимое: Продукт (field_pb_product) */
  $handler->display->display_options['arguments']['field_pb_product_nid']['id'] = 'field_pb_product_nid';
  $handler->display->display_options['arguments']['field_pb_product_nid']['table'] = 'field_data_field_pb_product';
  $handler->display->display_options['arguments']['field_pb_product_nid']['field'] = 'field_pb_product_nid';
  $handler->display->display_options['arguments']['field_pb_product_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_pb_product_nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_pb_product_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_batch' => 'product_batch',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['prices_of_product'] = $view;

  $view = new view();
  $view->name = 'product_batches';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'product_batches';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'prices_of_product';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Дата прибытия */
  $handler->display->display_options['fields']['field_pr_income_date']['id'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['table'] = 'field_data_field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['field'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['label'] = '';
  $handler->display->display_options['fields']['field_pr_income_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pr_income_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_pr_income_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_pr_amount']['id'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['field'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['label'] = 'Осталось';
  $handler->display->display_options['fields']['field_pr_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_pr_price']['id'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['table'] = 'field_data_field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['field'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['label'] = 'Цена';
  $handler->display->display_options['fields']['field_pr_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pr_price']['alter']['text'] = '[field_pr_price] сум';
  $handler->display->display_options['fields']['field_pr_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_pr_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_pr_price_base']['id'] = 'field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['table'] = 'field_data_field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['field'] = 'field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['label'] = '';
  $handler->display->display_options['fields']['field_pr_price_base']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pr_price_base']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_pr_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Срок годности */
  $handler->display->display_options['fields']['field_pr_expiry_date']['id'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['table'] = 'field_data_field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['field'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['label'] = '';
  $handler->display->display_options['fields']['field_pr_expiry_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pr_expiry_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_pr_expiry_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Поставщик */
  $handler->display->display_options['fields']['field_pr_provider']['id'] = 'field_pr_provider';
  $handler->display->display_options['fields']['field_pr_provider']['table'] = 'field_data_field_pr_provider';
  $handler->display->display_options['fields']['field_pr_provider']['field'] = 'field_pr_provider';
  $handler->display->display_options['fields']['field_pr_provider']['label'] = '';
  $handler->display->display_options['fields']['field_pr_provider']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pr_provider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pr_provider']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pr_provider']['type'] = 'node_reference_nid';
  /* Поле: Содержимое: Порядковый номер */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Филиал */
  $handler->display->display_options['fields']['field_pr_branch']['id'] = 'field_pr_branch';
  $handler->display->display_options['fields']['field_pr_branch']['table'] = 'field_data_field_pr_branch';
  $handler->display->display_options['fields']['field_pr_branch']['field'] = 'field_pr_branch';
  $handler->display->display_options['fields']['field_pr_branch']['label'] = '';
  $handler->display->display_options['fields']['field_pr_branch']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pr_branch']['type'] = 'node_reference_nid';
  /* Поле: Содержимое: Накладная № */
  $handler->display->display_options['fields']['field_pr_waybill_no']['id'] = 'field_pr_waybill_no';
  $handler->display->display_options['fields']['field_pr_waybill_no']['table'] = 'field_data_field_pr_waybill_no';
  $handler->display->display_options['fields']['field_pr_waybill_no']['field'] = 'field_pr_waybill_no';
  $handler->display->display_options['fields']['field_pr_waybill_no']['type'] = 'node_reference_nid';
  $handler->display->display_options['fields']['field_pr_waybill_no']['settings'] = array(
    'alias' => 1,
    'absolute' => 0,
  );
  /* Критерий сортировки: Содержимое: Порядковый номер (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Контекстный фильтр: Содержимое: Продукт (field_pb_product) */
  $handler->display->display_options['arguments']['field_pb_product_nid']['id'] = 'field_pb_product_nid';
  $handler->display->display_options['arguments']['field_pb_product_nid']['table'] = 'field_data_field_pb_product';
  $handler->display->display_options['arguments']['field_pb_product_nid']['field'] = 'field_pb_product_nid';
  $handler->display->display_options['arguments']['field_pb_product_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_pb_product_nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_pb_product_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pb_product_nid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_batch' => 'product_batch',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['product_batches'] = $view;

  $view = new view();
  $view->name = 'products_empty_stock';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Не осталось на складе';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Нет в наличии';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Таких продуктов нет.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Продукт (field_pb_product) - реверс */
  $handler->display->display_options['relationships']['reverse_field_pb_product_node']['id'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['relationships']['reverse_field_pb_product_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_pb_product_node']['field'] = 'reverse_field_pb_product_node';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название продукта';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'OR',
  );
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['filters']['type']['group'] = 3;
  /* Критерий фильтра: SUM(Содержимое: Количество (field_pr_amount)) */
  $handler->display->display_options['filters']['field_pr_amount_value']['id'] = 'field_pr_amount_value';
  $handler->display->display_options['filters']['field_pr_amount_value']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['filters']['field_pr_amount_value']['field'] = 'field_pr_amount_value';
  $handler->display->display_options['filters']['field_pr_amount_value']['relationship'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['filters']['field_pr_amount_value']['group_type'] = 'sum';
  $handler->display->display_options['filters']['field_pr_amount_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_pr_amount_value']['value']['value'] = '0';
  $handler->display->display_options['filters']['field_pr_amount_value']['group'] = 1;
  /* Критерий фильтра: SUM(Содержимое: Количество (field_pr_amount)) */
  $handler->display->display_options['filters']['field_pr_amount_value_1']['id'] = 'field_pr_amount_value_1';
  $handler->display->display_options['filters']['field_pr_amount_value_1']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['filters']['field_pr_amount_value_1']['field'] = 'field_pr_amount_value';
  $handler->display->display_options['filters']['field_pr_amount_value_1']['relationship'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['filters']['field_pr_amount_value_1']['group_type'] = 'sum';
  $handler->display->display_options['filters']['field_pr_amount_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_pr_amount_value_1']['group'] = 1;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Подвал: Глобальный: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="text-right"><?php print l(\'Посмотреть все\', \'dashboard/warehouse/no-stock\'); ?></div>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';

  /* Display: Страница */
  $handler = $view->new_display('page', 'Страница', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['path'] = 'dashboard/warehouse/no-stock';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['attach_text'] = 'Экспорт на Excel-файл';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Нет-в-наличии-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'dashboard/warehouse/no-stock/xlsx';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'block' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/warehouse/no-stock';
  $handler->display->display_options['segment_size'] = '100';
  $export['products_empty_stock'] = $view;

  $view = new view();
  $view->name = 'products_list_of_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'products list of user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );

  /* Display: References */
  $handler = $view->new_display('references', 'References', 'references_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'references_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['products_list_of_user'] = $view;

  $view = new view();
  $view->name = 'profile_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Profile block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Поле: Профиль: Рисунок профиля */
  $handler->display->display_options['fields']['field_apteka_image']['id'] = 'field_apteka_image';
  $handler->display->display_options['fields']['field_apteka_image']['table'] = 'field_data_field_apteka_image';
  $handler->display->display_options['fields']['field_apteka_image']['field'] = 'field_apteka_image';
  $handler->display->display_options['fields']['field_apteka_image']['label'] = '';
  $handler->display->display_options['fields']['field_apteka_image']['element_class'] = 'profile-photo';
  $handler->display->display_options['fields']['field_apteka_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apteka_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_apteka_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_apteka_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Поле: Профиль: Название магазина */
  $handler->display->display_options['fields']['field_apteka_name']['id'] = 'field_apteka_name';
  $handler->display->display_options['fields']['field_apteka_name']['table'] = 'field_data_field_apteka_name';
  $handler->display->display_options['fields']['field_apteka_name']['field'] = 'field_apteka_name';
  $handler->display->display_options['fields']['field_apteka_name']['label'] = '';
  $handler->display->display_options['fields']['field_apteka_name']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_apteka_name']['element_class'] = 'profile-name';
  $handler->display->display_options['fields']['field_apteka_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apteka_name']['element_default_classes'] = FALSE;
  /* Поле: Профиль: Обложка */
  $handler->display->display_options['fields']['field_appteca_cover']['id'] = 'field_appteca_cover';
  $handler->display->display_options['fields']['field_appteca_cover']['table'] = 'field_data_field_appteca_cover';
  $handler->display->display_options['fields']['field_appteca_cover']['field'] = 'field_appteca_cover';
  $handler->display->display_options['fields']['field_appteca_cover']['label'] = '';
  $handler->display->display_options['fields']['field_appteca_cover']['element_type'] = '0';
  $handler->display->display_options['fields']['field_appteca_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_appteca_cover']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_appteca_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_appteca_cover']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_appteca_cover']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Контекстный фильтр: Профиль: Пользователь uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['user']['default_argument_options']['code'] = 'global $user;
if (in_array(\'manager\', $user->roles)) {
return $user->uid;
} else { 
$parent_manager = user_get_parent_manager($user);
if ($parent_manager) {
return $parent_manager->uid;
}
}';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Профиль: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'main' => 'main',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['profile_block'] = $view;

  $view = new view();
  $view->name = 'providers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Поставщики';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Поставщики';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'field_provider_name' => 'field_provider_name',
    'field_provider_phone' => 'field_provider_phone',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_provider_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_provider_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right pull-right margin-top-38"><a href="/ru/dashboard/providers/add-new?destination=dashboard/providers" class="btn btn-success">Добавить нового поставщика</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Поставщики ещё не добавлены.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Поставщик (field_dg_provider) - реверс */
  $handler->display->display_options['relationships']['reverse_field_dg_provider_node']['id'] = 'reverse_field_dg_provider_node';
  $handler->display->display_options['relationships']['reverse_field_dg_provider_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_dg_provider_node']['field'] = 'reverse_field_dg_provider_node';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить провайдера',
    ),
  );
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Контактное лицо */
  $handler->display->display_options['fields']['field_provider_name']['id'] = 'field_provider_name';
  $handler->display->display_options['fields']['field_provider_name']['table'] = 'field_data_field_provider_name';
  $handler->display->display_options['fields']['field_provider_name']['field'] = 'field_provider_name';
  /* Поле: Содержимое: Номер телефона */
  $handler->display->display_options['fields']['field_provider_phone']['id'] = 'field_provider_phone';
  $handler->display->display_options['fields']['field_provider_phone']['table'] = 'field_data_field_provider_phone';
  $handler->display->display_options['fields']['field_provider_phone']['field'] = 'field_provider_phone';
  /* Поле: Содержимое: Email */
  $handler->display->display_options['fields']['field_provider_email']['id'] = 'field_provider_email';
  $handler->display->display_options['fields']['field_provider_email']['table'] = 'field_data_field_provider_email';
  $handler->display->display_options['fields']['field_provider_email']['field'] = 'field_provider_email';
  $handler->display->display_options['fields']['field_provider_email']['type'] = 'email_plain';
  /* Поле: COUNT(Содержимое: Заголовок) */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_dg_provider_node';
  $handler->display->display_options['fields']['title_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['title_1']['label'] = 'Договоры';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<span class="glyphicon glyphicon-edit" data-toggle="tooltip" data-placement="top" title="Редактировать"></span>';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = '<span class="glyphicon glyphicon-remove-circle text-danger" data-toggle="tooltip" data-placement="top" title="Удалить"></span>';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/ru/dashboard/providers/contracts/add-new?provider_nid=[nid]"><span class="glyphicon glyphicon-list-alt text-primary" data-toggle="tooltip" data-placement="top" title="Добавить договор"></span></a>&nbsp; 
[edit_node]&nbsp; 
[delete_node]&nbsp;';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'h4 text-right';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'provider' => 'provider',
  );
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Название поставщика';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/providers';
  $export['providers'] = $view;

  $view = new view();
  $view->name = 'providers_as_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Поставщики (список)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'provider' => 'provider',
  );
  $export['providers_as_list'] = $view;

  $view = new view();
  $view->name = 'reports_date';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Отчёт По дате';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Отчёт по дате';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'nid' => 'nid',
    'field_trc_qty' => 'field_trc_qty',
    'field_trc_price' => 'field_trc_price',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br/><br/><br/><br/>
  <span class="label label-default"> Нет данных для отображения.</span>
<br/><br/><br/><br/>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата продаж';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<a href="/ru/dashboard/reports/hours?date_filter_from%5Bvalue%5D%5Bdate%5D=[created]" data-toggle="tooltip" data-placement="top" title="Нажмите чтобы посмотреть отчёт по часам (Откроется в новом окне)" target="_blank">[created]</a>';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во транзакций';
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Продажи';
  $handler->display->display_options['fields']['field_trc_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price']['alter']['text'] = '[field_trc_price] сум';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. продажи';
  $handler->display->display_options['fields']['field_trc_price_base']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$rozn = 
	isset($data->field_data_field_trc_price_field_trc_price_value)
	? $data->field_data_field_trc_price_field_trc_price_value
	: 0;

$opt = 
	isset($data->field_data_field_trc_price_base_field_trc_price_base_value)
	? $data->field_data_field_trc_price_base_field_trc_price_base_value
	: 0;

$profit = $rozn - $opt;
$profit = max($profit, 0);
return $profit;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Критерий сортировки: MAX(Содержимое: Дата публикации) */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['group_type'] = 'max';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  /* Критерий фильтра: Содержимое: Тип транзакции (field_trc_type) */
  $handler->display->display_options['filters']['field_trc_type_value']['id'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['filters']['field_trc_type_value']['field'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['value'] = array(
    'sell' => 'sell',
  );
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'От даты';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_from';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'До даты';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['group_info']['label'] = 'Дата (node)';
  $handler->display->display_options['filters']['date_filter_1']['group_info']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['date_filter_1']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Критерий фильтра: Содержимое: Тип оплаты (field_trc_payment_type) */
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['id'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['field'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator_id'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['label'] = 'Тип оплаты';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['identifier'] = 'payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['vocabulary'] = 'payment_type';
  /* Критерий фильтра: Содержимое: Продукт транзакции (field_trc_product) */
  $handler->display->display_options['filters']['field_trc_product_nid']['id'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['field'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator_id'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['label'] = 'Продукт';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['identifier'] = 'trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Клиент (field_trc_client) */
  $handler->display->display_options['filters']['field_trc_client_nid']['id'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['table'] = 'field_data_field_trc_client';
  $handler->display->display_options['filters']['field_trc_client_nid']['field'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator_id'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['label'] = 'Клиент';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['identifier'] = 'client';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/reports/date';
  $handler->display->display_options['menu']['title'] = 'По дате';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Отчёты';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-manager-menu';

  /* Display: Chart */
  $handler = $view->new_display('attachment', 'Chart', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'img-thumbnail';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'area';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'created';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_trc_price' => 'field_trc_price',
    'php' => 'php',
    'title' => 0,
    'created' => 0,
    'nid' => 0,
    'field_trc_qty' => 0,
    'field_trc_price_base' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#1aadce',
    'created' => '#2f7ed8',
    'nid' => '#0d233a',
    'field_trc_qty' => '#8bbc21',
    'field_trc_price' => '#1aadce',
    'field_trc_price_base' => '#492970',
    'php' => '#1fe03c',
  );
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
  $handler->display->display_options['style_options']['yaxis_suffix'] = ' сум';
  $handler->display->display_options['style_options']['yaxis_decimal_count'] = '0';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: MAX(Содержимое: Дата публикации) */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['group_type'] = 'max';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Дата публикации';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Отчет-по-дате-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: STDDEV_POP(Содержимое: Заголовок) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['title']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['title']['label'] = 'Продукт';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата продаж';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<a href="/ru/dashboard/reports/hours?date_filter_from%5Bvalue%5D%5Bdate%5D=[created]" data-toggle="tooltip" data-placement="top" title="Нажмите чтобы посмотреть отчёт по часам (Откроется в новом окне)" target="_blank">[created]</a>';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во транзакций';
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Продажи';
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. продажи';
  $handler->display->display_options['fields']['field_trc_price_base']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['path'] = 'dashboard/reports/date/xlsx';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/reports/date';
  $handler->display->display_options['segment_size'] = '100';
  $export['reports_date'] = $view;

  $view = new view();
  $view->name = 'reports_hours';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Отчёт По часам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Отчёт по часам';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'nid' => 'nid',
    'field_trc_qty' => 'field_trc_qty',
    'field_trc_price' => 'field_trc_price',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br/><br/><br/><br/>
  <span class="label label-default"> Нет данных для отображения.</span>
<br/><br/><br/><br/>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Время продаж';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'H';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во транзакций';
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Продажи';
  $handler->display->display_options['fields']['field_trc_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price']['alter']['text'] = '[field_trc_price] сум';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. продажи';
  $handler->display->display_options['fields']['field_trc_price_base']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$rozn = 
	isset($data->field_data_field_trc_price_field_trc_price_value)
	? $data->field_data_field_trc_price_field_trc_price_value
	: 0;

$opt = 
	isset($data->field_data_field_trc_price_base_field_trc_price_base_value)
	? $data->field_data_field_trc_price_base_field_trc_price_base_value
	: 0;

$profit = $rozn - $opt;
$profit = max($profit, 0);
return $profit;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Критерий сортировки: MAX(Содержимое: Дата публикации) */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['group_type'] = 'max';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Тип транзакции (field_trc_type) */
  $handler->display->display_options['filters']['field_trc_type_value']['id'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['filters']['field_trc_type_value']['field'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['value'] = array(
    'sell' => 'sell',
  );
  $handler->display->display_options['filters']['field_trc_type_value']['group'] = 1;
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Дата продаж';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_from';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Содержимое: Тип оплаты (field_trc_payment_type) */
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['id'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['field'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator_id'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['label'] = 'Тип оплаты';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['identifier'] = 'payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['vocabulary'] = 'payment_type';
  /* Критерий фильтра: Содержимое: Клиент (field_trc_client) */
  $handler->display->display_options['filters']['field_trc_client_nid']['id'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['table'] = 'field_data_field_trc_client';
  $handler->display->display_options['filters']['field_trc_client_nid']['field'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator_id'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['label'] = 'Клиент';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['identifier'] = 'client';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Продукт транзакции (field_trc_product) */
  $handler->display->display_options['filters']['field_trc_product_nid']['id'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['field'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator_id'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['label'] = 'Продукт';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['identifier'] = 'trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/reports/hours';
  $handler->display->display_options['menu']['title'] = 'По часам';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Отчёты';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-manager-menu';

  /* Display: Chart */
  $handler = $view->new_display('attachment', 'Chart', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'img-thumbnail';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'created';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_trc_price' => 'field_trc_price',
    'php' => 'php',
    'title' => 0,
    'created' => 0,
    'nid' => 0,
    'field_trc_qty' => 0,
    'field_trc_price_base' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#1aadce',
    'created' => '#2f7ed8',
    'nid' => '#0d233a',
    'field_trc_qty' => '#8bbc21',
    'field_trc_price' => '#1aadce',
    'field_trc_price_base' => '#492970',
    'php' => '#1fe03c',
  );
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '600';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
  $handler->display->display_options['style_options']['yaxis_suffix'] = ' сум';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: MAX(Содержимое: Дата публикации) */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['group_type'] = 'max';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Дата публикации';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;
  $export['reports_hours'] = $view;

  $view = new view();
  $view->name = 'reports_manufacturers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Отчёт По производителям';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Отчёт по производителям';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_md_manufacturer' => 'field_md_manufacturer',
    'field_trc_qty' => 'field_trc_qty',
    'field_trc_price' => 'field_trc_price',
    'field_trc_price_base' => 'field_trc_price_base',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_md_manufacturer' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price_base' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Связь: Содержимое: Продукт транзакции (field_trc_product) */
  $handler->display->display_options['relationships']['field_trc_product_nid']['id'] = 'field_trc_product_nid';
  $handler->display->display_options['relationships']['field_trc_product_nid']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['relationships']['field_trc_product_nid']['field'] = 'field_trc_product_nid';
  $handler->display->display_options['relationships']['field_trc_product_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_trc_product_nid']['delta'] = '0';
  /* Связь: Обработчик испорчен или отсутствует */
  $handler->display->display_options['relationships']['field_md_manufacturer_tid']['id'] = 'field_md_manufacturer_tid';
  $handler->display->display_options['relationships']['field_md_manufacturer_tid']['table'] = 'field_data_field_md_manufacturer';
  $handler->display->display_options['relationships']['field_md_manufacturer_tid']['field'] = 'field_md_manufacturer_tid';
  $handler->display->display_options['relationships']['field_md_manufacturer_tid']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['relationships']['field_md_manufacturer_tid']['label'] = 'Term field_md_manufacturer';
  $handler->display->display_options['relationships']['field_md_manufacturer_tid']['required'] = TRUE;
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_md_manufacturer_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Производители';
  /* Поле: Обработчик испорчен или отсутствует */
  $handler->display->display_options['fields']['field_trc_qty']['id'] = 'field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['table'] = 'field_data_field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['field'] = 'field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_qty']['label'] = 'Продуктов продано';
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. всего';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. всего';
  $handler->display->display_options['fields']['field_trc_price_base']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$roz = $data->field_data_field_trc_price_field_trc_price_value;
$opt = $data->field_data_field_trc_price_base_field_trc_price_base_value;
$prib = $roz - $opt;
return $prib;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Критерий сортировки: SUM(Содержимое: Розничная цена (field_trc_price)) */
  $handler->display->display_options['sorts']['field_trc_price_value']['id'] = 'field_trc_price_value';
  $handler->display->display_options['sorts']['field_trc_price_value']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['sorts']['field_trc_price_value']['field'] = 'field_trc_price_value';
  $handler->display->display_options['sorts']['field_trc_price_value']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['field_trc_price_value']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['code'] = 'return customizer_manager_user_context_filter();';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['uid']['validate_options']['code'] = 'return customizer_manager_user_context_filter_validate($argument);';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Тип транзакции (field_trc_type) */
  $handler->display->display_options['filters']['field_trc_type_value']['id'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['filters']['field_trc_type_value']['field'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['value'] = array(
    'sell' => 'sell',
  );
  $handler->display->display_options['filters']['field_trc_type_value']['group'] = 1;
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'От Даты';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_from';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'До Даты';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Критерий фильтра: Термин таксономии: Имя */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_md_manufacturer_tid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Производитель';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'manufacturer';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['name']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_field'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_dependent'] = 0;
  /* Критерий фильтра: Содержимое: Тип оплаты (field_trc_payment_type) */
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['id'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['field'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator_id'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['label'] = 'Тип оплаты';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['identifier'] = 'payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['vocabulary'] = 'payment_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br/><br/><br/><br/>
  <span class="label label-default"> Нет данных для отображения.</span>
<br/><br/><br/><br/>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'dashboard/reports/manufacturers';
  $handler->display->display_options['menu']['title'] = 'По производителям';
  $handler->display->display_options['menu']['weight'] = '30';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Chart */
  $handler = $view->new_display('attachment', 'Chart', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'img-thumbnail';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'name';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_trc_price' => 'field_trc_price',
    'name' => 0,
    'field_trc_qty' => 0,
    'field_trc_price_base' => 0,
    'php' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'name' => '#2f7ed8',
    'field_trc_qty' => '#0d233a',
    'field_trc_price' => '#8bbc21',
    'field_trc_price_base' => '#910000',
    'php' => '#1aadce',
  );
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br><br><br><br>
  <span class="label label-default"> Нет данных для отображения.</span>
<br><br><br><br>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_md_manufacturer_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Производители';
  /* Поле: Обработчик испорчен или отсутствует */
  $handler->display->display_options['fields']['field_trc_qty']['id'] = 'field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['table'] = 'field_data_field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['field'] = 'field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_qty']['label'] = 'Продуктов продано';
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. всего';
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. всего';
  $handler->display->display_options['fields']['field_trc_price_base']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$roz = $data->field_data_field_trc_price_field_trc_price_value;
$opt = $data->field_data_field_trc_price_base_field_trc_price_base_value;
$prib = $roz - $opt;
return $prib;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;
  $export['reports_manufacturers'] = $view;

  $view = new view();
  $view->name = 'reports_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Отчёт По продуктам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Отчёт по продуктам';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_md_up_barcode' => 'field_md_up_barcode',
    'field_trc_qty' => 'field_trc_qty',
    'field_trc_price' => 'field_trc_price',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_md_up_barcode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br/><br/><br/><br/>
  <span class="label label-default"> Нет данных для отображения.</span>
<br/><br/><br/><br/>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Продукт транзакции (field_trc_product) - реверс */
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['id'] = 'reverse_field_trc_product_node';
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['field'] = 'reverse_field_trc_product_node';
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['required'] = TRUE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Штрих-код */
  $handler->display->display_options['fields']['field_prtrc_barcode']['id'] = 'field_prtrc_barcode';
  $handler->display->display_options['fields']['field_prtrc_barcode']['table'] = 'field_data_field_prtrc_barcode';
  $handler->display->display_options['fields']['field_prtrc_barcode']['field'] = 'field_prtrc_barcode';
  $handler->display->display_options['fields']['field_prtrc_barcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_prtrc_opt_price']['id'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['table'] = 'field_data_field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['field'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_prtrc_roz_price']['id'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['field'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$rozn = 
	isset($data->field_data_field_prtrc_roz_price_field_prtrc_roz_price_value)
	?$data->field_data_field_prtrc_roz_price_field_prtrc_roz_price_value
	: 0;

$opt = 
	isset($data->field_data_field_prtrc_opt_price_field_prtrc_opt_price_value)
	? $data->field_data_field_prtrc_opt_price_field_prtrc_opt_price_value
	: 0;

$profit = $rozn - $opt;
$profit = max($profit, 0);
return $profit;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Критерий сортировки: SUM(Содержимое: Розничная цена (field_prtrc_roz_price)) */
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['id'] = 'field_prtrc_roz_price_value';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['field'] = 'field_prtrc_roz_price_value';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction_product' => 'transaction_product',
  );
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'От Даты';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_from';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'До Даты';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Продукт';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'trc_product';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Критерий фильтра: Содержимое: Тип оплаты (field_trc_payment_type) */
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['id'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['field'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['relationship'] = 'reverse_field_trc_product_node';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator_id'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['label'] = 'Тип оплаты';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['identifier'] = 'payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['vocabulary'] = 'payment_type';
  /* Критерий фильтра: Содержимое: Поставщик (field_prtrc_provider_title) */
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['id'] = 'field_prtrc_provider_title_value';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['table'] = 'field_data_field_prtrc_provider_title';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['field'] = 'field_prtrc_provider_title_value';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['operator_id'] = 'field_prtrc_provider_title_value_op';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['label'] = 'Поставщик';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['operator'] = 'field_prtrc_provider_title_value_op';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['identifier'] = 'provider';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_dependent'] = 0;
  /* Критерий фильтра: Содержимое: Количество (field_prtrc_amount) */
  $handler->display->display_options['filters']['field_prtrc_amount_value']['id'] = 'field_prtrc_amount_value';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['field'] = 'field_prtrc_amount_value';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['value']['value'] = '0';
  /* Критерий фильтра: Содержимое: Клиент (field_trc_client) */
  $handler->display->display_options['filters']['field_trc_client_nid']['id'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['table'] = 'field_data_field_trc_client';
  $handler->display->display_options['filters']['field_trc_client_nid']['field'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['relationship'] = 'reverse_field_trc_product_node';
  $handler->display->display_options['filters']['field_trc_client_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator_id'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['label'] = 'Клиент';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['identifier'] = 'client';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Штрих-код */
  $handler->display->display_options['fields']['field_prtrc_barcode']['id'] = 'field_prtrc_barcode';
  $handler->display->display_options['fields']['field_prtrc_barcode']['table'] = 'field_data_field_prtrc_barcode';
  $handler->display->display_options['fields']['field_prtrc_barcode']['field'] = 'field_prtrc_barcode';
  $handler->display->display_options['fields']['field_prtrc_barcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_prtrc_opt_price']['id'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['table'] = 'field_data_field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['field'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_prtrc_opt_price']['alter']['text'] = '[field_prtrc_opt_price] сум';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_prtrc_roz_price']['id'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['field'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_prtrc_roz_price']['alter']['text'] = '[field_prtrc_roz_price] сум';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$rozn = 
	isset($data->field_data_field_prtrc_roz_price_field_prtrc_roz_price_value)
	?$data->field_data_field_prtrc_roz_price_field_prtrc_roz_price_value
	: 0;

$opt = 
	isset($data->field_data_field_prtrc_opt_price_field_prtrc_opt_price_value)
	? $data->field_data_field_prtrc_opt_price_field_prtrc_opt_price_value
	: 0;

$profit = $rozn - $opt;
$profit = max($profit, 0);
return $profit;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['path'] = 'dashboard/reports/products';
  $handler->display->display_options['menu']['title'] = 'По продуктам';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Chart */
  $handler = $view->new_display('attachment', 'Chart', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'img-thumbnail';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'title';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_prtrc_roz_price' => 'field_prtrc_roz_price',
    'php' => 'php',
    'title' => 0,
    'field_md_up_barcode' => 0,
    'field_prtrc_opt_price' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#2f7ed8',
    'field_md_up_barcode' => '#0d233a',
    'field_prtrc_opt_price' => '#8bbc21',
    'field_prtrc_roz_price' => '#0080c0',
    'php' => '#1fe03c',
  );
  $handler->display->display_options['style_options']['legend_position'] = 'top';
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
  $handler->display->display_options['style_options']['yaxis_suffix'] = ' сум';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: SUM(Содержимое: Розничная цена (field_prtrc_roz_price)) */
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['id'] = 'field_prtrc_roz_price_value';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['field'] = 'field_prtrc_roz_price_value';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['field_prtrc_roz_price_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Отчет-по-продуктам-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Штрих-код */
  $handler->display->display_options['fields']['field_md_up_barcode']['id'] = 'field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['table'] = 'field_data_field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['field'] = 'field_md_up_barcode';
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_prtrc_opt_price']['id'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['table'] = 'field_data_field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['field'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_prtrc_roz_price']['id'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['field'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['path'] = 'dashboard/reports/products/xlsx';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/reports/products';
  $handler->display->display_options['segment_size'] = '100';
  $export['reports_products'] = $view;

  $view = new view();
  $view->name = 'reports_provider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Отчёт По поставщикам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Отчёт по поставщикам';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'uid' => 'uid',
    'nid' => 'nid',
    'field_trc_qty' => 'field_trc_qty',
    'field_trc_price' => 'field_trc_price',
    'field_trc_price_base' => 'field_trc_price_base',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price_base' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br/><br/><br/><br/>
  <span class="label label-default"> Нет данных для отображения.</span>
<br/><br/><br/><br/>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Продукт транзакции (field_trc_product) */
  $handler->display->display_options['relationships']['field_trc_product_nid']['id'] = 'field_trc_product_nid';
  $handler->display->display_options['relationships']['field_trc_product_nid']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['relationships']['field_trc_product_nid']['field'] = 'field_trc_product_nid';
  $handler->display->display_options['relationships']['field_trc_product_nid']['delta'] = '0';
  /* Поле: STDDEV_POP(Содержимое: Заголовок) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['title']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Поставщик */
  $handler->display->display_options['fields']['field_prtrc_provider_title']['id'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['table'] = 'field_data_field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['field'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['group_columns'] = array(
    'bundle' => 'bundle',
    'value' => 'value',
  );
  $handler->display->display_options['fields']['field_prtrc_provider_title']['delta_offset'] = '0';
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во транзакций';
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. всего';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. всего';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$roz = $data->field_data_field_trc_price_field_trc_price_value;
$opt = $data->field_data_field_trc_price_base_field_trc_price_base_value;
$prib = $roz - $opt;
return $prib;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['code'] = 'return customizer_manager_user_context_filter();';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['uid']['validate_options']['code'] = 'return customizer_manager_user_context_filter_validate($argument);';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  /* Критерий фильтра: Содержимое: Тип транзакции (field_trc_type) */
  $handler->display->display_options['filters']['field_trc_type_value']['id'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['filters']['field_trc_type_value']['field'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['value'] = array(
    'sell' => 'sell',
  );
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'От Даты';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_from';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'До Даты';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Продукт';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'product_title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Критерий фильтра: Содержимое: Тип оплаты (field_trc_payment_type) */
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['id'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['field'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator_id'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['label'] = 'Тип оплаты';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['identifier'] = 'payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['vocabulary'] = 'payment_type';
  /* Критерий фильтра: Содержимое: Поставщик (field_prtrc_provider_title) */
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['id'] = 'field_prtrc_provider_title_value';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['table'] = 'field_data_field_prtrc_provider_title';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['field'] = 'field_prtrc_provider_title_value';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['operator_id'] = 'field_prtrc_provider_title_value_op';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['label'] = 'Поставщик';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['operator'] = 'field_prtrc_provider_title_value_op';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['identifier'] = 'provider';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_field'] = 'field_prtrc_provider_title';
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_prtrc_provider_title_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/reports/providers';
  $handler->display->display_options['menu']['title'] = 'По продавцам';
  $handler->display->display_options['menu']['weight'] = '40';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Отчёты';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-manager-menu';

  /* Display: Chart */
  $handler = $view->new_display('attachment', 'Chart', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'img-thumbnail';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'field_prtrc_provider_title';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_trc_price' => 'field_trc_price',
    'php' => 'php',
    'title' => 0,
    'field_prtrc_provider_title' => 0,
    'nid' => 0,
    'field_trc_price_base' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#2f7ed8',
    'field_prtrc_provider_title' => '#0d233a',
    'nid' => '#910000',
    'field_trc_price_base' => '#f28f43',
    'field_trc_price' => '#1aadce',
    'php' => '#1fe03c',
  );
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
  $handler->display->display_options['style_options']['yaxis_suffix'] = ' сум';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Отчет-по-поставщикам-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: STDDEV_POP(Содержимое: Заголовок) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['title']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Поставщик */
  $handler->display->display_options['fields']['field_prtrc_provider_title']['id'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['table'] = 'field_data_field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['field'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['group_columns'] = array(
    'bundle' => 'bundle',
    'value' => 'value',
  );
  $handler->display->display_options['fields']['field_prtrc_provider_title']['delta_offset'] = '0';
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во транзакций';
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. всего';
  $handler->display->display_options['fields']['field_trc_price_base']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. всего';
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['path'] = 'dashboard/reports/providers/xlsx';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/reports/providers';
  $handler->display->display_options['segment_size'] = '100';
  $export['reports_provider'] = $view;

  $view = new view();
  $view->name = 'reports_sellers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Отчёт По продавцам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Отчёт по продавцам';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'uid' => 'uid',
    'nid' => 'nid',
    'field_trc_qty' => 'field_trc_qty',
    'field_trc_price' => 'field_trc_price',
    'field_trc_price_base' => 'field_trc_price_base',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price_base' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br/><br/><br/><br/>
  <span class="label label-default"> Нет данных для отображения.</span>
<br/><br/><br/><br/>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Поле: Пользователь: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: UID Автора */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Продавец';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Продавец';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return $data->node_uid;';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
echo \'<a href="\'.url(\'dashboard/reports\', array(\'query\' => array(\'seller_select\' =>  $data->node_uid))).\'" data-toggle="tooltip" data-placement="top" title="Нажмите, чтобы посмотреть транзакции продавца (Откроется в новом окне)" target="_blank">\' . check_plain($row->name) . \'</a>\';

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во транзакций';
  /* Поле: SUM(Содержимое: Розничная цена) */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. всего';
  $handler->display->display_options['fields']['field_trc_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price']['alter']['text'] = '[field_trc_price] сум';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Оптовая цена) */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. всего';
  $handler->display->display_options['fields']['field_trc_price_base']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_base']['alter']['text'] = '[field_trc_price_base] сум';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$roz = $data->field_data_field_trc_price_field_trc_price_value;
$opt = $data->field_data_field_trc_price_base_field_trc_price_base_value;
$prib = $roz - $opt;
return $prib;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo number_format($value, 0, \'.\', \' \') . \' сум\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['code'] = 'return customizer_manager_user_context_filter();';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  /* Критерий фильтра: Содержимое: Тип транзакции (field_trc_type) */
  $handler->display->display_options['filters']['field_trc_type_value']['id'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['filters']['field_trc_type_value']['field'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['value'] = array(
    'sell' => 'sell',
  );
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'От Даты';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_from';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'До Даты';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Критерий фильтра: Содержимое: Тип оплаты (field_trc_payment_type) */
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['id'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['field'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator_id'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['label'] = 'Тип оплаты';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['identifier'] = 'payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['vocabulary'] = 'payment_type';
  /* Критерий фильтра: Содержимое: Продукт транзакции (field_trc_product) */
  $handler->display->display_options['filters']['field_trc_product_nid']['id'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['field'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator_id'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['label'] = 'Продукт';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['identifier'] = 'trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: UID Автора */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'UID Автора';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Клиент (field_trc_client) */
  $handler->display->display_options['filters']['field_trc_client_nid']['id'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['table'] = 'field_data_field_trc_client';
  $handler->display->display_options['filters']['field_trc_client_nid']['field'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator_id'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['label'] = 'Клиент';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['identifier'] = 'client';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/reports/sellers';
  $handler->display->display_options['menu']['title'] = 'По продавцам';
  $handler->display->display_options['menu']['weight'] = '40';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Отчёты';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-manager-menu';

  /* Display: Chart */
  $handler = $view->new_display('attachment', 'Chart', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'img-thumbnail';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'php_1';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'php_1' => 'php_1',
    'field_trc_price' => 'field_trc_price',
    'php' => 'php',
    'title' => 0,
    'uid' => 0,
    'nid' => 0,
    'field_trc_qty' => 0,
    'field_trc_price_base' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#2f7ed8',
    'uid' => '#0d233a',
    'php_1' => '#8bbc21',
    'nid' => '#910000',
    'field_trc_qty' => '#1aadce',
    'field_trc_price' => '#1aadce',
    'field_trc_price_base' => '#f28f43',
    'php' => '#1fe03c',
  );
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
  $handler->display->display_options['style_options']['yaxis_suffix'] = ' сум';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Отчет-по-продавцам-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'dashboard/reports/sellers/xlsx';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/reports/sellers';
  $handler->display->display_options['segment_size'] = '100';
  $export['reports_sellers'] = $view;

  $view = new view();
  $view->name = 'reports_transactions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Транзакции';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Все транзакции';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_trc_product_title' => 'field_trc_product_title',
    'title' => 'title',
    'uid' => 'uid',
    'php' => 'php',
    'created' => 'created',
    'field_trc_type' => 'field_trc_type',
    'field_trc_price_base' => 'field_trc_price_base',
    'field_trc_price' => 'field_trc_price',
    'field_trc_qty' => 'field_trc_qty',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'field_trc_product_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price_base' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="text-center"><br/><br/><br/><br/>
  <span class="label label-default"> Нет данных для отображения.</span>
<br/><br/><br/><br/>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Продукт';
  $handler->display->display_options['fields']['title']['empty'] = '[field_trc_product_title] <span class="label label-warning">продукт удалён</span>';
  /* Поле: Содержимое: UID Автора */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'От Даты';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_from';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Критерий фильтра: Дата: Дата (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'До Даты';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Критерий фильтра: Содержимое: Тип транзакции (field_trc_type) */
  $handler->display->display_options['filters']['field_trc_type_value']['id'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['filters']['field_trc_type_value']['field'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_trc_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_type_value']['expose']['operator_id'] = 'field_trc_type_value_op';
  $handler->display->display_options['filters']['field_trc_type_value']['expose']['label'] = 'Тип транзакции';
  $handler->display->display_options['filters']['field_trc_type_value']['expose']['operator'] = 'field_trc_type_value_op';
  $handler->display->display_options['filters']['field_trc_type_value']['expose']['identifier'] = 'field_trc_type_value';
  $handler->display->display_options['filters']['field_trc_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Seller UID (select list) */
  $handler->display->display_options['filters']['seller_select']['id'] = 'seller_select';
  $handler->display->display_options['filters']['seller_select']['table'] = 'node';
  $handler->display->display_options['filters']['seller_select']['field'] = 'seller_select';
  $handler->display->display_options['filters']['seller_select']['group'] = 1;
  $handler->display->display_options['filters']['seller_select']['exposed'] = TRUE;
  $handler->display->display_options['filters']['seller_select']['expose']['operator_id'] = 'seller_select_op';
  $handler->display->display_options['filters']['seller_select']['expose']['label'] = 'Автор транзакции';
  $handler->display->display_options['filters']['seller_select']['expose']['operator'] = 'seller_select_op';
  $handler->display->display_options['filters']['seller_select']['expose']['identifier'] = 'seller_select';
  $handler->display->display_options['filters']['seller_select']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Тип оплаты (field_trc_payment_type) */
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['id'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['field'] = 'field_trc_payment_type_tid';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator_id'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['label'] = 'Тип оплаты';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['operator'] = 'field_trc_payment_type_tid_op';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['identifier'] = 'payment_type';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trc_payment_type_tid']['vocabulary'] = 'payment_type';
  /* Критерий фильтра: Содержимое: Чек № (field_trc_check_no) */
  $handler->display->display_options['filters']['field_trc_check_no_value']['id'] = 'field_trc_check_no_value';
  $handler->display->display_options['filters']['field_trc_check_no_value']['table'] = 'field_data_field_trc_check_no';
  $handler->display->display_options['filters']['field_trc_check_no_value']['field'] = 'field_trc_check_no_value';
  $handler->display->display_options['filters']['field_trc_check_no_value']['group'] = 1;
  $handler->display->display_options['filters']['field_trc_check_no_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_check_no_value']['expose']['operator_id'] = 'field_trc_check_no_value_op';
  $handler->display->display_options['filters']['field_trc_check_no_value']['expose']['label'] = 'Чек №';
  $handler->display->display_options['filters']['field_trc_check_no_value']['expose']['operator'] = 'field_trc_check_no_value_op';
  $handler->display->display_options['filters']['field_trc_check_no_value']['expose']['identifier'] = 'check_no';
  $handler->display->display_options['filters']['field_trc_check_no_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Клиент (field_trc_client) */
  $handler->display->display_options['filters']['field_trc_client_nid']['id'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['table'] = 'field_data_field_trc_client';
  $handler->display->display_options['filters']['field_trc_client_nid']['field'] = 'field_trc_client_nid';
  $handler->display->display_options['filters']['field_trc_client_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_trc_client_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator_id'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['label'] = 'Клиент';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['operator'] = 'field_trc_client_nid_op';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['identifier'] = 'client';
  $handler->display->display_options['filters']['field_trc_client_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Продукт транзакции (field_trc_product) */
  $handler->display->display_options['filters']['field_trc_product_nid']['id'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['field'] = 'field_trc_product_nid';
  $handler->display->display_options['filters']['field_trc_product_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator_id'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['label'] = 'Продукт';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['operator'] = 'field_trc_product_nid_op';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['identifier'] = 'trc_product';
  $handler->display->display_options['filters']['field_trc_product_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Дата публикации */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Дата публикации';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['created']['group_info']['label'] = 'Дата публикации';
  $handler->display->display_options['filters']['created']['group_info']['identifier'] = 'trc_created';
  $handler->display->display_options['filters']['created']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'сегодня',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'today 00:00:00',
        'max' => 'today 23:59:59',
      ),
    ),
    2 => array(
      'title' => 'вчера',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'yesterday 00:00:00',
        'max' => 'yesterday 23:59:59',
      ),
    ),
    3 => array(
      'title' => 'на этой неделе',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'this week 00:00:00',
        'max' => 'today 23:59:59',
      ),
    ),
    4 => array(
      'title' => 'на прошлой неделе',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'previous week 00:00:00',
        'max' => 'this week 00:00:00',
      ),
    ),
    5 => array(
      'title' => 'в этом месяце',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'first day of this month 00:00:00',
        'max' => 'today 23:59:59',
      ),
    ),
    6 => array(
      'title' => 'в прошлом месяце',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'first day of previous month 00:00:00',
        'max' => 'last day of previous month 23:59:59',
      ),
    ),
    7 => array(
      'title' => 'два месяца назад',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'first day of -2 month 00:00:00',
        'max' => 'last day of -2 month 23:59:59',
      ),
    ),
    8 => array(
      'title' => 'в этом году',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'first day of january this year 00:00:00',
        'max' => 'today 23:59:59',
      ),
    ),
    9 => array(
      'title' => 'в прошлом году',
      'operator' => 'between',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => 'first day of january previous year 00:00:00',
        'max' => 'last day of december previous year 23:59:59',
      ),
    ),
    10 => array(
      'title' => 'задать дату',
      'operator' => '!=',
      'value' => array(
        'type' => 'date',
        'value' => '1971-01-01 00:00:00',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '30, 50, 100, 200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'Показать все строки';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_trc_check_no' => 'field_trc_check_no',
    'field_trc_product' => 'field_trc_product',
    'title' => 'title',
    'uid' => 'uid',
    'php' => 'php',
    'created_1' => 'created_1',
    'created' => 'created',
    'field_trc_type' => 'field_trc_type',
    'field_trc_price_base' => 'field_trc_price_base',
    'field_trc_price' => 'field_trc_price',
    'field_trc_payment_cash' => 'field_trc_payment_cash',
    'field_trc_payment_terminal' => 'field_trc_payment_terminal',
    'field_trc_payment_owe' => 'field_trc_payment_owe',
    'field_trc_rate' => 'field_trc_rate',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_check_no' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_product' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price_base' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_payment_cash' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_payment_terminal' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_payment_owe' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_rate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Подвал: Глобальный: Сводка результатов */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Показано @start - @end из @total';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Удалить транзакцию',
    ),
  );
  /* Поле: Содержимое: Чек № */
  $handler->display->display_options['fields']['field_trc_check_no']['id'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['table'] = 'field_data_field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['field'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_check_no']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Продукт транзакции */
  $handler->display->display_options['fields']['field_trc_product']['id'] = 'field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['field'] = 'field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['label'] = 'Продукт';
  $handler->display->display_options['fields']['field_trc_product']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_trc_product']['settings'] = array(
    'node_reference_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_trc_product']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_trc_product']['separator'] = '';
  /* Поле: Содержимое: UID Автора */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Продавец';
  $handler->display->display_options['fields']['php']['alter']['path'] = 'user/[uid] ';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$trc_user = user_load($row->uid);
if (!empty($trc_user)) {
print \'<a href="\'.url(\'dashboard/reports/sellers\').\'" data-toggle="tooltip" data-placement="top" title="Нажмите, чтобы посмотреть отчёт по продавцам (Откроется в новом окне)" target="_blank">\'.$trc_user->name.\'</a>\';
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created_1']['format_date_sql'] = 0;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Время';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<a href="/ru/dashboard/reports/hours?date_filter_from%5Bvalue%5D%5Bdate%5D=[created_1]" data-toggle="tooltip" data-placement="top" title="Нажмите, чтобы посмотреть отчёт по дате (Откроется в новом окне)" target="_blank">[created]</a>';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y H:i';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Тип транзакции */
  $handler->display->display_options['fields']['field_trc_type']['id'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['field'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['label'] = 'Тип';
  $handler->display->display_options['fields']['field_trc_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_type']['alter']['text'] = '<span class="trc-type-[field_trc_type-value]">[field_trc_type]</span>';
  $handler->display->display_options['fields']['field_trc_type']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. цена';
  $handler->display->display_options['fields']['field_trc_price_base']['alter']['text'] = '[field_trc_price_base] сум';
  $handler->display->display_options['fields']['field_trc_price_base']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price_base']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. цена';
  $handler->display->display_options['fields']['field_trc_price']['alter']['text'] = '[field_trc_price] сум';
  $handler->display->display_options['fields']['field_trc_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Наличные */
  $handler->display->display_options['fields']['field_trc_payment_cash']['id'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['table'] = 'field_data_field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['field'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['alter']['text'] = '[field_trc_payment_cash] сум';
  $handler->display->display_options['fields']['field_trc_payment_cash']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_cash']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Терминал */
  $handler->display->display_options['fields']['field_trc_payment_terminal']['id'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['table'] = 'field_data_field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['field'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['alter']['text'] = '[field_trc_payment_terminal] сум';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Долг */
  $handler->display->display_options['fields']['field_trc_payment_owe']['id'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['table'] = 'field_data_field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['field'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_owe']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Курс у.е. в сумах */
  $handler->display->display_options['fields']['field_trc_rate']['id'] = 'field_trc_rate';
  $handler->display->display_options['fields']['field_trc_rate']['table'] = 'field_data_field_trc_rate';
  $handler->display->display_options['fields']['field_trc_rate']['field'] = 'field_trc_rate';
  $handler->display->display_options['fields']['field_trc_rate']['label'] = '';
  $handler->display->display_options['fields']['field_trc_rate']['element_class'] = 'hide';
  $handler->display->display_options['fields']['field_trc_rate']['element_label_class'] = 'hide';
  $handler->display->display_options['fields']['field_trc_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_rate']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_rate']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<span class="glyphicon glyphicon-edit" data-toggle="tooltip" data-placement="top" title="Редактировать"></span>';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = '<span class="glyphicon glyphicon-remove-circle text-danger" data-toggle="tooltip" data-placement="top" title="Удалить"></span>';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'h4 text-right';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'dashboard/reports';
  $handler->display->display_options['menu']['title'] = 'Все транзакции';
  $handler->display->display_options['menu']['weight'] = '60';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_stats');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Продаж всего';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Все продажи';
  $handler->display->display_options['fields']['field_trc_price']['alter']['text'] = '[field_trc_price] сум';
  $handler->display->display_options['fields']['field_trc_price']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_trc_price']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_trc_price']['element_wrapper_class'] = 'text-right';
  $handler->display->display_options['fields']['field_trc_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. всего';
  $handler->display->display_options['fields']['field_trc_price_base']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_base']['alter']['text'] = '[field_trc_price_base] сум';
  $handler->display->display_options['fields']['field_trc_price_base']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['php']['element_wrapper_class'] = 'text-right';
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$roz = $data->field_data_field_trc_price_field_trc_price_value;
$opt = $data->field_data_field_trc_price_base_field_trc_price_base_value;
$prib = $roz - $opt;

return number_format($prib, 0, \'.\', \' \') . \' сум\';';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Все-транзакции-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Чек № */
  $handler->display->display_options['fields']['field_trc_check_no']['id'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['table'] = 'field_data_field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['field'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_check_no']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Продукт';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: UID Автора */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Продавец';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$trc_user = user_load($row->uid);
if (!empty($trc_user)) {
print $trc_user->name;
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Время';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y H:i';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Тип транзакции */
  $handler->display->display_options['fields']['field_trc_type']['id'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['field'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['label'] = 'Тип';
  $handler->display->display_options['fields']['field_trc_type']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_prtrc_amount']['id'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['field'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_prtrc_opt_price']['id'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['table'] = 'field_data_field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['field'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_prtrc_roz_price']['id'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['field'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Поставщик */
  $handler->display->display_options['fields']['field_prtrc_provider_title']['id'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['table'] = 'field_data_field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['field'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['delta_offset'] = '0';
  /* Поле: Содержимое: Производитель */
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['id'] = 'field_prtrc_manufacturer';
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['table'] = 'field_data_field_prtrc_manufacturer';
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['field'] = 'field_prtrc_manufacturer';
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['relationship'] = 'field_trc_product_nid';
  /* Поле: Содержимое: Страна производителя */
  $handler->display->display_options['fields']['field_prtrc_mn_country']['id'] = 'field_prtrc_mn_country';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['table'] = 'field_data_field_prtrc_mn_country';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['field'] = 'field_prtrc_mn_country';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['label'] = 'Производитель-страна';
  $handler->display->display_options['path'] = 'dashboard/reports/xlsx';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/reports';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_average_check');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Продаж всего';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Поле: Содержимое: Курс у.е. в сумах */
  $handler->display->display_options['fields']['field_trc_rate']['id'] = 'field_trc_rate';
  $handler->display->display_options['fields']['field_trc_rate']['table'] = 'field_data_field_trc_rate';
  $handler->display->display_options['fields']['field_trc_rate']['field'] = 'field_trc_rate';
  $handler->display->display_options['fields']['field_trc_rate']['label'] = 'Курс';
  $handler->display->display_options['fields']['field_trc_rate']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Все продажи';
  $handler->display->display_options['fields']['field_trc_price']['element_type'] = '0';
  $handler->display->display_options['fields']['field_trc_price']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_trc_price']['element_wrapper_class'] = 'text-right';
  $handler->display->display_options['fields']['field_trc_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. всего';
  $handler->display->display_options['fields']['field_trc_price_base']['element_type'] = '0';
  $handler->display->display_options['fields']['field_trc_price_base']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price_base']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Чек № */
  $handler->display->display_options['fields']['field_trc_check_no']['id'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['table'] = 'field_data_field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['field'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_trc_check_no']['element_type'] = '0';
  $handler->display->display_options['fields']['field_trc_check_no']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_check_no']['separator'] = '';
  /* Поле: Содержимое: Наличные */
  $handler->display->display_options['fields']['field_trc_payment_cash']['id'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['table'] = 'field_data_field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['field'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_payment_cash']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_payment_cash']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_cash']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Терминал */
  $handler->display->display_options['fields']['field_trc_payment_terminal']['id'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['table'] = 'field_data_field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['field'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_payment_terminal']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_trc_price_1']['id'] = 'field_trc_price_1';
  $handler->display->display_options['fields']['field_trc_price_1']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price_1']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price_1']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_trc_price_1']['label'] = 'Все продажи (у.е.)';
  $handler->display->display_options['fields']['field_trc_price_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_price_1']['alter']['text'] = '[field_trc_price_1]/[field_trc_rate]';
  $handler->display->display_options['fields']['field_trc_price_1']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Долг */
  $handler->display->display_options['fields']['field_trc_payment_owe']['id'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['table'] = 'field_data_field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['field'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_owe']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Чек № */
  $handler->display->display_options['fields']['field_trc_check_no']['id'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['table'] = 'field_data_field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['field'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_check_no']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Продукт';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: UID Автора */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Продавец';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$trc_user = user_load($row->uid);
if (!empty($trc_user)) {
print $trc_user->name;
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Время';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y H:i';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Тип транзакции */
  $handler->display->display_options['fields']['field_trc_type']['id'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['field'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['label'] = 'Тип';
  $handler->display->display_options['fields']['field_trc_type']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_prtrc_amount']['id'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['field'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_prtrc_opt_price']['id'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['table'] = 'field_data_field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['field'] = 'field_prtrc_opt_price';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_prtrc_opt_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_prtrc_roz_price']['id'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['table'] = 'field_data_field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['field'] = 'field_prtrc_roz_price';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_prtrc_roz_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Поставщик */
  $handler->display->display_options['fields']['field_prtrc_provider_title']['id'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['table'] = 'field_data_field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['field'] = 'field_prtrc_provider_title';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_provider_title']['delta_offset'] = '0';
  /* Поле: Содержимое: Производитель */
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['id'] = 'field_prtrc_manufacturer';
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['table'] = 'field_data_field_prtrc_manufacturer';
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['field'] = 'field_prtrc_manufacturer';
  $handler->display->display_options['fields']['field_prtrc_manufacturer']['relationship'] = 'field_trc_product_nid';
  /* Поле: Содержимое: Страна производителя */
  $handler->display->display_options['fields']['field_prtrc_mn_country']['id'] = 'field_prtrc_mn_country';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['table'] = 'field_data_field_prtrc_mn_country';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['field'] = 'field_prtrc_mn_country';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['relationship'] = 'field_trc_product_nid';
  $handler->display->display_options['fields']['field_prtrc_mn_country']['label'] = 'Производитель-страна';
  $handler->display->display_options['path'] = 'dashboard/reports/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['return_path'] = 'dashboard/reports';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Online export */
  $handler = $view->new_display('page', 'Online export', 'online');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Фильтровать';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Очистить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_trc_check_no' => 'field_trc_check_no',
    'title_1' => 'title_1',
    'field_trc_product' => 'field_trc_product',
    'uid' => 'uid',
    'created' => 'created',
    'field_trc_type' => 'field_trc_type',
    'field_trc_price_base' => 'field_trc_price_base',
    'field_trc_price' => 'field_trc_price',
    'field_trc_payment_cash' => 'field_trc_payment_cash',
    'field_trc_payment_terminal' => 'field_trc_payment_terminal',
    'field_field_trc_refund_reason' => 'field_field_trc_refund_reason',
    'field_trc_refund_amount' => 'field_trc_refund_amount',
    'field_trc_payment_type' => 'field_trc_payment_type',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_check_no' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_product' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price_base' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_payment_cash' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_payment_terminal' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_field_trc_refund_reason' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_refund_amount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_payment_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Сводка результатов */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Показано @start - @end из @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Поле: Содержимое: Чек № */
  $handler->display->display_options['fields']['field_trc_check_no']['id'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['table'] = 'field_data_field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['field'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_check_no']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Продукт транзакции */
  $handler->display->display_options['fields']['field_trc_product']['id'] = 'field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['field'] = 'field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['label'] = 'Продукт';
  $handler->display->display_options['fields']['field_trc_product']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_trc_product']['settings'] = array(
    'node_reference_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_trc_product']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_trc_product']['separator'] = '';
  /* Поле: Содержимое: UID Автора */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Время';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y H:i';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Тип транзакции */
  $handler->display->display_options['fields']['field_trc_type']['id'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['field'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['label'] = 'Тип';
  $handler->display->display_options['fields']['field_trc_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_type']['alter']['text'] = '<span class="trc-type-[field_trc_type-value]">[field_trc_type]</span>';
  $handler->display->display_options['fields']['field_trc_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_type']['type'] = 'list_key';
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = 'Опт. цена';
  $handler->display->display_options['fields']['field_trc_price_base']['alter']['text'] = '[field_trc_price_base] сум';
  $handler->display->display_options['fields']['field_trc_price_base']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price_base']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Роз. цена';
  $handler->display->display_options['fields']['field_trc_price']['alter']['text'] = '[field_trc_price] сум';
  $handler->display->display_options['fields']['field_trc_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Наличные */
  $handler->display->display_options['fields']['field_trc_payment_cash']['id'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['table'] = 'field_data_field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['field'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_payment_cash']['alter']['text'] = '[field_trc_payment_cash] сум';
  $handler->display->display_options['fields']['field_trc_payment_cash']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_cash']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Терминал */
  $handler->display->display_options['fields']['field_trc_payment_terminal']['id'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['table'] = 'field_data_field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['field'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_payment_terminal']['alter']['text'] = '[field_trc_payment_terminal] сум';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Причина возврата */
  $handler->display->display_options['fields']['field_field_trc_refund_reason']['id'] = 'field_field_trc_refund_reason';
  $handler->display->display_options['fields']['field_field_trc_refund_reason']['table'] = 'field_data_field_field_trc_refund_reason';
  $handler->display->display_options['fields']['field_field_trc_refund_reason']['field'] = 'field_field_trc_refund_reason';
  /* Поле: Содержимое: Сумма возврата */
  $handler->display->display_options['fields']['field_trc_refund_amount']['id'] = 'field_trc_refund_amount';
  $handler->display->display_options['fields']['field_trc_refund_amount']['table'] = 'field_data_field_trc_refund_amount';
  $handler->display->display_options['fields']['field_trc_refund_amount']['field'] = 'field_trc_refund_amount';
  $handler->display->display_options['fields']['field_trc_refund_amount']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_refund_amount']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Тип оплаты */
  $handler->display->display_options['fields']['field_trc_payment_type']['id'] = 'field_trc_payment_type';
  $handler->display->display_options['fields']['field_trc_payment_type']['table'] = 'field_data_field_trc_payment_type';
  $handler->display->display_options['fields']['field_trc_payment_type']['field'] = 'field_trc_payment_type';
  $handler->display->display_options['fields']['field_trc_payment_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_trc_payment_type']['delta_offset'] = '0';
  /* Поле: Пользователь: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Поле: Содержимое: Сервер ID */
  $handler->display->display_options['fields']['field_trc_server_node_id']['id'] = 'field_trc_server_node_id';
  $handler->display->display_options['fields']['field_trc_server_node_id']['table'] = 'field_data_field_trc_server_node_id';
  $handler->display->display_options['fields']['field_trc_server_node_id']['field'] = 'field_trc_server_node_id';
  $handler->display->display_options['fields']['field_trc_server_node_id']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_server_node_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Загружен на сервер (field_trc_uploaded_server) */
  $handler->display->display_options['filters']['field_trc_uploaded_server_value']['id'] = 'field_trc_uploaded_server_value';
  $handler->display->display_options['filters']['field_trc_uploaded_server_value']['table'] = 'field_data_field_trc_uploaded_server';
  $handler->display->display_options['filters']['field_trc_uploaded_server_value']['field'] = 'field_trc_uploaded_server_value';
  $handler->display->display_options['filters']['field_trc_uploaded_server_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trc_uploaded_server_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'dashboard/reports/online';
  $handler->display->display_options['menu']['title'] = 'Все транзакции';
  $handler->display->display_options['menu']['weight'] = '60';
  $handler->display->display_options['menu']['name'] = 'menu-manager-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['reports_transactions'] = $view;

  $view = new view();
  $view->name = 'revoked_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Списанные товары';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Списанные товары';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'field_rv_amount' => 'field_rv_amount',
    'field_rv_opt_price' => 'field_rv_opt_price',
    'field_rv_roz_price' => 'field_rv_roz_price',
    'field_rv_comment' => 'field_rv_comment',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rv_amount' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rv_opt_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rv_roz_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rv_comment' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить списанного товара',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Время списания';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_rv_amount']['id'] = 'field_rv_amount';
  $handler->display->display_options['fields']['field_rv_amount']['table'] = 'field_data_field_rv_amount';
  $handler->display->display_options['fields']['field_rv_amount']['field'] = 'field_rv_amount';
  $handler->display->display_options['fields']['field_rv_amount']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_rv_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_rv_opt_price']['id'] = 'field_rv_opt_price';
  $handler->display->display_options['fields']['field_rv_opt_price']['table'] = 'field_data_field_rv_opt_price';
  $handler->display->display_options['fields']['field_rv_opt_price']['field'] = 'field_rv_opt_price';
  $handler->display->display_options['fields']['field_rv_opt_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_rv_opt_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_rv_roz_price']['id'] = 'field_rv_roz_price';
  $handler->display->display_options['fields']['field_rv_roz_price']['table'] = 'field_data_field_rv_roz_price';
  $handler->display->display_options['fields']['field_rv_roz_price']['field'] = 'field_rv_roz_price';
  $handler->display->display_options['fields']['field_rv_roz_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_rv_roz_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Комментарий */
  $handler->display->display_options['fields']['field_rv_comment']['id'] = 'field_rv_comment';
  $handler->display->display_options['fields']['field_rv_comment']['table'] = 'field_data_field_rv_comment';
  $handler->display->display_options['fields']['field_rv_comment']['field'] = 'field_rv_comment';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'revoked_product' => 'revoked_product',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['revoked_products'] = $view;

  $view = new view();
  $view->name = 'sellers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Продавцы';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Продавцы';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Вы ещё не добавили ни одного продавца.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Пользователь: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Имя пользователя';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Поле: Пользователь: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Расширенный доступ';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$account = user_load($row->uid);
if (in_array(\'warehouse manager\', $account->roles)) {
print \'<span class="glyphicon glyphicon-ok text-success"></span>\';
} 
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Пользователь: Дата создания */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата регистрации';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Пользователь: Последнее посещение */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['empty'] = 'никогда';
  $handler->display->display_options['fields']['access']['date_format'] = 'long';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'long';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/ru/dashboard/sellers/[uid]/edit?destination=dashboard/sellers">Редактировать</a> <a href="/ru/dashboard/sellers/[uid]/cancel?destination=dashboard/sellers">Удалить</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Пользователь: Дата создания */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Пользователь: Менеджер (field_parent_manager) */
  $handler->display->display_options['arguments']['field_parent_manager_uid']['id'] = 'field_parent_manager_uid';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['table'] = 'field_data_field_parent_manager';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['field'] = 'field_parent_manager_uid';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_manager_uid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Пользователь: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dashboard/sellers';
  $export['sellers'] = $view;

  $view = new view();
  $view->name = 'top_selled_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Топ продаваемых продуктов';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ТОП-5 продаваемые продукты';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Подвал: Глобальный: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="text-right">
  <br><a href="/ru/dashboard/reports/products">Посмотреть отчёт по продуктам</a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Не было продаж.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Продукт транзакции (field_trc_product) - реверс */
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['id'] = 'reverse_field_trc_product_node';
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['field'] = 'reverse_field_trc_product_node';
  $handler->display->display_options['relationships']['reverse_field_trc_product_node']['required'] = TRUE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: SUM(Содержимое: Количество) */
  $handler->display->display_options['fields']['field_prtrc_amount']['id'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['field'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_amount']['label'] = '';
  $handler->display->display_options['fields']['field_prtrc_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prtrc_amount']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: Счетчик результатов */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Критерий сортировки: SUM(Содержимое: Количество (field_prtrc_amount)) */
  $handler->display->display_options['sorts']['field_prtrc_amount_value']['id'] = 'field_prtrc_amount_value';
  $handler->display->display_options['sorts']['field_prtrc_amount_value']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['sorts']['field_prtrc_amount_value']['field'] = 'field_prtrc_amount_value';
  $handler->display->display_options['sorts']['field_prtrc_amount_value']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['field_prtrc_amount_value']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction_product' => 'transaction_product',
  );
  /* Критерий фильтра: Содержимое: Дата публикации */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['value'] = '-30 days';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Дата публикации';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  /* Критерий фильтра: Содержимое: Количество (field_prtrc_amount) */
  $handler->display->display_options['filters']['field_prtrc_amount_value']['id'] = 'field_prtrc_amount_value';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['field'] = 'field_prtrc_amount_value';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_prtrc_amount_value']['value']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Глобальный: Счетчик результатов */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '<span class="label label-info">[counter]</span>';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: SUM(Содержимое: Количество) */
  $handler->display->display_options['fields']['field_prtrc_amount']['id'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['table'] = 'field_data_field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['field'] = 'field_prtrc_amount';
  $handler->display->display_options['fields']['field_prtrc_amount']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_prtrc_amount']['label'] = '';
  $handler->display->display_options['fields']['field_prtrc_amount']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_prtrc_amount']['alter']['text'] = '- [field_prtrc_amount] упк.';
  $handler->display->display_options['fields']['field_prtrc_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prtrc_amount']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prtrc_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $export['top_selled_products'] = $view;

  $view = new view();
  $view->name = 'transaction_track_changes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Изменения';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Изменения в транзакции';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'timestamp' => 'timestamp',
    'uid' => 'uid',
    'field_name' => 'field_name',
    'before_value_text' => 'before_value_text',
    'after_value_text' => 'after_value_text',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'before_value_text' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'after_value_text' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Field Tracker: Creation Date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'track_field_changes_audit';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Время';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd.m.Y - H:i:s';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['format_date_sql'] = 0;
  /* Поле: Field Tracker: Пользователь */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'track_field_changes_audit';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Поле: Field Tracker: Field Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'track_field_changes_audit';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = 'Название поля';
  /* Поле: Field Tracker: Value Before */
  $handler->display->display_options['fields']['before_value_text']['id'] = 'before_value_text';
  $handler->display->display_options['fields']['before_value_text']['table'] = 'track_field_changes_audit';
  $handler->display->display_options['fields']['before_value_text']['field'] = 'before_value_text';
  $handler->display->display_options['fields']['before_value_text']['label'] = 'Старое значение';
  /* Поле: Field Tracker: Value After */
  $handler->display->display_options['fields']['after_value_text']['id'] = 'after_value_text';
  $handler->display->display_options['fields']['after_value_text']['table'] = 'track_field_changes_audit';
  $handler->display->display_options['fields']['after_value_text']['field'] = 'after_value_text';
  $handler->display->display_options['fields']['after_value_text']['label'] = 'Новое значение';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );
  /* Критерий фильтра: Field Tracker: Field Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'track_field_changes_audit';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_trc_client' => 'field_trc_client',
    'field_trc_payment_cash' => 'field_trc_payment_cash',
    'field_trc_payment_owe' => 'field_trc_payment_owe',
    'field_trc_payment_terminal' => 'field_trc_payment_terminal',
    'field_trc_price' => 'field_trc_price',
    'field_trc_rate' => 'field_trc_rate',
    'field_trc_refund_amount' => 'field_trc_refund_amount',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['transaction_track_changes'] = $view;

  $view = new view();
  $view->name = 'transactions_24';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Транзакции за 24 часа';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<table class="transactions-table table table-condensed table-hover">
				<thead>
					<tr>
						<th>Чек №</th>
						<th>Дата</th>
						<th width="40%">Продукты</th>
						<th>Общая сумма</th>
						<th>Терминал</th>
						<th>Наличные</th>
						<th>Долг</th>
						<th>Продавец</th>
						<th>Действия</th>
					</tr>
				</thead>
				<tbody></tbody>
			</table>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Чек № */
  $handler->display->display_options['fields']['field_trc_check_no']['id'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['table'] = 'field_data_field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['field'] = 'field_trc_check_no';
  $handler->display->display_options['fields']['field_trc_check_no']['element_class'] = 'trc-check-no';
  $handler->display->display_options['fields']['field_trc_check_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_check_no']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_check_no']['empty'] = '___';
  $handler->display->display_options['fields']['field_trc_check_no']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_check_no']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата';
  $handler->display->display_options['fields']['created']['element_class'] = 'trc-time';
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y H:i:s';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Продукт транзакции */
  $handler->display->display_options['fields']['field_trc_product']['id'] = 'field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['field'] = 'field_trc_product';
  $handler->display->display_options['fields']['field_trc_product']['label'] = 'Продукты';
  $handler->display->display_options['fields']['field_trc_product']['element_class'] = 'trc-products';
  $handler->display->display_options['fields']['field_trc_product']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_product']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_product']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_trc_product']['settings'] = array(
    'node_reference_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_trc_product']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_trc_product']['separator'] = '';
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['label'] = '';
  $handler->display->display_options['fields']['field_trc_price_base']['element_type'] = '0';
  $handler->display->display_options['fields']['field_trc_price_base']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price_base']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price_base']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['label'] = 'Общая сумма';
  $handler->display->display_options['fields']['field_trc_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Терминал */
  $handler->display->display_options['fields']['field_trc_payment_terminal']['id'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['table'] = 'field_data_field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['field'] = 'field_trc_payment_terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['element_class'] = 'trc-terminal';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_payment_terminal']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_terminal']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Наличные */
  $handler->display->display_options['fields']['field_trc_payment_cash']['id'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['table'] = 'field_data_field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['field'] = 'field_trc_payment_cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['element_class'] = 'trc-cash';
  $handler->display->display_options['fields']['field_trc_payment_cash']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_payment_cash']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_cash']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Долг */
  $handler->display->display_options['fields']['field_trc_payment_owe']['id'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['table'] = 'field_data_field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['field'] = 'field_trc_payment_owe';
  $handler->display->display_options['fields']['field_trc_payment_owe']['empty'] = '0';
  $handler->display->display_options['fields']['field_trc_payment_owe']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_trc_payment_owe']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Тип транзакции */
  $handler->display->display_options['fields']['field_trc_type']['id'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['field'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['label'] = 'Тип платежа';
  $handler->display->display_options['fields']['field_trc_type']['element_class'] = 'trc-type';
  $handler->display->display_options['fields']['field_trc_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_type']['element_default_classes'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'YmdHis';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created_1']['format_date_sql'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Поле: Содержимое: Тип транзакции */
  $handler->display->display_options['fields']['field_trc_type_1']['id'] = 'field_trc_type_1';
  $handler->display->display_options['fields']['field_trc_type_1']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['fields']['field_trc_type_1']['field'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_trc_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trc_type_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_trc_type_1']['type'] = 'list_key';
  /* Поле: Пользователь: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Продавец';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Дата: Дата (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['date_argument']['default_argument_options']['code'] = 'if (isset($_GET[\'date\'])) {
return $_GET[\'date\'];
}
return date(\'Y-m-d\');';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['transactions_24'] = $view;

  $view = new view();
  $view->name = 'transactions_by_product';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Все транзакции по продуктам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Все продажи';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_trc_qty' => 'field_trc_qty',
    'field_trc_price_base' => 'field_trc_price_base',
    'field_field_trc_refund_reason' => 'field_field_trc_refund_reason',
    'field_trc_price' => 'field_trc_price',
    'field_trc_type' => 'field_trc_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_qty' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price_base' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_field_trc_refund_reason' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trc_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата продажи';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Поле: Обработчик испорчен или отсутствует */
  $handler->display->display_options['fields']['field_trc_qty']['id'] = 'field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['table'] = 'field_data_field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['field'] = 'field_trc_qty';
  $handler->display->display_options['fields']['field_trc_qty']['label'] = 'Количество';
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_trc_price_base']['id'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['table'] = 'field_data_field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['field'] = 'field_trc_price_base';
  $handler->display->display_options['fields']['field_trc_price_base']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_trc_price_base']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_trc_price']['id'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['table'] = 'field_data_field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['field'] = 'field_trc_price';
  $handler->display->display_options['fields']['field_trc_price']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_trc_price']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Причина возврата */
  $handler->display->display_options['fields']['field_field_trc_refund_reason']['id'] = 'field_field_trc_refund_reason';
  $handler->display->display_options['fields']['field_field_trc_refund_reason']['table'] = 'field_data_field_field_trc_refund_reason';
  $handler->display->display_options['fields']['field_field_trc_refund_reason']['field'] = 'field_field_trc_refund_reason';
  $handler->display->display_options['fields']['field_field_trc_refund_reason']['exclude'] = TRUE;
  /* Поле: Содержимое: Тип транзакции */
  $handler->display->display_options['fields']['field_trc_type']['id'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['table'] = 'field_data_field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['field'] = 'field_trc_type';
  $handler->display->display_options['fields']['field_trc_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trc_type']['alter']['text'] = '<a data-toggle="tooltip" data-placement="top" title="[field_field_trc_refund_reason]">[field_trc_type]</a>';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: Продукт транзакции (field_trc_product) */
  $handler->display->display_options['arguments']['field_trc_product_nid']['id'] = 'field_trc_product_nid';
  $handler->display->display_options['arguments']['field_trc_product_nid']['table'] = 'field_data_field_trc_product';
  $handler->display->display_options['arguments']['field_trc_product_nid']['field'] = 'field_trc_product_nid';
  $handler->display->display_options['arguments']['field_trc_product_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_trc_product_nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_trc_product_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_trc_product_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_trc_product_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_trc_product_nid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transaction' => 'transaction',
  );

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $export['transactions_by_product'] = $view;

  $view = new view();
  $view->name = 'warehouse';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Склад';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Склад';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Поиск';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возр.';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыв.';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 30, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'Показать все строки';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_md_up_barcode' => 'field_md_up_barcode',
    'nid_2' => 'nid_2',
    'nid' => 'nid',
    'nid_1' => 'nid_1',
    'created' => 'created',
    'changed' => 'changed',
    'status' => 'status',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_md_up_barcode' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right">
<a href="/ru/dashboard/warehouse/apply?destination=dashboard/warehouse" class="btn btn-primary">Поступление по накладной</a>
<a href="/ru/dashboard/warehouse/add-new?destination=dashboard/warehouse" class="btn btn-success">Добавить новый продукт</a>
</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Ваш склад пустой. Добавьте новый <a href="/dashboard/warehouse/add-new">продукт</a>. Ваши продукты будут доступно в кассе.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Изменить значения полей',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Включить',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Выключить',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить продукт',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Товар';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Штрих-код */
  $handler->display->display_options['fields']['field_md_up_barcode']['id'] = 'field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['table'] = 'field_data_field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['field'] = 'field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_md_up_barcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['label'] = 'Кол.';
  $handler->display->display_options['fields']['nid_2']['element_default_classes'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Добавлен';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = '<span class="glyphicon glyphicon-remove-circle text-danger" data-toggle="tooltip" data-placement="top" title="Удалить"></span>';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<span class="glyphicon glyphicon-edit" data-toggle="tooltip" data-placement="top" title="Редактировать"></span>';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/ru/dashboard/warehouse/barcode/[nid_2]"><span class="glyphicon glyphicon-barcode" data-toggle="tooltip" data-placement="top" title="Печать штрих-кода"></span></a> &nbsp;
<a href="/ru/dashboard/warehouse/add-new?clone=[nid_2]" class="text-warning"><span class="glyphicon glyphicon-duplicate" data-toggle="tooltip" data-placement="top" title="Клонировать продукт"></span></a> &nbsp;
[edit_node]&nbsp; 
[delete_node]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'h3 text-right warehouse-actions';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['group_type'] = 'stddev_pop';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Название лекарства';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 1;
  /* Критерий фильтра: Содержимое: Штрих-код (field_md_up_barcode) */
  $handler->display->display_options['filters']['field_md_up_barcode_value']['id'] = 'field_md_up_barcode_value';
  $handler->display->display_options['filters']['field_md_up_barcode_value']['table'] = 'field_data_field_md_up_barcode';
  $handler->display->display_options['filters']['field_md_up_barcode_value']['field'] = 'field_md_up_barcode_value';
  $handler->display->display_options['filters']['field_md_up_barcode_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_md_up_barcode_value']['expose']['operator_id'] = 'field_md_up_barcode_value_op';
  $handler->display->display_options['filters']['field_md_up_barcode_value']['expose']['label'] = 'Штрих-код';
  $handler->display->display_options['filters']['field_md_up_barcode_value']['expose']['operator'] = 'field_md_up_barcode_value_op';
  $handler->display->display_options['filters']['field_md_up_barcode_value']['expose']['identifier'] = 'field_md_up_barcode_value';
  $handler->display->display_options['filters']['field_md_up_barcode_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Подвал: Глобальный: Сводка результатов */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<p class="pull-left">Показан @start - @end из @total</p>';
  $handler->display->display_options['path'] = 'dashboard/warehouse';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Склад-%timestamp-full.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Продукт (field_pb_product) - реверс */
  $handler->display->display_options['relationships']['reverse_field_pb_product_node']['id'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['relationships']['reverse_field_pb_product_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_pb_product_node']['field'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название продукта';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Название продукта */
  $handler->display->display_options['fields']['field_pr_medicament_title']['id'] = 'field_pr_medicament_title';
  $handler->display->display_options['fields']['field_pr_medicament_title']['table'] = 'field_data_field_pr_medicament_title';
  $handler->display->display_options['fields']['field_pr_medicament_title']['field'] = 'field_pr_medicament_title';
  /* Поле: Содержимое: Штрих-код */
  $handler->display->display_options['fields']['field_md_up_barcode']['id'] = 'field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['table'] = 'field_data_field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['field'] = 'field_md_up_barcode';
  $handler->display->display_options['fields']['field_md_up_barcode']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_md_up_barcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Кол. в упаковке */
  $handler->display->display_options['fields']['field_md_up_amount']['id'] = 'field_md_up_amount';
  $handler->display->display_options['fields']['field_md_up_amount']['table'] = 'field_data_field_md_up_amount';
  $handler->display->display_options['fields']['field_md_up_amount']['field'] = 'field_md_up_amount';
  $handler->display->display_options['fields']['field_md_up_amount']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_md_up_amount']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Производитель */
  $handler->display->display_options['fields']['field_pr_manufacturer']['id'] = 'field_pr_manufacturer';
  $handler->display->display_options['fields']['field_pr_manufacturer']['table'] = 'field_data_field_pr_manufacturer';
  $handler->display->display_options['fields']['field_pr_manufacturer']['field'] = 'field_pr_manufacturer';
  $handler->display->display_options['fields']['field_pr_manufacturer']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: Страна производителя */
  $handler->display->display_options['fields']['field_pr_mn_country']['id'] = 'field_pr_mn_country';
  $handler->display->display_options['fields']['field_pr_mn_country']['table'] = 'field_data_field_pr_mn_country';
  $handler->display->display_options['fields']['field_pr_mn_country']['field'] = 'field_pr_mn_country';
  $handler->display->display_options['fields']['field_pr_mn_country']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: Дата прибытия */
  $handler->display->display_options['fields']['field_pr_income_date']['id'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['table'] = 'field_data_field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['field'] = 'field_pr_income_date';
  $handler->display->display_options['fields']['field_pr_income_date']['relationship'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['fields']['field_pr_income_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Количество */
  $handler->display->display_options['fields']['field_pr_amount']['id'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['table'] = 'field_data_field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['field'] = 'field_pr_amount';
  $handler->display->display_options['fields']['field_pr_amount']['relationship'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['fields']['field_pr_amount']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_pr_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Оптовая цена */
  $handler->display->display_options['fields']['field_pr_price_base']['id'] = 'field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['table'] = 'field_data_field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['field'] = 'field_pr_price_base';
  $handler->display->display_options['fields']['field_pr_price_base']['relationship'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['fields']['field_pr_price_base']['label'] = 'Опт. цена';
  $handler->display->display_options['fields']['field_pr_price_base']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_pr_price_base']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Розничная цена */
  $handler->display->display_options['fields']['field_pr_price']['id'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['table'] = 'field_data_field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['field'] = 'field_pr_price';
  $handler->display->display_options['fields']['field_pr_price']['relationship'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['fields']['field_pr_price']['label'] = 'Роз. цена';
  $handler->display->display_options['fields']['field_pr_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_pr_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Срок годности */
  $handler->display->display_options['fields']['field_pr_expiry_date']['id'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['table'] = 'field_data_field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['field'] = 'field_pr_expiry_date';
  $handler->display->display_options['fields']['field_pr_expiry_date']['relationship'] = 'reverse_field_pb_product_node';
  $handler->display->display_options['fields']['field_pr_expiry_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Опубликовано */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Включен';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['path'] = 'dashboard/warehouse/xlsx';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'dashboard/warehouse';
  $handler->display->display_options['segment_size'] = '100';
  $export['warehouse'] = $view;

  $view = new view();
  $view->name = 'waybills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Накладные';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Накладные';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Шапка: Глобальный: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="text-right pull-right margin-top-38"><a href="/ru/dashboard/providers/waybills/add-new?destination=dashboard/providers/waybills" class="btn btn-success">Новая накладная</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Поведение при отсутствии результатов: Глобальный: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Накладные ещё не добавлены.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Содержимое: Договор (field_wb_contract_no) */
  $handler->display->display_options['relationships']['field_wb_contract_no_nid']['id'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['relationships']['field_wb_contract_no_nid']['table'] = 'field_data_field_wb_contract_no';
  $handler->display->display_options['relationships']['field_wb_contract_no_nid']['field'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['relationships']['field_wb_contract_no_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_wb_contract_no_nid']['delta'] = '-1';
  /* Связь: Содержимое: Поставщик (field_dg_provider) */
  $handler->display->display_options['relationships']['field_dg_provider_nid']['id'] = 'field_dg_provider_nid';
  $handler->display->display_options['relationships']['field_dg_provider_nid']['table'] = 'field_data_field_dg_provider';
  $handler->display->display_options['relationships']['field_dg_provider_nid']['field'] = 'field_dg_provider_nid';
  $handler->display->display_options['relationships']['field_dg_provider_nid']['relationship'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['relationships']['field_dg_provider_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_dg_provider_nid']['delta'] = '-1';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить договор',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Накладная';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Дата */
  $handler->display->display_options['fields']['field_wb_date']['id'] = 'field_wb_date';
  $handler->display->display_options['fields']['field_wb_date']['table'] = 'field_data_field_wb_date';
  $handler->display->display_options['fields']['field_wb_date']['field'] = 'field_wb_date';
  $handler->display->display_options['fields']['field_wb_date']['label'] = 'Дата создания';
  $handler->display->display_options['fields']['field_wb_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Договор №';
  /* Поле: Содержимое: Дата договора */
  $handler->display->display_options['fields']['field_dg_date']['id'] = 'field_dg_date';
  $handler->display->display_options['fields']['field_dg_date']['table'] = 'field_data_field_dg_date';
  $handler->display->display_options['fields']['field_dg_date']['field'] = 'field_dg_date';
  $handler->display->display_options['fields']['field_dg_date']['relationship'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['fields']['field_dg_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_dg_provider_nid';
  $handler->display->display_options['fields']['title_2']['label'] = 'Поставщик';
  $handler->display->display_options['fields']['title_2']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '<span class="glyphicon glyphicon-edit" data-toggle="tooltip" data-placement="top" title="Редактировать"></span>';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = '<span class="glyphicon glyphicon-remove-circle text-danger" data-toggle="tooltip" data-placement="top" title="Удалить"></span>';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]&nbsp; 
[delete_node]&nbsp;';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'h4 text-right';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_dg_provider_nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Поставщик №';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'waybill' => 'waybill',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Накладная №';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Критерий фильтра: Содержимое: Дата (field_wb_date) */
  $handler->display->display_options['filters']['field_wb_date_value']['id'] = 'field_wb_date_value';
  $handler->display->display_options['filters']['field_wb_date_value']['table'] = 'field_data_field_wb_date';
  $handler->display->display_options['filters']['field_wb_date_value']['field'] = 'field_wb_date_value';
  $handler->display->display_options['filters']['field_wb_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_wb_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_wb_date_value']['expose']['operator_id'] = 'field_wb_date_value_op';
  $handler->display->display_options['filters']['field_wb_date_value']['expose']['label'] = 'Дата создания';
  $handler->display->display_options['filters']['field_wb_date_value']['expose']['operator'] = 'field_wb_date_value_op';
  $handler->display->display_options['filters']['field_wb_date_value']['expose']['identifier'] = 'field_wb_date_value';
  $handler->display->display_options['filters']['field_wb_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_wb_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_wb_date_value']['year_range'] = '-0:+0';
  /* Критерий фильтра: Содержимое: Договор (field_wb_contract_no) */
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['id'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['table'] = 'field_data_field_wb_contract_no';
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['field'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['expose']['operator_id'] = 'field_wb_contract_no_nid_op';
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['expose']['label'] = 'Договор';
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['expose']['operator'] = 'field_wb_contract_no_nid_op';
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['expose']['identifier'] = 'field_wb_contract_no_nid';
  $handler->display->display_options['filters']['field_wb_contract_no_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'dashboard/providers/waybills';
  $export['waybills'] = $view;

  return $export;
}
