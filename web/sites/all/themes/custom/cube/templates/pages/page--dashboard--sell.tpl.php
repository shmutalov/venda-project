<?php 
global $user;


$is_online_enabled = false;
$online_reporting_enabled = config_pages_get('li'.'c'.'ense','field_online_reports',0);

if ($online_reporting_enabled) {
  $receiver_url = config_pages_get('li'.'c'.'ense','field_receiver_url',0);
  $receiver_login = config_pages_get('li'.'c'.'ense','field_receiver_login',0);
  
  if ($receiver_url['url']!='' and $receiver_url and 
      $receiver_login!='' and $receiver_login) {
    $is_online_enabled = true;
  }
  
}

$rate = config_pages_get('li'.'c'.'ense','field_exchange_rate',0);
$last_update = config_pages_get('li'.'c'.'ense','field_rate_last_update',0);

$rate = config_pages_get('li'.'c'.'ense','field_exchange_rate',0);
$show_in_header = config_pages_get('li'.'c'.'ense','field_rate_show',0);
?>
<div class="container-fluid hide-on-print">
  <div class="row page-title-container">
    <div class="col-xs-3 col-sm-4">
      <?php if ($logo): ?>
        <a class="pos-logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('VENDA'); ?>" title="<?php print t('VENDA'); ?>" data-toggle="tooltip" data-placement="bottom"/>
        </a>
      <?php endif; ?>
    </div>
    
    <div class="col-sm-4 col-xs-6  text-center">
			<?php if ($show_in_header): ?>
        <a href="<?php print url('dashboard/settings') ?>"><span class="h5 header-rate visible-xs">1 у.е. = <?php print $rate; ?> сум</span></a>
      <?php endif; ?>
    </div>
    
    <div class="col-sm-4 col-xs-3 text-right">
      <?php if ($show_in_header): ?><span class="h5 header-rate hidden-xs">1 у.е. = <?php print $rate; ?> сум</span><?php endif; ?> 
			
      <?php if ($is_online_enabled): ?>
        <a href="<?php print url('dashboard/reports/send-online', array('query' => array('destination' => 'dashboard/sell'))); ?>" title="<?php print t('Сохранить отчеты в интернете. (Последное сохранение: '.variable_get('last_online_report_time', 'не было').')'); ?>" data-toggle="tooltip" data-placement="bottom" class="hidden-xs">
				<span class="glyphicon glyphicon-cloud-upload"></span>
			</a> &nbsp; 
      <?php endif; ?>
      
      <a href="<?php print url('dashboard/sell'); ?>" title="<?php print t('Обновить кассу F5'); ?>" data-toggle="tooltip" data-placement="bottom" class="hidden-xs"><span class="glyphicon glyphicon-refresh"></span></a>  &nbsp; 
      
      <a href="<?php print url('dashboard/sell'); ?>" target="_blank" title="<?php print t('Открыть новое окно кассы'); ?>" data-toggle="tooltip" data-placement="bottom" class="hidden-xs kassa-new-window"><span class="glyphicon glyphicon-new-window"></span></a>  &nbsp; 
      
      <?php if (in_array('seller', $user->roles)) : ?>
        <a href="<?php print url('user/logout'); ?>" class="sell-process-exit" title="<?php print t('Выйти из программы'); ?>" data-toggle="tooltip" data-placement="bottom"><span class="glyphicon glyphicon-off"></span></a>
      <?php else: ?>
				<a href="<?php print url('<front>'); ?>" class="sell-process-exit pos-exit" title="<?php print t('Выйти из кассы'); ?>" data-toggle="tooltip" data-placement="bottom"><span class="glyphicon glyphicon-off"></span></a>
      <?php endif; ?>
    </div>
  </div>
</div>

<div class="main-container container-fluid">
  <div class="row">
    <section class="col-sm-12">
      <?php print $messages; ?>
      <?php print render($page['content']); ?>
    </section>
  </div>
</div>
<div class="progress sell-progress active hide hide-on-print">
  <div class="progress-bar progress-bar-default"></div>
</div>
