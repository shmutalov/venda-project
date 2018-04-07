<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="panel panel-default transactions-container <?php print isset($_COOKIE['transactions_container']) ? $_COOKIE['transactions_container'] : ''; ?>">
  <div class="panel-heading">
    <div class="row">
      <div class="col-sm-6 h4 tr-header-title">
        <?php 
        if (!isset($_GET['date'])) {
          print t('Сегодняшние продажи'); 
        } else {
          print t('Продажи в '.$_GET['date']);
        }
        ?> 
        <a href="#" class="transactions-save-all btn btn-primary"><?php print t('Сохранить все'); ?></a></div>
      <div class="col-sm-6">
        <div class="tr-date-filter text-right">
          <form class="form-inline">
            <div class="form-group">
              <input type="text" maxlength="10" placeholder="<?php print t('Дата') ?>" value="<?php print (isset($_GET['date']) ? $_GET['date'] : ''); ?>" class="form-control tr-date-filter-input input-sm" name="date"/>
            </div>
            <div class="form-group">
              <button type="submit" class="btn btn-primary btn-tr-date-search btn-sm"><?php print t('Поиск'); ?></button>
              <a href="<?php print url('dashboard/sell'); ?>" class="btn btn-default btn-sm"><?php print t('Отменить'); ?></a>
            </div>
          </form>
          
        </div>
      </div>
    </div>
    
  </div>
  <div class="panel-body table-responsive">
    <?php if ($exposed): ?>
      <div class="view-filters">
        <?php print $exposed; ?>
      </div>
    <?php endif; ?>
    
    <?php if ($rows): 
			print $rows; 
		else: 
			print $empty;
		endif; ?>
  </div>
</div>

<?php if ($pager): ?>
  <?php print $pager; ?>
<?php endif; ?>