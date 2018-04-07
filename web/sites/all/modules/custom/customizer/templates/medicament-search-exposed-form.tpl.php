<?php //print_r($form); exit; ?>
<div class="container">
  <div class="row">
    <div class="col-sm-9">
      <?php print drupal_render($form['title']); ?>
    </div>
    
    <div class="col-sm-3 search-submits text-right">
      <?php print drupal_render($form['submit']); ?>
      <?php print drupal_render($form['reset']); ?>
    </div>
  </div>
</div>

<?php print drupal_render($form['form_build_id']); ?>
<?php print drupal_render($form['form_id']); ?>