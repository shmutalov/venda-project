<?php
	$nav_tab = false;
	if (isset($_COOKIE['nav_tab'])) {
		$nav_tab = $_COOKIE['nav_tab'];
	}
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <ul class="nav nav-tabs" role="tablist">
    <li role="presentation" class="active"><a href="#chart" aria-controls="chart" role="tab" data-toggle="tab">Диаграмма</a></li>
    <li role="presentation"><a href="#table" aria-controls="table" role="tab" data-toggle="tab">Таблица</a></li>
  </ul>

  <!-- Tab panes -->
  <div class="tab-content">
    <div role="tabpanel" class="tab-pane active" id="chart">
      <?php if ($attachment_before): ?>
        <div class="attachment attachment-before">
          <?php print $attachment_before; ?>
        </div>
      <?php endif; ?>
    </div>
    <div role="tabpanel" class="tab-pane" id="table">
      <?php if ($rows): ?>
        <div class="view-content">
          <?php print $rows; ?>
        </div>
      <?php elseif ($empty): ?>
        <div class="view-empty">
          <?php print $empty; ?>
        </div>
      <?php endif; ?>
      
      <?php if ($pager): ?>
        <?php print $pager; ?>
      <?php endif; ?>
      
    </div>
  </div>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
			<a href="#" class="print-page" title="<?php print t('Печатать'); ?>">
				<img src="<?php print base_path().drupal_get_path('theme', 'cube'); ?>/images/printer-icon.png"/>
			</a>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>