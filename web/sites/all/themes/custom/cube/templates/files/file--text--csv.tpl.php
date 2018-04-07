<?php

/**
 * @file
 * Default theme implementation to display a file.
 *
 * Available variables:
 * - $label: the (sanitized) file name of the file.
 * - $content: An array of file items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The file owner's picture from user-picture.tpl.php.
 * - $date: Formatted added date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $timestamp
 *   variable.
 * - $name: Themed username of file owner output from theme_username().
 * - $file_url: Direct URL of the current file.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_file().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - file-entity: The current template type, i.e., "theming hook".
 *   - file-[type]: The current file type. For example, if the file is a
 *     "Image" file it would result in "file-image". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - file-[mimetype]: The current file's MIME type. For exampe, if the file
 *     is a PNG image, it would result in "file-image-png"
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $file: Full file object. Contains data that may not be safe.
 * - $type: File type, i.e. image, audio, video, etc.
 * - $uid: User ID of the file owner.
 * - $timestamp: Time the file was added formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   listings.
 * - $id: Position of the file. Increments each time it's output.
 *
 * File status variables:
 * - $view_mode: View mode, e.g. 'default', 'full', etc.
 * - $page: Flag for the full page state.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the file a corresponding
 * variable is defined, e.g. $file->caption becomes $caption. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language, e.g. $file->caption['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_file_entity()
 * @see template_process()
 *
 * @ingroup themeable
 */
//print_r($file);exit;
?>

<div class="text-center h4 text-strong" style="margin:30px 0">
	Счет фактура №<input type="text" size="4" maxlength="5" class="print-input"/> 
	от <input type="text" class="print-input" size="9" maxlength="10" value="<?php print date('d.m.Y',$file->timestamp); ?>"/>
</div>
<table class="table table-bordered table-hover">
	<thead>
		<tr class="strong">
			<td>№</td>
			<td>Наименование товара</td>
			<td>Количество</td>
			<td>Опт.цена за ед. (сум)</td>
			<td>Роз.цена за ед. (сум)</td>
			<td>Опт.цена (сум)</td>
			<td>Роз.цена (сум)</td>
		</tr>
	</thead>
	<tbody>
		
<?php 

$handle = fopen(drupal_realpath($file->uri), 'r');
$delimiter = getFileDelimiter(drupal_realpath($file->uri));

$total_amount = $total_opt_price_ed = $total_roz_price_ed = $total_opt_price = $total_roz_price = 0; 

while ($row = fgetcsv($handle, 0, $delimiter)) {
	$row = array_map( "convert", $row );

	if (!empty($row[0]) or !empty($row[1])) { //check for empty lines
		//Skip header
		if ($i!=0): ?>
		<tr>
			<td>
				<?php print $i; ?>
			</td>
			<td>
				<?php print $row[0].' '.$row[2].' '.$row[3].' №'.$row[4]; ?>
			</td>
			<td>
				<?php print $row[8]; $total_amount = $total_amount+$row[8]; ?>
			</td>
			<td>
				<?php print $row[9]; $total_opt_price_ed = $total_opt_price_ed+$row[9]; ?>
			</td>
			<td>
				<?php print $row[10]; $total_roz_price_ed = $total_roz_price_ed+$row[10]; ?>
			</td>
			<td>
				<?php print $row[8]*$row[9]; $total_opt_price = $total_opt_price+$row[8]*$row[9]; ?>
			</td>
			<td>
				<?php print $row[8]*$row[10]; $total_roz_price = $total_roz_price+$row[8]*$row[10]; ?>
			</td>
		</tr>
		<?php endif;
	}

	$i++;
}

?>
		<tr>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
		</tr>
		<tr>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
			<td> &nbsp; </td>
		</tr>
		
		<tr class="text-strong">
			<td></td>
			<td>Итого</td>
			<td>
				<?php print $total_amount; ?>
			</td>
			<td>
				<?php print $total_opt_price_ed; ?>
			</td>
			<td>
				<?php print $total_roz_price_ed; ?>
			</td>
			<td>
				<?php print $total_opt_price; ?>
			</td>
			<td>
				<?php print $total_roz_price; ?>
			</td>
		</tr>
	</tbody>
</table>
<p>
	&nbsp; <br/>
	&nbsp; <br/>
	&nbsp; <br/>
</p>
<div class="row">
	<div class="col-xs-6 h5">
		<p>Отправил: <input type="text" class="print-input" size="20" maxlength="20" value=""/><br/>
		<p>Подпись: &nbsp; ___________________________</p>
	</div>
	<div class="col-xs-6 h5 text-right">
		<p>Получил: <input type="text" class="print-input" size="20" maxlength="20" value=""/><br/>
		<p>Подпись: ___________________________</p>
	</div>
</div>

<p class="hide-print">
	&nbsp; <br/>
	&nbsp; <br/>
	&nbsp; <br/>
</p>
<div class="row hide-print">
	<div class="col-xs-6 h5">
		<p>
			<a href="<?php print url('dashboard/warehouse/export'); ?>" class="btn btn-danger">Назад</a>
		</p>
	</div>
	<div class="col-xs-6 h5 text-right">
		<p>
			<a href="#" onclick="window.print();" class="btn btn-primary">Печать</a>
		</p>
	</div>
</div>