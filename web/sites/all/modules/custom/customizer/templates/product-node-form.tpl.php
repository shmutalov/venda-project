<?php
$node = $form['#node'];
$is_create_form = !isset($node->nid) || isset($node->is_new);
$app_type = config_pages_get('li'.'c'.'ense','field_st_app_type',0);

global $user;
global $language;

$rate = config_pages_get('li'.'c'.'ense','field_exchange_rate',0);
$warehouse_currency = config_pages_get('li'.'c'.'ense','field_currency_warehouse','сум');
$pos_currency = config_pages_get('li'.'c'.'ense','field_currency_pos','сум');
$rate_round = config_pages_get('li'.'c'.'ense','field_rate_round',1);
$rate_round_side = config_pages_get('li'.'c'.'ense','field_rate_round_side','round');

?>
<div class="panel panel-default product-medicament-container">
  <div class="panel-heading h4"><?php print t('Параметры упаковки'); ?></div>
  <div class="panel-body">
    <div class="row">
      <div class="col-sm-6 col-md-3 col-lg-3">
        <?php print drupal_render($form['field_pr_medicament_title']); ?>
      </div>
      <div class="col-sm-2 col-md-6 col-lg-2">
        <?php print drupal_render($form['field_md_up_barcode']); ?>
      </div>
      <div class="col-sm-6 col-md-2 col-lg-2">
        <?php echo drupal_render($form['field_md_up_amount']); ?>
      </div>
			<div class="col-sm-6 col-md-3 col-lg-3">
				<?php echo drupal_render($form['field_pr_manufacturer']); ?>
			</div>
			<div class="col-sm-6 col-md-3 col-lg-2">
				<?php echo drupal_render($form['field_pr_mn_country']); ?>
			</div>
		</div>
		
		<div class="row">
			<div class="col-sm-6 col-md-8 col-lg-8">
				<h4 class="product-title-generate"><span class="product-title-sp">_____________________________</span></h4>
				<div class="hide"><?php print drupal_render($form['title']); ?></div>
			</div>
			<div class="col-sm-6 col-md-offset-2 col-md-2 col-lg-2">
        <div class="btn-group btn-block" data-toggle="buttons">
          <label class="btn btn-block product-status<?php if ($form['options']['status']['#default_value']): ?> active<?php endif; ?>" data-toggle="tooltip" data-original-title="Cостояние продукта. Включен - продукт будет видно в кассовой программе. Выключен - продукт НЕ будет видно в кассовой программе. Если вы уже не продаёте этого продукта, но вам нужны отчеты об этом продукте, Вы можете отключить.">
						<?php
							show($form['options']['status']);
							$form['options']['status']['#theme_wrappers'] = array();
							echo drupal_render($form['options']['status']);
						?>
						<span><?php echo $form['options']['status']['#default_value'] ? 'Вкл' : 'Выкл'; ?></span>
          </label>
        </div>
      </div>
		</div>
    
		
  </div>
</div>

<?php
$batches = NULL;
$batches_delete = array();
$batches_errors = array();
$batches_check_errors = FALSE;

if (isset($form['batches']['#value']) && is_array($form['batches']['#value'])) {
  $batches = $form['batches']['#value'];

  if ($batches !== NULL) {
    $batches_check_errors = TRUE;
  }
}

if (isset($form['batches_delete']['#value']) && is_array($form['batches']['#value'])) {
  $batches_delete = $form['batches_delete']['#value'];
}

if (isset($form['batches_errors']['#value'])) {
  $batches_errors = $form['batches_errors']['#value'];
}


//Get providers list
$providers_array = array();
$providers = views_get_view('providers_as_list');
if ($providers) {
  if ($providers->set_display('default')) {
    $providers->set_arguments(array($user->uid));
    $providers->pre_execute();

		if ($providers->execute() !== FALSE) {
      
      foreach ($providers->result as $view_row) {
				$providers_array[$view_row->nid] = $view_row->node_title;
      }
		}
  }

  $providers->destroy();
}
unset($providers);



//Get waybills list
$waybills_array = array();
$waybills = views_get_view('waybills');
if ($waybills) {
  if ($waybills->set_display('default')) {
    $waybills->pre_execute();

		if ($waybills->execute() !== FALSE) {
      
      foreach ($waybills->result as $view_row) { //print_r($view_row); exit;
				$waybills_array[$view_row->node_field_data_field_dg_provider_nid . '-' . $view_row->nid] = $view_row->node_title.' по дог. ' .
                $view_row->node_field_data_field_wb_contract_no_title .
                ' от ' . strip_tags($view_row->field_field_dg_date[0]['rendered']['#markup']) . 
                ' - ' . $view_row->node_field_data_field_dg_provider_title;
      }
		}
  }

  $waybills->destroy();
}
unset($waybills);



