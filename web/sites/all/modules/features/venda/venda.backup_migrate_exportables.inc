<?php
/**
 * @file
 * venda.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function venda_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'manual';
  $item->name = 'Папка для ручного копирования';
  $item->subtype = 'file_manual';
  $item->location = '../database-backups/manual';
  $item->settings = array(
    'chmod' => '',
    'chgrp' => '',
  );
  $export['manual'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'scheduled';
  $item->name = 'Папка для копирования по расписанию';
  $item->subtype = 'file_scheduled';
  $item->location = '../database-backups/scheduled';
  $item->settings = array(
    'chmod' => '',
    'chgrp' => '',
  );
  $export['scheduled'] = $item;

  return $export;
}
