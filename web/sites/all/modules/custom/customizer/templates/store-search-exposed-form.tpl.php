<?php //print_r($form); exit; ?>

  <div class="row">
    <div class="col-sm-8">
      <?php print drupal_render($form['medicament']); ?>
    </div>
    
    <div class="col-sm-4 search-submits text-right">
      <?php print drupal_render($form['submit']); ?>
      <?php print drupal_render($form['reset']); ?>
    </div>
  </div>

<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_id']); ?>