
  <div class="row">
    <div class="col-sm-3">
      <?php print drupal_render($form['title']); ?>
    </div>
    <div class="col-sm-2">
      <?php print drupal_render($form['field_md_up_barcode_value']); ?>
    </div>
    <div class="col-sm-2">
      <?php print drupal_render($form['items_per_page']); ?>
    </div>
    <div class="col-sm-2">
      <?php print drupal_render($form['status']); ?>
    </div>
    <div class="col-sm-3">
      <?php print drupal_render($form['submit']); ?>
      <?php print drupal_render($form['reset']); ?>
    </div>
  </div>
  
<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_id']); ?>