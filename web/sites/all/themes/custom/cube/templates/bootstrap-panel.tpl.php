<div <?php print $attributes; ?>>
  <div class="panel-heading h4"><?php print $title; ?></div>
  <div class="panel-body table-responsive">
    <?php if ($description): ?><div class="help-block"><?php print $description; ?></div><?php endif; ?>
    <?php print $content; ?>
  </div>
</div>
