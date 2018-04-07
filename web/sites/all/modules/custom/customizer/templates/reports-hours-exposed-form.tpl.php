<?php //print_r($form); exit; ?>

  <div class="row">
    <div class="col-sm-3">
      <?php print drupal_render($form['date_filter_from']); ?>
    </div>
    <div class="col-sm-3">
      <?php print drupal_render($form['trc_product']); ?>
    </div>
    <div class="col-sm-3">
      <?php print drupal_render($form['payment_type']); ?>
    </div>
    <div class="col-sm-3">
      <?php print drupal_render($form['client']); ?>
    </div>
  </div>
  <div class="row">
    <div class="col-sm-12 submit-btn text-right">
      <?php print drupal_render($form['submit']); ?>
      <?php print drupal_render($form['reset']); ?>
    </div>
  </div>

<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_id']); ?>