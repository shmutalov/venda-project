<?php
 global $user;
 
 if (!isset($_COOKIE['menu_opened'])) {
	 $_COOKIE['menu_opened'] = false;
 }
 
 $rate = config_pages_get('li'.'c'.'ense','field_exchange_rate',0);
 $show_in_header = config_pages_get('li'.'c'.'ense','field_rate_show',0);
 
?>
<div class="container-fluid">
	
	<div class="row page-title-container">
		<div class="col-sm-4 col-xs-3">
		
			<?php if (user_is_warehouse_manager()): ?>
				<div class="sidebar-menu-toggle pull-left<?php print ($_COOKIE['menu_opened'] ? ' opened' : ''); ?>">
					<span class="glyphicon <?php print ($_COOKIE['menu_opened'] ? ' glyphicon-remove' : 'glyphicon-menu-hamburger'); ?>"></span>
				</div>	
			<?php else: ?>
				<a class="pos-logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('VENDA'); ?>" title="<?php print t('VENDA'); ?>" data-toggle="tooltip" data-placement="bottom"/>
        </a>
			<?php endif; ?>
		</div>
		
		<div class="col-sm-4 col-xs-6  text-center">
			<?php if (user_is_warehouse_manager()): ?>
        <img src="<?php print $logo; ?>" title="<?php print t('VENDA'); ?>" data-toggle="tooltip" data-placement="bottom" class="hidden-xs"/>
			<?php endif; ?>
      <?php if ($show_in_header && $logged_in): ?>
        <a href="<?php print url('dashboard/settings') ?>"><span class="h5 header-rate visible-xs">1 у.е. = <?php print $rate; ?> сум</span></a>
      <?php endif; ?>
        
		</div>
		
		<div class="col-sm-4 col-xs-3 text-right">
			<?php if ($logged_in): ?>
				<div class="text-right">
          <a href="<?php print url('dashboard/settings') ?>"><span class="h5 header-rate hidden-xs<?php if (!$show_in_header): ?> hide<?php endif; ?>">1 у.е. = <?php print $rate; ?> сум</span></a>
          <a href="<?php print url('user/logout'); ?>" class="sell-process-exit" title="<?php print t('Выйти из системы'); ?>" data-toggle="tooltip" data-placement="bottom"><span class="glyphicon glyphicon-off"></span></a>
				</div>
			<?php endif; ?>
		</div>
	</div>
		
</div>
		
<?php if ($logged_in): ?>
	<div id="sidedrawer" class="<?php print (($_COOKIE['menu_opened']) ? ' op' : ''); ?>">
		<?php if (!empty($page['sidebar_first'])): ?>
			<aside class="sidebar-menu" role="complementary">
				<?php print render($page['sidebar_first']); ?>
			</aside>  <!-- /#sidebar-first -->
		<?php endif; ?>
</div>
<?php endif; ?>

<div id="wrapper">

	<div class="main-container container-fluid">
	
		<div class="row">
			
			<section class="col-sm-12 main-section">
				<a id="main-content"></a>
				<h1 class="page-header">
          <div class="row">
            <?php if (arg(1)=='warehouse' and arg(2)==''): ?>
              <div class="col-sm-6">
                <?php print $title; ?>
              </div>
              <div class="col-sm-6 text-right">
                <a href="<?php print url('dashboard/warehouse/apply', array('query' => array('destination' => 'dashboard/warehouse'))); ?>" class="btn btn-primary">Поступление по накладной</a>
                <a href="<?php print url('dashboard/warehouse/add-new', array('query' => array('destination' => 'dashboard/warehouse'))); ?>" class="btn btn-success">Добавить новый продукт</a>
              </div>
            <?php else: ?>
              <div class="col-sm-12">
                <?php print $title; ?>
              </div>
            <?php endif; ?>
          </div>
        </h1>
				<?php print $messages; ?>
				<?php if (!empty($tabs)): ?>
					<?php print render($tabs); ?>
				<?php endif; ?>
				<?php print render($page['content']); ?>
			</section>

		</div>
		
	</div>

</div>
<div class="progress sell-progress active hide">
  <div class="progress-bar progress-bar-default"></div>
</div>

<div class="menu-overlay hide fade"></div>
