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
$roz_sum = $opt_sum = $i = $cash_sum = $terminal_sum = $roz_usd = $opt_usd = $cash_usd = $terminal_usd = $owe_sum = $owe_usd = 0;

?>
<div class="<?php print $classes; ?>">
  <?php
    if (count($view->result)>0) {
      foreach ($view->result as $row) {
        //SUM
        $roz_sum = $roz_sum + $row->field_field_trc_price[0]['raw']['value'];
        $opt_sum = $opt_sum + $row->field_field_trc_price_base[0]['raw']['value'];
        $cash_sum = $cash_sum + $row->field_field_trc_payment_cash[0]['raw']['value'];
        $terminal_sum = $terminal_sum + $row->field_field_trc_payment_terminal[0]['raw']['value'];
        $owe_sum = $owe_sum + $row->field_field_trc_payment_owe[0]['raw']['value'];
        
        //U.E.
        $roz_usd = $roz_usd + round($row->field_field_trc_price[0]['raw']['value']/$row->field_field_trc_rate[0]['raw']['value'], 2);
        $opt_usd = $opt_usd + round($row->field_field_trc_price_base[0]['raw']['value']/$row->field_field_trc_rate[0]['raw']['value'], 2);
        $cash_usd = $cash_usd + round($row->field_field_trc_payment_cash[0]['raw']['value']/$row->field_field_trc_rate[0]['raw']['value'], 2);
        $terminal_usd = $terminal_usd + round($row->field_field_trc_payment_terminal[0]['raw']['value']/$row->field_field_trc_rate[0]['raw']['value'], 2);
        $owe_usd = $owe_usd + round($row->field_field_trc_payment_owe[0]['raw']['value']/$row->field_field_trc_rate[0]['raw']['value'], 2);
        
        $i++;
      }
    }
    
    $check_amount = $i;
    
    //SUM
    $prib_sum = $roz_sum - $opt_sum;
    $average_check_sum = round(($roz_sum / $check_amount),2);
    $pribil_average_check_sum = round($prib_sum / $check_amount,2);
    
    //UE
    $prib_usd = $roz_usd - $opt_usd;
    $average_check_usd = round(($roz_usd / $check_amount), 2);
    $pribil_average_check_usd = round($prib_usd / $check_amount,2);

    
    
//Get Inkassatsiya data
$inc_output = '';
$date_from = $date_to = false;

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

$enc_amount = 0;
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

$price_show = 'сум';

//SUM output
$roz_output = round($roz_sum, 2) . ' '.$price_show;
$cash_output = round($cash_sum, 2) . ' '.$price_show;
$terminal_output = round($terminal_sum, 2) . ' '.$price_show;
$owe_output = round($owe_sum, 2) . ' '.$price_show;
$pribil_output = round($prib_sum, 2) . ' '.$price_show;
$enc_amount_output = $enc_amount . ' '.$price_show;
$average_check_output = round(($roz_sum / $check_amount), 2) . ' '.$price_show;
$pribil_average_check_output = round(($prib_sum / $check_amount),2) . ' '.$price_show;

if (!isset($_SESSION['price_show'])) {
  
} elseif ($_SESSION['price_show']=='sum') {
  $price_show = 'сум';
} elseif ($_SESSION['price_show']=='ue') {
  $price_show = 'у.е.';
  
  //SUM output
  $roz_output = round($roz_usd, 2) . ' '.$price_show;
  $cash_output = round($cash_usd, 2) . ' '.$price_show;
  $terminal_output = round($terminal_usd, 2) . ' '.$price_show;
  $owe_output = round($owe_usd, 2) . ' '.$price_show;
  $pribil_output = round($prib_usd, 2) . ' '.$price_show;
  $average_check_output = round(($roz_usd / $check_amount), 2) . ' '.$price_show;
  $pribil_average_check_output = round(($prib_usd / $check_amount),2) . ' '.$price_show;
}




		
 ?>
<hr/>
<div class="row">
	<div class="col-sm-4">
		<h4>Все продажи: <span><?php print $roz_output; ?></span></h4>
		<h4>Прибыль: <span><?php print $pribil_output; ?></span></h4>
	</div>
	<div class="col-sm-4">
		<h4>Терминал: <span><?php print $terminal_output; ?></span></h4>
		<h4>Наличные: <span><?php print $cash_output; ?></span></h4>
		<h4>Долги клиентов: <span><?php print $owe_output; ?></span></h4>
	</div>
	<div class="col-sm-4">
		<h4>Средний чек: <span><?php print $average_check_output; ?></span></h4>
		<h4>Средний прибыль по чеку: <span><?php print $pribil_average_check_output; ?></span></h4>
	</div>
</div>
<hr/>
<?php if ($enc_amount): ?>
	<h4>Расходы<?php print $inc_output; ?>: <span><?php print $enc_amount_output; ?></span></h4>
<?php endif; ?>
<hr/>
</div><?php /* class view */ ?>