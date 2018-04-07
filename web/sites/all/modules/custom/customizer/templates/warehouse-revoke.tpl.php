<?php
global $user;
global $language;
$warehouse_currency = config_pages_get('li'.'c'.'ense','field_currency_warehouse','сум');

?>
<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_token']); ?>
<?php print drupal_render($form['form_id']); ?>

<div class="panel panel-default table-panel">
  <div class="panel-body">
		<table class="table table-striped table-hover warehouse-export-csv">
			<thead>
				<tr class="strong">
					<td width="3%"></td>
					<td width="30%">
						Название продукта
					</td>
					<td width="60%" class="text-center">
						Партии
					</td>
					<td width="7%">
						
					</td>
				</tr>
			</thead>
			<tbody>
				<tr>
					<td class="sorter vmiddle">
						<span class="glyphicon glyphicon-move"></span>
					</td>
					<td class="product-name-search">
						<input type="text" name="products[nid][title]" placeholder="Поиск по названиям/штрих-коду" class="form-control form-text required search-md-input input-sm"/>
            <input type="hidden" name="products[nid][pr_title]" class="product-title"/>
						<span class="glyphicon glyphicon-refresh glyphicon-spin textfield-spin hide"></span>
					</td>
					<td class="product-parts">
						<div class="row.small-col-padding">
							<div class="col-sm-2 small-col-padding pr-amount">
								<input type="text" value="" placeholder="Количество" class="form-control form-text input-sm decimal" disabled="disabled"/>
							</div>
							<div class="col-sm-3 small-col-padding opt-price">
								<input type="text" value="" placeholder="Опт. цена (в <?php print $warehouse_currency; ?>)" class="form-control form-text input-sm" disabled="disabled"/>
							</div>
							<div class="col-sm-3 small-col-padding roz-price">
								<input type="text" value="" placeholder="Роз. цена (в <?php print $warehouse_currency; ?>)" class="form-control form-text input-sm" disabled="disabled"/>
							</div>
							<div class="col-sm-4 small-col-padding date-expire">
                <input type="text" value="" placeholder="Комментарий" disabled="disabled" class="form-control form-text input-sm" maxlength="100"/>
							</div>
						</div>
					</td>
					<td class="vmiddle action-links">
						<a href="#" target="_blank" title="Редактировать продукт (откроется в новом окне)" class="edit-product"><span class="glyphicon glyphicon-edit text-warning"></span></a> 
						<a href="#" title="Удалить строку" class="remove-row"><span class="glyphicon glyphicon-remove text-danger"></span></a> 
					</td>
				</tr>
			</tbody>
		</table>
	</div>
</div>

<?php print render($form['remove_exported_batches']); ?>
<?php print render($form['ignore_empty_packages']); ?>

<div class="warehouse-export-csv-actions">
	<button type="button" name="op" value="Создать CSV файл" class="btn btn-success form-submit">Списать выбранных товаров</button>
</div>