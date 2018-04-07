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
 
$warehouse_currency = config_pages_get('li'.'c'.'ense','field_currency_warehouse','сум');
?>
<div class="panel panel-default table-panel">
  <div class="panel-body table-responsive">
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <th <?php if ($header_classes['views_bulk_operations']) { print 'class="'. $header_classes['views_bulk_operations'] . '" '; } ?> scope="col">
          <?php print $header['views_bulk_operations']; ?>
        </th>
        
        <th data-toggle="tooltip" title="Название товара" data-placement="top">
          <?php print $header['title']; ?>
        </th>
        
        <th data-toggle="tooltip" title="Уникальный штрих-код товара" data-placement="top">
          <?php print $header['field_md_up_barcode']; ?>
        </th>
        
        <th data-toggle="tooltip" title="Общее количество на складе" data-placement="top">
          <?php print $header['nid_2']; ?>
        </th>
        
        <th data-toggle="tooltip" title="Цена за единицы" data-placement="top"><?php print t('Eд.цена'); ?></th>
        <th data-toggle="tooltip" title="Общая цена" data-placement="top"><?php print t('Общ.цена'); ?></th>
        
        <th <?php if ($header_classes['created']) { print 'class="'. $header_classes['created'] . '" '; } ?> scope="col">
          <?php print $header['created']; ?>
        </th>
        
        <th></th>
        
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): 
      $batch_obj = customizer_batch_maxqty_curprice($row['nid_2'], true);
      $expire_class = '';
      if ($batch_obj['expire_date']) {
        $time = strtotime($batch_obj['expire_date']);
        if ($time>0) {
          if ($time<time()) {
            $expire_class = ' bg-lightdanger';
          } elseif ($time<(time()+config_pages_get('li'.'c'.'ense','field_highlight_time',2592000))) {
            $expire_class = ' bg-lightwarning';
          }
        }
      }
      ?>
      <tr class="<?php print $expire_class; ?>">
        <td <?php if ($row_classes['views_bulk_operations']) { print 'class="'. $row_classes['views_bulk_operations'] . '" '; } ?> scope="col">
          <?php print $row['views_bulk_operations']; ?>
        </td>
        
        <td <?php if ($row_classes['title']) { print 'class="'. $row_classes['title'] . '" '; } ?> scope="col">
          <?php print $row['title']; ?>
        </td>
        
        <td <?php if ($row_classes['field_md_up_barcode']) { print 'class="'. $row_classes['field_md_up_barcode'] . '" '; } ?> scope="col">
          <?php print $row['field_md_up_barcode']; ?>
        </td>
        
        <td <?php if ($row_classes['nid_2']) { print 'class="'. $row_classes['nid_2'] . '" '; } ?> scope="col">
          <?php print ($batch_obj['qty']=='-' ? $batch_obj['qty'] : $batch_obj['qty'].' упк.'); ?>
        </td>
        
        <td>
          <?php print ($batch_obj['price']=='-' ? $batch_obj['price'] : $batch_obj['price'].' '.$warehouse_currency); ?>
        </td>
        
        <td>
          <?php print ($batch_obj['price']=='-' ? $batch_obj['price'] : ($batch_obj['price']*$batch_obj['qty']).' '.$warehouse_currency); ?>
        </td>
        
        <td <?php if ($row_classes['created']) { print 'class="'. $row_classes['created'] . '" '; } ?> scope="col">
          <?php print $row['created']; ?>
        </td>
        
        <td <?php if ($row_classes['nothing']) { print 'class="'. $row_classes['nothing'] . '" '; } ?> scope="col">
          <?php print $row['nothing']; ?>
        </td>
        
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
  </div>
</div>