if ($app_type=='server') {
  //Get branches list
  $branches_array = array();
  $branches = views_get_view('branches');
  if ($branches) {
    if ($branches->set_display('block_1')) {
      $branches->set_arguments(array($user->uid));
      $branches->pre_execute();

      if ($branches->execute() !== FALSE) {

        foreach ($branches->result as $view_row) {
          $branches_array[$view_row->nid] = $view_row->node_title;
        }
      }
    }

    $branches->destroy();
  }
  unset($branches);
}


// Show on node_edit_form batches if this form wasn't submitted before
if (!$is_create_form && $batches === NULL) {
  $batches = array();
  $view_batch = views_get_view('product_batches');

  if ($view_batch) {
    if ($view_batch->set_display('block')) {
      $view_batch->set_arguments(array($node->nid));
      $view_batch->pre_execute();

      if ($view_batch->execute() !== FALSE) {
        foreach ($view_batch->result as $view_row) { 
          $batch_el = array();
					
          $batch_el['nid'] = isset($view_row->nid) ? $view_row->nid : '';
          $batch_el['field_pr_provider'] = isset($view_row->field_field_pr_provider[0]['raw']['nid']) ?
            $view_row->field_field_pr_provider[0]['raw']['nid']
            : '';
          $batch_el['field_pr_branch'] = isset($view_row->field_field_pr_branch[0]['raw']['nid']) ?
            $view_row->field_field_pr_branch[0]['raw']['nid']
            : '';
          $batch_el['field_pr_income_date'] = isset($view_row->field_field_pr_income_date[0]['raw']['value']) ?
            date('d.m.Y',strtotime($view_row->field_field_pr_income_date[0]['raw']['value']))
            : '';
					$batch_el['field_pr_expiry_date'] = isset($view_row->field_field_pr_expiry_date[0]['raw']['value']) ?
            date('d.m.Y',strtotime($view_row->field_field_pr_expiry_date[0]['raw']['value']))
            : '';
          $batch_el['field_pr_amount'] = isset($view_row->field_field_pr_amount[0]['raw']['value']) ?
            $view_row->field_field_pr_amount[0]['raw']['value']
            : '';
          $batch_el['field_pr_waybill_no'] = isset($view_row->field_field_pr_waybill_no[0]['raw']['nid']) ?
            $view_row->field_field_pr_waybill_no[0]['raw']['nid']
            : '';
          $batch_el['field_pr_price'] = isset($view_row->field_field_pr_price[0]['raw']['value']) ?
            $view_row->field_field_pr_price[0]['raw']['value']
            : '';
          $batch_el['field_pr_price_base'] = isset($view_row->field_field_pr_price_base[0]['raw']['value']) ?
            $view_row->field_field_pr_price_base[0]['raw']['value']
            : '';
          $batches[] = $batch_el;
        }

        unset($view_row, $batch_el);
      }
    }

    $view_batch->destroy();
  }

  unset($view_batch);
}

if (!$batches) {
  $batches[] = array(
    'nid' => '',
    'field_pr_branch' => '',
    'field_pr_provider' => '',
    'field_pr_provider_other' => '',
    'field_pr_income_date' => '',
    'field_pr_amount' => '0',
    'field_pr_waybill_no' => '',
    'field_pr_expiry_date' => '',
    'field_pr_price' => '',
    'field_pr_price_base' => '',
  );
}

?>

