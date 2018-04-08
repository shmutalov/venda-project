<?php

/**
 * @file
 * PHPExcel style plugin.
 */

class views_data_export_phpexcel_plugin_style_export extends views_data_export_plugin_style_export {
	var $excelCurrentRow = 1;
	var $PHPExcel;
	
  /**
   * Render the display in this style.
   */
  function render() {
    if ($this->uses_row_plugin() && empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }

    $this->render_header();
    $this->render_body();
    $this->render_footer();
  }

  /**
   * Create a new PHP Excel spreadsheet.
   */
  function createPHPExcel() {
    libraries_load('PHPExcel');
    $PHPExcel = new PHPExcel();
    $PHPExcel->setActiveSheetIndex(0);
    return $PHPExcel;
  }

  /**
   * Write the PHP Excel document to the output file path.
   */
  function savePHPExcel() {
    libraries_load('PHPExcel');
    $file_path = drupal_realpath($this->view->display_handler->outputfile_path());
    $writer = PHPExcel_IOFactory::createWriter($this->getPHPExcel(), 'Excel2007');
    $writer->save($file_path);
    // Writer has deleted and re-created the file, so fix permissions now.
    drupal_chmod($file_path);
  }

  /**
   * Get the PHP Excel spreadsheet.
   */
  function getPHPExcel() {
    if (!$this->PHPExcel) {
      $view = $this->view;
      $is_batch = !empty($view->display_handler->batched_execution_state);
      $batch_state = $is_batch ? $view->display_handler->batched_execution_state : NULL;

      if (!$is_batch) {
        $this->PHPExcel = $this->createPHPExcel();
      }
      elseif (empty($batch_state->sandbox['ExcelCurrentRow'])) {
        // This is a batch and it has just started.
        $this->PHPExcel = $this->createPHPExcel();
        $batch_state->sandbox['ExcelCurrentRow'] = 1;
        $this->savePHPExcel();
      }
      else {
        // We have an existing saved excel document. Load it.
        libraries_load('PHPExcel');
        $reader = PHPExcel_IOFactory::createReader('Excel2007');
        $file_path = drupal_realpath($view->display_handler->outputfile_path());
        $this->PHPExcel = $reader->load($file_path);
        $this->PHPExcel->setActiveSheetIndex(0);
        $this->excelCurrentRow = $batch_state->sandbox['ExcelCurrentRow'];
      }
    }
    return $this->PHPExcel;
  }

  /**
   * Append rows to the PHP Excel doc.
   */
  function appendRows(array $rows) {
    $this->getPHPExcel()->getActiveSheet()->fromArray($rows, NULL, 'A' . $this->excelCurrentRow);
    $this->excelCurrentRow += count($rows);
  }

  function render_header() {
    parent::render_header();
    if (!empty($this->view->display_handler->batched_execution_state)) {
      $this->view->display_handler->batched_execution_state->sandbox['ExcelCurrentRow'] = $this->excelCurrentRow;
      $this->savePHPExcel();
    }
  }

  function render_body() {
    parent::render_body();
    if (!empty($this->view->display_handler->batched_execution_state)) {
      $this->view->display_handler->batched_execution_state->sandbox['ExcelCurrentRow'] = $this->excelCurrentRow;
      $this->savePHPExcel();
    }
  }

  function render_footer() {
    parent::render_footer();
    if (!empty($this->view->display_handler->batched_execution_state)) {
      $this->savePHPExcel();
    }
    else {
      ob_start();
      libraries_load('PHPExcel');
      $writer = PHPExcel_IOFactory::createWriter($this->getPHPExcel(), 'Excel2007');
      $writer->save('php://output');
      return ob_get_clean();
    }
  }
}
