<?php

function _customizer_print_a4_barcode($form, &$form_state) {
	$product_ID = arg(4);
	$copy = arg(5);
	$product = node_load($product_ID);

	$form = array();

	if(isset($product->field_md_up_barcode[LANGUAGE_NONE][0]['value'])) {
		$barcode_img_name = barcode_print(
			$product->field_md_up_barcode[LANGUAGE_NONE][0]['value'],
			1,
			$product->title,
			false
			);

		$markup = "<div class='print_me' style='text-align: center; background: #fff; overflow: hidden; width: 595px;'>";
		for($i = 0; $i < $copy; $i++) {
			$markup .= "<table border=0 style='float:left; margin-right: 4px;'>";
				$markup .= "<tr>";
					$markup .= "<td>";
						$markup .= '<p style="margin:0;font-size: 9px; margin-bottom: 2px;">' . $product->title . '</p>';
						$markup .= '<img src="/' . drupal_get_path("module", "customizer") . '/includes/' . $barcode_img_name . '.bmp" width="150px">';
					$markup .= '</td>';
				$markup .= '</tr>';
			$markup .= '</table>';
		}
		$markup .= '</div><br>';

		$form['markup'] = array(
			'#type' => 'markup',
			'#markup' => $markup,
			);

		sleep(1);

		drupal_add_js('jQuery(document).ready(function () {
			var content = jQuery(".print_me").html();
			w = window.open();
			w.document.write(content);
			w.print();
			w.close();
		});', 'inline');

		//drupal_goto("dashboard/warehouse");

		$form['submit'] = array(
			'#type' => 'submit',
			'#attributes' => array(
				'class' => array('btn-primary print-barcode-a4'),
				),
			'#value' => t('Print'),
			);
	}

	return $form;
}

function _customizer_print_a4_barcode_submit($form, &$form_state) {
	if(isset($form_state['values']['barcode'])) {
		barcode_print($form_state['values']['barcode'], $form_state['values']['copy'], $form_state['values']['product_title']);
		drupal_goto("dashboard/warehouse");
	}
}