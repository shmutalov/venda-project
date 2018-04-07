<?php

/**
* @file
* Product import.
*/

/**
* Warehouse products import form.
*/
function customizer_warehouse_product_import_form($form, &$form_state) {
  /*$form['delimiter'] = array(
    '#type' => 'select',
    '#title' => t('Delimiter'),
    '#description' => t('The character that delimits fields in the CSV file.'),
    '#options' => array(
      ',' => ',',
      ';' => ';',
      'TAB' => 'TAB',
      '|' => '|',
    ),
    '#default_value' => ';',
  );

  // first row is header
  $form['no_headers'] = array(
    '#type' => 'checkbox',
    '#title' => t('No Headers'),
    '#description' => t('Check if the imported CSV file does not start with a header row.'),
    '#default_value' => 0,
  );*/

  $form['upload'] = array(
    '#type' => 'file',
    '#title' => t('File'),
    '#description' => t('Select CSV file from your local system.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

function customizer_warehouse_product_import_form_validate($form, &$form_state) {
  global $user;

  $user_dir = 'private://warehouse_import/' . $user->uid . '/';
  file_prepare_directory($user_dir, FILE_CREATE_DIRECTORY);
  $file = file_save_upload('upload', array(
    'file_validate_extensions' => array('csv'),
  ), $user_dir, FILE_EXISTS_RENAME);

  // If the file passed validation
  if ($file) {
    if ($file->filesize) {
      $form_state['storage']['upload'] = $file;
    } else {
      form_set_error('upload', 'Uploaded file is empty!');
    }
  } else {
    form_set_error('upload', 'No file was uploaded.');
  }

  if ($file && form_get_errors()) {
    file_delete($file, TRUE);
  }
}

function customizer_warehouse_product_import_form_submit($form, &$form_state) {
  $file = $form_state['storage']['upload'];
  // We are done with the file, remove it from storage.
  unset($form_state['storage']['file']);

  if (file_exists(drupal_realpath($file->uri))) {
    $batch = array(
      'title' => 'Importing products',
      'operations' => array(
        array('customizer_import_batch_operation', array($file->fid)),
      ),
      'finished' => 'customizer_import_batch_finished',
      'init_message' => 'Import is starting',
      'progress_message' => 'Import in progress',
      //'error_message' => 'Error while importing',
      'file' => drupal_get_path('module', 'customizer') . '/customizer.import.inc',
    );

    batch_set($batch);
  } else {
    drupal_set_message('File upload error.');
    file_delete($file, TRUE);
  }
}

function customizer_import_batch_operation($file_id, &$context) {
  $file = file_load($file_id);

  if ($file === FALSE || !file_exists(($file_real_path = drupal_realpath($file->uri)))) {
    $context['results']['files_delete'][$file_id] = $file_id;
    return;
  }

  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $file->filesize;
    $context['results']['files_delete'][$file_id] = $file_id;
  }

  $file_resource = fopen($file_real_path, 'r');

  if ($file_resource === FALSE) {
    $context['message'] = 'Error opening products csv file.';
    return;
  }

  if (fseek($file_resource, $context['sandbox']['progress'], SEEK_SET) < 0) {
    fclose($file_resource);
    return;
  }

  // How much nodes import by one batch
  $batch_limit = 2;

  $counter = 0;
  $data_rows = array();

  while (($data = fgetcsv($file_resource, null, ';', '"')) !== FALSE && $data !== NULL) {
    $data_rows[] = $data;
    ++$counter;

    if ($counter >= $batch_limit) {
      break;
    }
  }

  $context['sandbox']['progress'] = ftell($file_resource);
  fclose($file_resource);

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    if ($data !== FALSE && $data !== NULL) {
      $context['finished'] = ($context['sandbox']['max'] > 0) ?
        ($context['sandbox']['progress'] / $context['sandbox']['max'])
        : ($context['sandbox']['progress'] >= $context['sandbox']['max']);
    }
  }

  customizer_import_batch_processing($data_rows, $context);
}

/**
* This function runs the batch processing and creates nodes with then given information
*/
function customizer_import_batch_processing($data_rows, &$context) {
  /*
  Проверить, есть ли такая форма выпуска в таксономии
  Проверить, есть ли лекарство с таким названием и формой выпуска на сайте
  Что, если будет несколько лекарств с таким названием и формой выпуска?
  Если нет, то создать
  Проверить есть ли у текущего пользователя продукты по этому лекарству
  Что, если у пользователя будет несколько продуктов по какому-то лекарству (например,
  по ошибке добавил 2 раза)
  Если нет, то создать продукты
  Если есть, то загрузить продукт и обновить все его поля
   */

  // load taxonomy tree for vocabulary Форма выпуска
  // new self created add to this array
  // after check, try to load from db (in case someone also created this term)
  // if found, save it to local cache



  foreach ($data_rows as $data) {
    // blank line is parsed by fgetcsv as array(null)
    if ($data === array(null)) {
      continue;
    }

    // Lets make the variables more readable.
    $node_fields = array();
    $node_fields['title'] = trim($data[0]);
    $node_fields['package'] = (int) trim($data[1]);

    $node = new stdClass();
    $node->type = 'medicament';
    node_object_prepare($node);
    $node->status = 1;
    $node->language = LANGUAGE_NONE;
    $node->title = $node_fields['title'];
    //$node->field_md_type[LANGUAGE_NONE][]['tid'] = $node_fields['package'];

    $node = node_submit($node);
    $node->uid = $GLOBALS['user']->uid;
    node_save($node);

    /*$title = $data[0];
    $body = $data[1];
    $serial_num = $data[2];
    // Find out if the node already exists by looking up its serial number. Each serial number should be unique. You can use whatever you want.
    $nid = db_query("SELECT DISTINCT n.nid FROM {node} n " .
    "INNER JOIN {field_data_field_serial_number} s ON s.revision_id = n.vid AND s.entity_id = n.nid " .
    "WHERE field_serial_number_value = :serial", array(
    ':serial' => $serial_num,
    ))->fetchField();
    if(!empty($nid)) {
    // The node exists! Load it.
    $node = node_load($nid);

    // Change the values. No need to update the serial number though.
    $node->title = $title;
    $node->body['und'][0]['value'] = $body;
    $node->body['und'][0]['safe_value'] = check_plain($body);
    node_save($node);
    }
    else {
    // The node does not exist! Create it.
    global $user;
    $node = new StdClass();
    $node->type = 'page'; // Choose your type
    $node->status = 1; // Sets to published automatically, 0 will be unpublished
    $node->title = $title;
    $node->uid = $user->uid;
    $node->body['und'][0]['value'] = $body;
    $node->body['und'][0]['safe_value'] = check_plain($body);
    $node->language = 'und';

    $node->field_serial_number['und'][0]['value'] = $serial_num;
    $node->field_serial_number['und'][0]['safe_value'] = check_plain($serial_num);
    node_save($node);
    }*/
  }
}

/**
 * This function runs when the batch processing is complete
 */
function customizer_import_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message('Import Completed Successfully');
  } else {
    drupal_set_message('Error while importing');
  }

  // delete csv files
  $files_delete = isset($results['files_delete']) ?
    (array) $results['files_delete']
    : array();

  foreach ($files_delete as $file_id) {
    $file = file_load($file_id);
    file_delete($file, TRUE);
  }
}
