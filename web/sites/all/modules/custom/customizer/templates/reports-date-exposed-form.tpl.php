<?php //print_r($form); exit;

$price_show = 'sum';
if (isset($_SESSION['price_show'])) {
  if ($_SESSION['price_show']=='ue') {
    $price_show = 'ue';
  }
}
$warehouse_currency = config_pages_get('li'.'c'.'ense','field_currency_warehouse','сум');
$pos_currency = config_pages_get('li'.'c'.'ense','field_currency_pos','сум');

?>
	<?php if ($form['#id']=='views-exposed-form-reports-transactions-page'): ?>
		<div class="row">
			<div class="col-sm-3">
				<?php print drupal_render($form['check_no']); ?>
			</div>
			<div class="col-sm-3">
				<?php print drupal_render($form['seller_select']); ?>
			</div>
			<div class="col-sm-3">
				<?php print drupal_render($form['field_trc_type_value']); ?>
			</div>
			<div class="col-sm-3">
				<?php print drupal_render($form['payment_type']); ?>
			</div>
		</div>
		
		<div class="row">
      <div class="col-sm-6 col-md-4">
        <?php print drupal_render($form['trc_created']); ?>
        <div class="row <?php print ($_GET['trc_created']!=10 ? 'hide ' : ''); ?>exact-date">
           <div class="col-xs-6">
            <?php print drupal_render($form['date_filter_from']); ?>
          </div>
          <div class="col-xs-6">
            <?php print drupal_render($form['date_filter_to']); ?>
          </div>
        </div>
      </div>
     
			<div class="col-sm-6 col-md-3">
				<?php print drupal_render($form['trc_product']); ?>
			</div>
			<div class="col-sm-6 col-md-3">
				<?php print drupal_render($form['client']); ?>
			</div>
			<div class="col-sm-6 col-md-2">
				<?php print drupal_render($form['items_per_page']); ?>
			</div>
		</div>

		<div class="row">
      <div class="col-sm-6 col-sm-offset-6 submit-btn text-right">
        <?php print drupal_render($form['submit']); ?>
        <?php print drupal_render($form['reset']); ?>
        <?php if ($form['#id']=='views-exposed-form-reports-transactions-page' and $warehouse_currency != $pos_currency): ?>
          <?php if ($price_show=='sum'): ?>
            <a href="<?php print url('dashboard/reports', array('query' => array('currency' => 'ue'))); ?>" class="btn btn-warning">Показать в у.е.</a>
          <?php else: ?>
            <a href="<?php print url('dashboard/reports', array('query' => array('currency' => 'sum'))); ?>" class="btn btn-success">Показать в сумах</a>
          <?php endif; ?>
        <?php endif; ?>
      </div>
    </div>

  <?php else: ?>
		<div class="row">
			<div class="col-sm-6 col-md-2">
				<?php print drupal_render($form['date_filter_from']); ?>
			</div>
			<div class="col-sm-6 col-md-2">
				<?php print drupal_render($form['date_filter_to']); ?>
			</div>
			<div class="col-sm-6 col-md-3">
				<?php print drupal_render($form['payment_type']); ?>
			</div>
			<div class="col-sm-6 col-md-3">
				<?php print drupal_render($form['trc_product']); ?>
			</div>
			<div class="col-sm-6 col-md-2">
				<?php print drupal_render($form['client']); ?>
			</div>
      
		</div>

    <div class="row">
      <div class="col-sm-6 col-sm-offset-6 submit-btn text-right">
        <?php print drupal_render($form['submit']); ?>
        <?php print drupal_render($form['reset']); ?>
      </div>
    </div>

	<?php endif; ?>
  
  

<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_id']); ?>