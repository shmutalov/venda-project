<?php
global $user;
global $language;
$contracts = $form['#contracts'];
$providers = $form['#providers'];
$warehouse_currency = config_pages_get('li'.'c'.'ense','field_currency_warehouse','сум');


?>
<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_token']); ?>
<?php print drupal_render($form['form_id']); ?>

    <div class="form-inline waybill-header margin-bottom-30">
      <div class="form-group">
        <label for="waybill_no">Накладная №</label>
        <input type="text" name="waybill_no" class="form-control input-sm" id="waybill_no" maxlength="10"/> &nbsp; &nbsp; 
      </div>
      
      <div class="form-group">
        <label for="waybill_date">от </label>
        <input type="text" name="waybill_date" id="waybill_date" value="<?php print date('d.m.Y'); ?>" placeholder="дата прибытия" class="form-control input-sm"/> &nbsp; &nbsp; 
      </div>
      
      <div class="form-group">
        <label for="providers"></label>
        <select class="form-control input-sm provider-nid" name="provider_nid">
          <option value="0"> - поставщик - </option>
          <?php foreach ($providers as $nid => $provider): ?>
          <option value="<?php print $nid; ?>"><?php print $provider; ?></option>
          <?php endforeach; ?>
        </select>
      </div>
      
      <div class="form-group">
        <label for="contract_no"></label>
        <select class="form-control input-sm contract-nid" name="contract_nid">
          <option value="0"> - договор - </option>
          <?php foreach ($contracts as $nid => $contract): ?>
          <option value="<?php print $nid; ?>"><?php print $contract; ?></option>
          <?php endforeach; ?>
        </select>
      </div>
      
    </div>

<div class="panel panel-default table-panel">
  <div class="panel-body">
		<table class="table table-striped table-hover  warehouse-waybill">
			<thead>
				<tr class="strong">
          <td width="0" class="hide"></td>
					<td width="34%">
						Название продукта
					</td>
					<td width="15%">
						Штрих-код
					</td>
					<td width="48%" class="text-center">
						Партии
					</td>
					<td width="3%">
						
					</td>
				</tr>
			</thead>
			<tbody>
				<?php for ($i=0; $i<10; $i++): ?>
        <tr>
					<td class="sorter hide">
						<span class="glyphicon glyphicon-move"></span>
            <input type="hidden" class="product-nid" name="products[<?php print $i; ?>][nid]" value="0"/>
					</td>
					<td class="product-name-search">
            <input type="text" name="products[<?php print $i; ?>][title]" placeholder="Поиск по названиям/штрих-коду" class="form-control form-text required search-md-input input-sm" maxlength="120"/>
						<span class="glyphicon glyphicon-refresh glyphicon-spin textfield-spin hide"></span>
					</td>
          <td class="product-barcode-search">
						<input type="text" name="products[<?php print $i; ?>][barcode]" placeholder="Штрих-код" class="form-control form-text required product-barcode input-sm integer" maxlength="14"/>
					</td>
					<td class="product-parts">
						<div class="row small-col-padding">
							<div class="col-sm-3 small-col-padding pr-amount">
								<input type="text" value="" placeholder="Количество" class="form-control form-text input-sm decimal" name="products[<?php print $i; ?>][pr_amount]"/>
							</div>
							<div class="col-sm-3 small-col-padding opt-price">
								<input type="text" value="" placeholder="Опт.цена(<?php print $warehouse_currency; ?>)" class="form-control form-text input-sm decimal" name="products[<?php print $i; ?>][opt_price]"/>
							</div>
							<div class="col-sm-3 small-col-padding roz-price">
								<input type="text" value="" placeholder="Роз.цена(<?php print $warehouse_currency; ?>)" class="form-control form-text input-sm decimal" name="products[<?php print $i; ?>][roz_price]"/>
							</div>
							<div class="col-sm-3 small-col-padding date-expire">
								<input type="text" value="" placeholder="Срок годности" class="form-control form-text input-sm" name="products[<?php print $i; ?>][date_expire]"/>
							</div>
						</div>
					</td>
					<td class="vmiddle action-links">
						<a href="#" title="Удалить строку" class="remove-row"><span class="glyphicon glyphicon-remove text-danger"></span></a> 
					</td>
				</tr>
        <?php endfor; ?>
			</tbody>
		</table>
    <div class="add-new-rows"><a href="#" class="add-new-rows-link btn btn-info btn-sm">Добавить ещё 10 строк</a></div>
	</div>
</div>

<?php print render($form['remove_exported_batches']); ?>
<?php print render($form['ignore_empty_packages']); ?>

<div class=" warehouse-waybill-actions">
	<button type="button" name="op" value="Создать CSV файл" class="btn btn-success form-submit">Сохранить</button>
</div>