<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */

$pos_currency = config_pages_get('li'.'c'.'ense','field_currency_pos','сум');
?>
<table class="transactions-table table table-condensed table-hover">
  <thead>
    <tr>
			<th>Чек №</th>
      <th>Дата</th>
      <th width="40%">Продукты</th>
      <th>Общая сумма</th>
      <th>Терминал</th>
      <th>Наличные</th>
      <th>Долг</th>
      <th>Продавец</th>
			<th>Действия</th>
    </tr>
  </thead>
  <tbody>
		<?php foreach ($rows as $row_count => $row): ?>
			<tr data-payby="<?php print (isset($row['tid']) ? $row['tid'] : ''); ?>" data-trc-unix-time="<?php print $row['title'] ?>" data-trc-nid="<?php print $row['nid'] ?>"<?php print ''; ?><?php if ($row['field_trc_price']==0): ?> class="trwarning"<?php endif; ?>>
				<td class="trc-check-no"><?php print $row['field_trc_check_no']; ?></td>
				<td class="trc-time"><?php print $row['created']; ?></td>
				<td class="trc-products">
					<?php print $row['field_trc_product']; ?>
				</td>
				<td class="trc-price" data-price="<?php print $row['field_trc_price']; ?>" data-base-price="<?php print $row['field_trc_price_base']; ?>"><?php print $row['field_trc_price']; ?> <?php print $pos_currency; ?></td>
				<td class="trc-terminal" data-trc-terminal="<?php print $row['field_trc_payment_terminal']; ?>"><?php print $row['field_trc_payment_terminal']; ?> <?php print $pos_currency; ?></td>
				<td class="trc-cash" data-trc-cash="<?php print $row['field_trc_payment_cash']; ?>"><?php print $row['field_trc_payment_cash']; ?> <?php print $pos_currency; ?></td>
        <td class="trc-owe" data-trc-owe="<?php print $row['field_trc_payment_owe']; ?>"><a href="#" class="owe-return-opener label <?php print (($row['field_trc_payment_owe']>0) ? 'label-info ' : 'label-default '); ?>text-no-underline"><?php print $row['field_trc_payment_owe']; ?> <?php print $pos_currency; ?></a></td>
				<td class="trc-seller-name" data-trc-cash="<?php print $row['name']; ?>"><?php print $row['name']; ?></td>
				<td class="trc-actions">
          <?php if ($row['field_trc_price']>0): ?>
            <button class="btn btn-xs btn-danger refund-modal-opener" data-toggle="modal" data-target="#refund_modal">Возврат</button>
            <input type="hidden" value="" class="trc-refund-msg"/>
          <?php endif; ?>
				</td>
			</tr>
     <?php endforeach; ?>
      <tr class="total-counts strong active">
        <td></td>
        <td></td>
        <td class="text-right">Итого: &nbsp; &nbsp; &nbsp; </td>
        <td class="total-trc-price"><span>0</span> <?php print $pos_currency; ?></td>
        <td class="total-trc-terminal"><span>0</span> <?php print $pos_currency; ?></td>
        <td class="total-trc-cash"><span>0</span> <?php print $pos_currency; ?></td>
        <td class="total-trc-owe"><span>0</span> <?php print $pos_currency; ?></td>
        <td></td>
        <td></td>
			</tr>
  </tbody>
</table>