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

if (!isset($_SESSION['price_show'])) {
  $price_show = 'сум';
} elseif ($_SESSION['price_show']=='sum') {
  $price_show = 'сум';
} elseif ($_SESSION['price_show']=='ue') {
  $price_show = 'у.е.';
}

$rate = config_pages_get('li'.'c'.'ense','field_exchange_rate',0);
?>
<div class="panel panel-default table-panel">
  <div class="panel-body table-responsive">
    <table <?php if ($classes) { print 'class="'. $classes . ' table-striped table-hover" '; } ?><?php print $attributes; ?>>
       <?php if (!empty($title) || !empty($caption)) : ?>
         <caption><?php print $caption . $title; ?></caption>
      <?php endif; ?>
      <?php if (!empty($header)) : ?>
        <thead>
          <tr>
            <?php foreach ($header as $field => $label): ?>
              <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?> scope="col">
                <?php print $label; ?>
              </th>
            <?php endforeach; ?>
          </tr>
        </thead>
      <?php endif; ?>
      <tbody>
        <?php foreach ($rows as $row_count => $row): ?>
          <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
            <?php foreach ($row as $field => $content): ?>
              <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                <?php if (in_array($field, array('field_trc_price_base', 'field_trc_price', 'field_trc_payment_cash', 'field_trc_payment_terminal', 'field_trc_payment_owe'))) {
                  if ($price_show=='у.е.') {
                    $output = round(trim($content)/trim($row['field_trc_rate']),2);
                  } else {
                    $output = $content;
                    if ($output=='') {
                      $output = 0;
                    }
                  }

                  $output .= ' '.$price_show;

                  print $output;
                } else {
                  print $content;
                }
                ?>
              </td>
            <?php endforeach; ?>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>

  </div>
</div>