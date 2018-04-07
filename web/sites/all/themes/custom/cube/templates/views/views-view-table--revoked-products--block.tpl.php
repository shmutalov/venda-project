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

            <th>
              <?php print $header['title']; ?>
            </th>

            <th>
              <?php print $header['created']; ?>
            </th>

            <th>
              <?php print $header['field_rv_amount']; ?>
            </th>

            <th>
              <?php print $header['field_rv_opt_price']; ?>
            </th>

            <th>
              <?php print $header['field_rv_roz_price']; ?>
            </th>

            <th>
              <?php print $header['field_rv_comment']; ?>
            </th>

          </tr>
        </thead>
      <?php endif; ?>
      <tbody>
        <?php foreach ($rows as $row_count => $row): 
          ?>
          <tr>
            <td <?php if ($row_classes['views_bulk_operations']) { print 'class="'. $row_classes['views_bulk_operations'] . '" '; } ?> scope="col">
              <?php print $row['views_bulk_operations']; ?>
            </td>

            <td <?php if ($row_classes['title']) { print 'class="'. $row_classes['title'] . '" '; } ?> scope="col">
              <?php print $row['title']; ?>
            </td>

            <td <?php if ($row_classes['created']) { print 'class="'. $row_classes['created'] . '" '; } ?> scope="col">
              <?php print $row['created']; ?>
            </td>

            <td <?php if ($row_classes['field_rv_amount']) { print 'class="'. $row_classes['field_rv_amount'] . '" '; } ?> scope="col">
              <?php print $row['field_rv_amount']; ?>
            </td>

            <td <?php if ($row_classes['field_rv_opt_price']) { print 'class="'. $row_classes['field_rv_opt_price'] . '" '; } ?> scope="col">
              <?php print $row['field_rv_opt_price'].' '.$warehouse_currency; ?>
            </td>

            <td <?php if ($row_classes['field_rv_roz_price']) { print 'class="'. $row_classes['field_rv_roz_price'] . '" '; } ?> scope="col">
              <?php print $row['field_rv_roz_price'].' '.$warehouse_currency; ?>
            </td>

            <td <?php if ($row_classes['field_rv_comment']) { print 'class="'. $row_classes['field_rv_comment'] . '" '; } ?> scope="col">
              <?php print $row['field_rv_comment']; ?>
            </td>

          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  </div>
</div>