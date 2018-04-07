<?php 
$roz = $fields['field_trc_price']->content;
$opt = $fields['field_trc_price_base']->content;
$check_amount = $fields['nid']->content;
$cash = $fields['field_trc_payment_cash']->content;
$terminal = $fields['field_trc_payment_terminal']->content;
$owe = $fields['field_trc_payment_owe']->content;
$prib = $roz - $opt;
$average_check = $roz / $check_amount;

$enc_amount = 0;

$inc_output = '';
$date_from = $date_to = false;
$exposed_input = array();

if (isset($_SESSION['views']['reports_transactions']['default']['date_filter_from']['value']) and isset($_SESSION['views']['reports_transactions']['default']['date_filter_to']['value'])) {
	$date_from = $_SESSION['views']['reports_transactions']['default']['date_filter_from']['value'];
	$date_to = $_SESSION['views']['reports_transactions']['default']['date_filter_to']['value'];
	$inc_output = ' ('.date('d.m.Y', strtotime($date_from)).' - '.date('d.m.Y', strtotime($date_to)).')';
	
	
} elseif (isset($_SESSION['views']['reports_transactions']['default']['date_filter_from']['value'])) {
	$date_from = $_SESSION['views']['reports_transactions']['default']['date_filter_from']['value'];
	$inc_output = ' ('.date('d.m.Y', strtotime($date_from)).')';
} elseif (isset($_SESSION['views']['reports_transactions']['default']['date_filter_to']['value'])) {
	$date_to = $_SESSION['views']['reports_transactions']['default']['date_filter_to']['value'];
	$inc_output = ' ('.date('d.m.Y', strtotime($date_to)).')';	
}

$encashment = views_get_view('encashment');
if ($encashment) {
	if ($encashment->set_display('block_1')) {
		
		
		
		if ($date_from) {
			$filter = $encashment->get_item('default', 'filter', 'date_filter');
			$filter['value'] = array('value'=>$date_from);
			$encashment->set_item('default', 'filter', 'date_filter', $filter);
		}
		if ($date_to) {
			$filter = $encashment->get_item('default', 'filter', 'date_filter_1');
			$filter['value'] = array('value'=>$date_to);
			$encashment->set_item('default', 'filter', 'date_filter_1', $filter);
		}
		
    
		$encashment->pre_execute();

		if ($encashment->execute() !== FALSE) {
			foreach ($encashment->result as $view_row) {
				$enc_amount = isset($view_row->field_field_enc_amount[0]['raw']['value']) ?
					$view_row->field_field_enc_amount[0]['raw']['value']
					: 0;
								
			}
		}
	}

	$encashment->destroy();
}

unset($encashment);

$roz_output = number_format($roz, 0, '.', ' ') . ' сум';
$cash = number_format($cash, 0, '.', ' ') . ' сум';
$owe = number_format($owe, 0, '.', ' ') . ' сум';
$terminal = number_format($terminal, 0, '.', ' ') . ' сум';
$pribil = number_format(($roz - $opt), 0, '.', ' ') . ' сум';
$enc_amount_output = number_format($enc_amount, 0, '.', ' ') . ' сум';
$average_check = number_format(($roz / $check_amount), 0, '.', ' ') . ' сум';
$pribil_average_check = number_format((($roz-$opt) / $check_amount), 0, '.', ' ') . ' сум';

		
 ?>
<hr/>
<div class="row">
	<div class="col-sm-4">
		<h4>Все продажи: <span><?php print $roz_output; ?></span></h4>
		<h4>Прибыль: <span><?php print $pribil; ?></span></h4>
	</div>
	<div class="col-sm-4">
		<h4>Терминал: <span><?php print $terminal; ?></span></h4>
		<h4>Наличные: <span><?php print $cash; ?></span></h4>
		<h4>Долги клиентов: <span><?php print $owe; ?></span></h4>
	</div>
	<div class="col-sm-4">
		<h4>Средний чек: <span><?php print $average_check; ?></span></h4>
		<h4>Средний прибыль по чеку: <span><?php print $pribil_average_check; ?></span></h4>
	</div>
</div>
<hr/>
<?php if ($enc_amount): ?>
	<h4>Расходы<?php print $inc_output; ?>: <span><?php print $enc_amount_output; ?></span></h4>
<?php endif; ?>
<hr/>