<div class="panel panel-default product-parts-container">
  <div class="panel-heading h4"><?php print t('Партии'); ?> (<a href="#" data-content="Партия это группа продуктов одного наименования. Цены могут быть разные для нескольких партий. В кассовой программе цена продукта будет определяться в зависимости от партии, к которой она принадлежит. Выделенная партия (обычно она первая) в списке всегда будет продаваться первой. Чтобы поменять местами партии, используйте <span class='glyphicon glyphicon-move'></span> значок." data-toggle="popover" data-html="true" data-placement="bottom">что это?</a>)</div>
  <div class="panel-body table-responsive">
    <div class="row">
      <div class="col-md-12">
        <div class="h4">Розничная цена в кассе: <span class="product-single-price"><?php print $batches[0]['field_pr_price']; ?></span> <?php print $pos_currency; ?></div>
        <?php if ($pos_currency!=$warehouse_currency): ?>
        <div class="text-muted h5">Курс: 1 у.е. = <span class="current-rate"><?php print $rate; ?></span> сум
          <span class="hide warehouse-currency"><?php print $warehouse_currency; ?></span>
          <span class="hide pos-currency"><?php print $pos_currency; ?></span>
          <span class="hide rate-round"><?php print $rate_round; ?></span>
          <span class="hide rate-round-side"><?php print $rate_round_side; ?></span>
        </div>
        <?php endif; ?>
        <hr class="visible-sm visible-xs"/>
      </div>
      
    </div>
    <hr/>
		<div class="table-responsive">
			<table class="product-parts-table table table-condensed">
				<thead>
					<tr>
						<th></th>
						<?php if ($app_type=='server' and $node->nid): ?><th>Филиал</th><?php endif; ?>
						<th>Поставщик</th>
            <th>Накладная №</th>
            <th>Кол-во <span class="required text-danger" data-toggle="tooltip" data-original-title="Обязательное поле" data-placement="top">*</span></th>
						<th>Опт. цена(в <?php print $warehouse_currency; ?>) <span class="required text-danger" data-toggle="tooltip" data-original-title="Обязательное поле" data-placement="top">*</span></th>
						<th>Роз. цена(в <?php print $warehouse_currency; ?>) <span class="required text-danger" data-toggle="tooltip" data-original-title="Обязательное поле" data-placement="top">*</span></th>
						<th>Дата прибытия <span class="required text-danger" data-toggle="tooltip" data-original-title="Обязательное поле" data-placement="top">*</span></th>
						<th>Срок годности</th>
						<th></th>
					</tr>
				</thead>
				<tbody>
					<?php foreach ($batches as $i => $val): ?>
						<?php
						$val_errors = $batches_check_errors && isset($batches_errors[$i]) ?
							$batches_errors[$i]
							: NULL;
						?>
						<tr>
							<td class="sorter h5" width="2%">
								<span class="glyphicon glyphicon-move"></span>
								<input type="hidden" value="<?php echo check_plain($val['nid']) ?>" name="batches[nid][]" class="product-parts-nid">
							</td>
              <?php if ($app_type=='server' and $node->nid): ?>
                <td width="12%">
                  <div class="select-branch">
                    <select class="form-control" name="batches[field_pr_branch][]" data-toggle="tooltip" data-original-title="Выберите подходящего филиала">
                      <option value="_none"> - Филиал - </option>
                      <?php 
                      if (count($branches_array)>0) {
                        foreach ($branches_array as $pid => $prov) {
                          print '<option value="'.$pid.'"'.($val['field_pr_branch']==$pid ? ' selected="selected"' : '').'>'.$prov.'</option>';
                        }
                      }
                      ?>
                    </select>
                  </div>
                </td>
              <?php endif; ?>
							<td width="<?php print ($app_type=='server' ? '12' : '24'); ?>%">
								<div class="select-provider">
									<select class="form-control" name="batches[field_pr_provider][]" data-toggle="tooltip" data-original-title="Выберите поставщика">
										<option value="_none"> - Поставщик - </option>
										<?php 
										if (count($providers_array)>0) {
											foreach ($providers_array as $pid => $prov) {
												print '<option value="'.$pid.'"'.($val['field_pr_provider']==$pid ? ' selected="selected"' : '').'>'.$prov.'</option>';
											}
										}
										?>
										<option value="other">Другой</option>
									</select>
									<input type="text" maxlength="30" name="batches[field_pr_provider_other][]" class="form-control select-other-input hide <?php if (isset($val_errors['field_pr_provider_other'])): ?> error<?php endif; ?>" data-toggle="tooltip" data-original-title="Напишите названию поставщика" placeholder="Название поставщика">
								</div>
							</td>
              <td width="12%">
                <div class="select-waybill">
									<select class="form-control" name="batches[field_pr_waybill_no][]" data-toggle="tooltip" data-original-title="Накладная №">
										<option value="0"> - Накладная № - </option>
										<?php 
										if (count($waybills_array)>0) {
											foreach ($waybills_array as $wid => $waybill) {
                        $wb_parts = explode('-', $wid);
                        $waybill_nid = $wb_parts[1];
                        
												print '<option value="'.$wid.'"'.($val['field_pr_waybill_no']==$waybill_nid ? ' selected="selected"' : '').'>'.$waybill.'</option>';
											}
										}
										?>
									</select>
								</div>
							</td>
							<td width="6%">
								<input type="text" maxlength="10" value="<?php echo check_plain($val['field_pr_amount']); ?>" name="batches[field_pr_amount][]" id="" class="product-package-qty decimal form-control<?php if (isset($val_errors['field_pr_amount'])): ?> error<?php endif; ?>">
							</td>
							<td width="12%">
								<input type="text" maxlength="10" value="<?php echo check_plain($val['field_pr_price_base']); ?>" name="batches[field_pr_price_base][]" id="" data-toggle="tooltip" class="form-control product-opt-price decimal<?php if (isset($val_errors['field_pr_price_base'])): ?> error<?php endif; ?>" data-original-title="Оптовая цена (в <?php print $warehouse_currency; ?>). Оптовая цена нужна чтобы посчитать прибыль от продукта.">
							</td>
							<td class="form-item" width="12%">
								<input type="text" maxlength="10" value="<?php echo check_plain($val['field_pr_price']); ?>" name="batches[field_pr_price][]" id="" class="product-package-price form-control decimal integer-percent<?php if (isset($val_errors['field_pr_price'])): ?> error<?php endif; ?>" data-toggle="tooltip" data-original-title="Цена одного продукта (в <?php print $warehouse_currency; ?>)">
							</td>
							<td width="12%">
								<input type="text" maxlength="10" value="<?php echo ($val['field_pr_income_date']!='' ? check_plain($val['field_pr_income_date']) : date('d.m.Y')); ?>" name="batches[field_pr_income_date][]" id="" class="form-control income-date-field date-validate <?php if (isset($val_errors['field_pr_income_date'])): ?> error<?php endif; ?>" data-toggle="tooltip" data-original-title="Формат: дд.мм.гггг">
							</td>
							<td width="12%">
								<input type="text" maxlength="10" value="<?php echo check_plain($val['field_pr_expiry_date']); ?>" name="batches[field_pr_expiry_date][]" id="" class="form-control expiry-date-field date-validate <?php if (isset($val_errors['field_pr_expiry_date'])): ?> error<?php endif; ?>" data-toggle="tooltip" data-original-title="Формат: дд.мм.гггг">
							</td>
							<td width="2%">
								<a class="h5 remove-line-item" href="#"><span class="glyphicon glyphicon-remove-sign text-danger"></span></a>
							</td>
						</tr>
					<?php endforeach; ?>
				</tbody>
			</table>
		</div>
    <div class="part-actions"><a href="#" class="btn btn-primary btn-sm product-parts-add-row"><?php print t('Добавить новую строку'); ?></a></div>
  </div>
  <div class="products-parts-delete-nids">
    <?php foreach ($batches_delete as $val): ?>
      <input type="hidden" name="batches_delete[]" value="<?php echo check_plain($val); ?>">
    <?php endforeach; ?>
  </div>
