<?php

function _customizer_print_product_barcode($form, &$form_state) {
	$product_ID = arg(3);
	$product = node_load($product_ID);

	$form = array();

	if(isset($product->field_md_up_barcode[LANGUAGE_NONE][0]['value'])) {
		$form['product'] = array(
			'#type' => 'hidden',
			'#attributes' => array(
				'class' => array('product-id'),
				),
			'#default_value' => $product_ID,
			);
		$form['product_title'] = array(
			'#type' => 'hidden',
			'#attributes' => array(
				'class' => array('product-title'),
				),
			'#default_value' => $product->title,
			);
		$form['barcode'] = array(
			'#title' => t('Штрих-код'),
			'#type' => 'textfield',
			'#default_value' => $product->field_md_up_barcode[LANGUAGE_NONE][0]['value'],
			);
      
		$form['copy'] = array(
			'#title' => t('Число копии'),
			'#type' => 'textfield',
			'#default_value' => 1,
			);

		$form['submit'] = array(
			'#type' => 'submit',
			'#attributes' => array(
				'class' => array('btn-primary'),
				),
			'#value' => t('Print'),
			'#suffix' => '&nbsp;<a class="btn btn-success" href="' . url('dashboard/warehouse') . '">Назад</a>',
			);
	} else {
    $form['error'] = array(
        '#markup' => t('Штрих-код продукта <em>'.$product->title.'</em> не найдена. '.l(t('Добавить штрих-код'), 'node/'.$product->nid.'/edit', 
                array('query' => 
                    array('destination' => 'dashboard/warehouse/barcode/'.$product->nid,),
                    'attributes' => array(
                        'class' => array('btn', 'btn-primary')
                        )
                    )
                )
                ),
    );
  }

	return $form;
}

function _customizer_print_product_barcode_submit($form, &$form_state) {
	if(isset($form_state['values']['barcode'])) {
		
	}
	drupal_goto("dashboard/warehouse");
}