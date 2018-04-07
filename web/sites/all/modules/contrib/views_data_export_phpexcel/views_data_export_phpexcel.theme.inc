<?php

/**
 * @file
 * Theme and preprocess functions.
 */

/**
 * Theme function for header row of XLSX file using PHPExcel.
 */
function theme_views_data_export_xlsx_header(&$vars) {
  _views_data_export_header_shared_preprocess($vars);
  $rows = array($vars['header']);
  $vars['view']->style_plugin->appendRows($rows);
}

/**
 * Theme function for data rows XLSX file using PHPExcel.
 */
function theme_views_data_export_xlsx_body(&$vars) {
  _views_data_export_body_shared_preprocess($vars);
  $rows = $vars['themed_rows'];
  $vars['view']->style_plugin->appendRows($rows);
}