</div>


<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_token']); ?>
<?php print drupal_render($form['form_id']); ?>
<?php print drupal_render($form['additional_settings']); ?>
<?php print drupal_render($form['options']); ?>
<?php print drupal_render($form['author']); ?>
<?php print drupal_render($form['revision_information']); ?>

<?php if ($is_create_form): ?>
  <button class="btn btn-success form-submit product-submit" id="edit-submit" name="op" value="<?php print t('Save'); ?>" type="submit" data-toggle="tooltip" data-placement="top" title="<?php print t('Создадим новый продукт'); ?>"><?php print t('Save'); ?></button>
<?php else : ?>
  <button class="btn btn-success form-submit product-submit" id="edit-submit" name="op" value="<?php print t('Save'); ?>" type="submit" data-toggle="tooltip" data-placement="top" title="<?php print t('Сохраним изменения и вернемся на списку продуктов'); ?>"><?php print t('Save'); ?></button>
  <?php $destination = isset($_GET['destination']) ? drupal_get_destination() : array('destination' => 'dashboard/warehouse'); ?>
  <a class="btn btn-danger form-submit product-submit" href="<?php print url('node/'.$node->nid.'/delete', array('query' => $destination)); ?>" data-toggle="tooltip" data-placement="top" title="<?php print t('Удалим продукт и вся информация о продаже этого продукта'); ?>"><?php print t('Delete'); ?></a>
<?php endif; ?>

<?php if (isset($_GET['destination'])): ?>
	<a class="btn btn-warning form-submit product-submit" href="<?php print base_path().$language->prefix.'/'.$_GET['destination']; ?>" data-toggle="tooltip" data-placement="top" title="<?php print t('Отменим изменения и вернемся на списку продуктов'); ?>"><?php print t('Отменить'); ?></a>
<?php else: ?>
	<a class="btn btn-warning form-submit product-submit" href="<?php print url('dashboard/warehouse'); ?>" data-toggle="tooltip" data-placement="top" title="<?php print t('Отменим изменения и вернемся на списку продуктов'); ?>"><?php print t('Отменить'); ?></a>
<?php endif; ?>
<br/><br/><br/>