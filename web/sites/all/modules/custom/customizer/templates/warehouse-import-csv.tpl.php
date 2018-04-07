<?php
global $user;
global $language;

$warehouse_currency = config_pages_get('li'.'c'.'ense','field_currency_warehouse','сум');
?>
<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_token']); ?>
<?php print drupal_render($form['form_id']); ?>

<p>Пожалуйста загрузите только CSV файл. Структура файла должна быть такая:</p>
<div class="table-responsive">
<table class="table table-bordered table-striped">
	<thead>
		<tr class="strong">
			<td>
				Название продукта 
				<a href="#" data-toggle="modal" data-target="#product_title_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Штрих-код 
				<a href="#" data-toggle="modal" data-target="#barcode_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Кол. в упаковке 
				<a href="#" data-toggle="modal" data-target="#up_amount_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Производитель 
				<a href="#" data-toggle="modal" data-target="#manufacturer_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Страна производителя 
				<a href="#" data-toggle="modal" data-target="#country_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Дата прибытия 
				<a href="#" data-toggle="modal" data-target="#date_income_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Количество 
				<a href="#" data-toggle="modal" data-target="#amount_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Оптовая цена (<?php print $warehouse_currency; ?>)
				<a href="#" data-toggle="modal" data-target="#opt_price_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Розничная цена (<?php print $warehouse_currency; ?>)
				<a href="#" data-toggle="modal" data-target="#roz_price_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Срок годности 
				<a href="#" data-toggle="modal" data-target="#expire_date_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
			<td>
				Включен 
				<a href="#" data-toggle="modal" data-target="#is_enabled_modal">
					<span class="glyphicon glyphicon-question-sign text-primary"></span>
				</a>
			</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>
				Galaxy S8
			</td>
			<td>
				47028411891
			</td>
			<td>
				1
			</td>
			<td>
				Samsung
			</td>
			<td>
				Южная Корея
			</td>
			<td>
				23.02.2017
			</td>
			<td>
				30
			</td>
			<td>
				800
			</td>
			<td>
				900
			</td>
			<td>
				23.02.2019
			</td>
			<td>
				1
			</td>
		</tr>
	</tbody>
</table>
</div>
<?php
	$template_url = file_create_url('sites/default/files/examples/import-file-sketch_2.csv');
	
	$accept_lang = $_SERVER['HTTP_ACCEPT_LANGUAGE'];
	if ($accept_lang) {
		$ln = explode(',', $accept_lang);
			
		if (in_array($ln[0], array('en-US'))) {
			$template_url = file_create_url('sites/default/files/examples/import-file-sketch.csv');
		}
	}
			
?>
<p>А также, вы можете скачать этого <?php print l(t('шаблона'), $template_url); ?> и заполнить для импорта.</p>

<div class="modal fade" tabindex="-1" role="dialog" id="product_title_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Пожалуйста, не добавляйте количество, и.т.д. к названию.</p>
				<p>Примеры:<br/>
				<p>
					<span class="glyphicon glyphicon-ok text-success"></span> Цитрамон<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> Цитрамон таб 1мг №6<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> Цитрамон таблетка<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> Цитрамон №6<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> Цитрамон 2мг<br/>
				</p>
				<p>После импорта, программа сама будет генерировать полное название.</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="barcode_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Штрих-код должен состоять только из цифр. Минимальная длина штрих-кода - 9 цифр. Пожалуйста, не добавляйте буквы.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 47825724032<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 52625342<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 4556134234УЗ<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> RS1235567274<br/>
				</p>
				<p><strong>Добавлять штрих-код обязательно при импорте! Без штрих-кода система не может различать продукты и в итоге вы можете получить дубликаты.</strong></p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="manufacturer_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Производитель должна соответствовать одной из имеющихся списке. Если производитель отсутствует ниже, она будет добавлена как новая.</p>
				<p>Список производителей:<br/>
					<?php
						$manufacturer = taxonomy_get_tree(9);
						if (count($manufacturer)>0) {
							foreach ($manufacturer as $term) {
								print $term->name.'<br/>';
							}
						}
					?>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="country_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Страна должна соответствовать одной из имеющихся списке. Если страна отсутствует ниже, она будет добавлена как новая.</p>
				<p>Список формы выпуска:<br/>
					<?php
						$country = taxonomy_get_tree(8);
						if (count($country)>0) {
							foreach ($country as $term) {
								print $term->name.'<br/>';
							}
						}
					?>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="up_amount_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Количество в упаковке должно быть только цифры.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 23<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 1<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 5шт<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 20та<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> №15<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> N4<br/>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="date_income_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Формат даты должен быть дд.мм.гггг.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 23.02.2017<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23.02.2017г<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23 февраля<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 02/23/2017<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 2017-02-23<br/>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="amount_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Количество должно быть только цифры.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 23<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 1<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 5шт<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 20та<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> №15<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> N4<br/>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="opt_price_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Оптовая цена должна быть только цифры.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 23500<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23500 сум<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23 500<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23500.00<br/>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="roz_price_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Розничная цена должна быть только цифры.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 23500<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23500 сум<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23 500<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23500.00<br/>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="expire_date_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Формат даты должен быть дд.мм.гггг.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 23.02.2017<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23.02.2017г<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23 февраля<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 23<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 02/23/2017<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> 2017-02-23<br/>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" tabindex="-1" role="dialog" id="is_enabled_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <p>Cостояние продукта. 1 - продукт будет видно в кассовой программе. 0 - продукт НЕ будет видно в кассовой программе.</p>
				<p>Примеры:<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 1<br/>
					<span class="glyphicon glyphicon-ok text-success"></span> 0<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> включен<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> да<br/>
					<span class="glyphicon glyphicon-remove text-danger"></span> +<br/>
				</p>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<?php print drupal_render($form['import_upload']); ?>
<?php print drupal_render($form['actions']); ?>
