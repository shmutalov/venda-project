<?php

/**
 * @file
 * template.php
 */

function cube_preprocess_page(&$vars) {
  $arg2=arg(1);
  global $user;

	drupal_set_title(strip_tags(htmlspecialchars_decode(drupal_get_title())));

	if (isset($vars['node'])) {
    if (isset($vars['node']->type)) {
      if (($vars['node']->type=='faq' or $vars['node']->type=='transaction' or $vars['node']->type=='product_batch') and arg(2)=='') {
        drupal_goto('<front>');
      }
      if ($vars['node']->type=='product_batch' and arg(2)=='') {
        drupal_goto('dashboard/warehouse');
      }
      if ($vars['node']->type=='encashment' and arg(2)=='') {
        drupal_goto('dashboard/reports/encashment');
      }
      if (($vars['node']->type=='transaction' and arg(2)=='')) {
        drupal_goto('dashboard/reports');
      }
      if ($vars['node']->type=='provider' and arg(2)=='') {
        drupal_goto('dashboard/providers');
      }
      if ($vars['node']->type=='branch' and arg(2)=='') {
        drupal_goto('dashboard/branches');
      }
      if ($vars['node']->type=='waybill' and arg(2)=='') {
        drupal_goto('dashboard/providers/waybills');
      }
      if ($vars['node']->type=='product' and is_numeric($arg2) and arg(2)=='') {
        drupal_goto('node/'.$arg2.'/edit');
      }
      if ($vars['node']->type=='contract' and is_numeric($arg2) and arg(2)=='') {
        drupal_goto('node/'.$arg2.'/edit');
      }
      if ($vars['node']->type=='product' and arg(2)=='edit') {
        menu_set_active_item('dashboard/warehouse/add-new');
      }
      if ($vars['node']->type=='transaction' and arg(2)=='edit') {
        menu_set_active_item('dashboard/reports');
      }
      if ($vars['node']->type=='provider' and arg(2)=='edit') {
        menu_set_active_item('dashboard/providers');
      }
      if ($vars['node']->type=='contract' and arg(2)=='edit') {
        menu_set_active_item('dashboard/providers/contracts');
      }
      if ($vars['node']->type=='waybill' and arg(2)=='edit') {
        menu_set_active_item('dashboard/providers/waybills');
      }
      if ($vars['node']->type=='branch' and arg(2)=='edit') {
        menu_set_active_item('dashboard/branches');
      }
    }
  }

	if (arg(0)=='taxonomy' and arg(1)=='term' and arg(3)=='edit') {
		drupal_set_title(t('Производители'));
		menu_set_active_item('dashboard/manufacturers');
	}

  //add pos script
  if(arg(0) == 'dashboard' && arg(1) == 'warehouse' && count(arg()) == 2) {
    drupal_add_js(drupal_get_path('module', 'customizer') . '/js/jquery.pos.js');
  }

  if (arg(0)=='node' and $arg2=='add') {
		if (arg(2)=='transaction') {
			drupal_goto('dashboard/sell');
		}
		if (arg(2)=='product-batch' or arg(2)=='') {
			drupal_goto('dashboard/warehouse');
		}
	}

	if (arg(0)=='node' and $arg2=='add' and arg(2)=='product') {
    menu_set_active_item('dashboard/warehouse/add-new');
  }

  if (arg(0)=='node' and $arg2=='add' and arg(2)=='contract') {
    menu_set_active_item('dashboard/providers/contracts');
  }

  if (arg(0)=='node' and $arg2=='add' and arg(2)=='waybill') {
    menu_set_active_item('dashboard/providers/waybills');
  }

	if (arg(0)=='file' and is_numeric($arg2) and arg(2)=='') {
		drupal_set_title('Счет-фактура для файла '.drupal_get_title());
    menu_set_active_item('dashboard/warehouse/export');
  }

  if (user_is_logged_in()) {

    if (arg(0)=='user' and is_numeric($arg2) and $arg2==$user->uid and arg(2)=='') {
      drupal_goto('user/'.$user->uid.'/edit');
    }

		if (arg(1) != $user->uid && arg(0)=='user' and is_numeric($arg2) and arg(2)=='edit') {
      if ($arg2==$user->uid and $_SERVER['HTTP_HOST']=='demo.venda.uz') {
        drupal_set_message(t('Настройка профиля запрещена в демо версии.'), 'error');
				drupal_goto('<front>');
      } else {
        menu_set_active_item('dashboard/sellers');
      }
    }

  }
}

function cube_preprocess_file_entity(&$vars) {
	//print_r($vars['theme_hook_suggestions']); exit;
}

function cube_preprocess_node(&$vars) {
	$vars['theme_hook_suggestions'][] = 'node__'.$vars['node']->type.'__'.$vars['view_mode'];
}

function cube_css_alter(&$css) {
  unset($css['sites/all/modules/date/date_api/date.css']);
  if (user_is_logged_in() and arg(0)=='dashboard' and arg(1)=='sell') {
    //disable unused CSS files on Sell process page
    unset($css['modules/system/system.base.css']);
    unset($css['sites/all/modules/date/date_popup/themes/datepicker.1.7.css']);
    unset($css['sites/all/themes/custom/cube/css/print.css']);
    unset($css['sites/all/modules/views/css/views.css']);
  }

  unset($css['modules/field/theme/field.css']);
  unset($css['modules/node/node.css']);
  unset($css['sites/all/modules/logintoboggan/logintoboggan.css']);
  unset($css['sites/all/modules/ckeditor/css/ckeditor.css']);
  unset($css['sites/all/modules/ctools/css/ctools.css']);

}

function cube_date_combo($variables) {
  return theme('form_element', $variables);
}

function cube_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array(
    'id',
    'name',
    'value',
    'size',
    'maxlength',
  ));
  _form_set_class($element, array('form-text'));

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  $extra = '';
  if ($element['#autocomplete_path'] && !empty($element['#autocomplete_input'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#autocomplete_input']['#id'];
    $attributes['value'] = $element['#autocomplete_input']['#url_value'];
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    // Uses icon for autocomplete "throbber".
    if ($icon = _bootstrap_icon('refresh')) {
      $output = '<div class="input-grouper">' . $output . '<span class="input-group-addon">' . $icon . '</span></div>';
    }
    // Fallback to using core's throbber.
    else {
      $output = '<div class="input-grouper">' . $output . '<span class="input-group-addon">';
      // The throbber's background image must be set here because sites may not
      // be at the root of the domain (ie: /) and this value cannot be set via
      // CSS.
      $output .= '<span class="autocomplete-throbber" style="background-image:url(' . url('misc/throbber.gif') . ')"></span>';
      $output .= '</span></div>';
    }
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  return $output . $extra;
}

function cube_menu_tree__menu_report_menu(&$variables) {
  return '<ul class="nav nav-pills report-main-nav hidden-sm hidden-xs">' . $variables['tree'] . '</ul><select class="report-mobile-menu visible-sm visible-xs form-control"></select><hr class="visible-sm visible-xs"/>';
}

function cube_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  $title = $element['#title'];
  $href = $element['#href'];
  $options = !empty($element['#localized_options']) ? $element['#localized_options'] : array();
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : array();
	$caret = '';

  if ($element['#below']) {

    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {

			if ($element['#original_link']['menu_name'] == 'menu-manager-menu') {
				// Add our own wrapper.
				unset($element['#below']['#theme_wrappers']);
				$sub_menu = '<ul class="manager-dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

				// Generate as standard dropdown.
				$caret .= '<div class="menu-opener"><span class="glyphicon glyphicon-menu-right"></span></div>';

				$attributes['class'][] = 'dropdown';

				$options['html'] = TRUE;

			} else {
				// Add our own wrapper.
				unset($element['#below']['#theme_wrappers']);
				$sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

				// Generate as standard dropdown.
				$title .= ' <span class="caret"></span>';
				$attributes['class'][] = 'dropdown';

				$options['html'] = TRUE;

				// Set dropdown trigger element to # to prevent inadvertant page loading
				// when a submenu link is clicked.
				$options['attributes']['data-target'] = '#';
				$options['attributes']['class'][] = 'dropdown-toggle';
				$options['attributes']['data-toggle'] = 'dropdown';
			}
    }
  }

  // Filter the title if the "html" is set, otherwise l() will automatically
  // sanitize using check_plain(), so no need to call that here.
  if (!empty($options['html'])) {
    $title = _bootstrap_filter_xss($title);
  }

  return '<li' . drupal_attributes($attributes) . '>' . l($title, $href, $options). $caret . $sub_menu . "</li>\n";
}



/**
 * Theme function for header row of XLSX file using PHPExcel.
 */
function cube_views_data_export_xlsx_header(&$vars) {
  _views_data_export_header_shared_preprocess($vars);
  $rows = array($vars['header']);
  $vars['view']->style_plugin->appendRows($rows);
}



/**
 * Theme function for data rows XLSX file using PHPExcel.
 */
function cube_views_data_export_xlsx_body(&$vars) {
  _views_data_export_body_shared_preprocess($vars);

	foreach ($vars['themed_rows'] as $k => $row) {
		foreach ($row as $v => $value) {
			$vars['themed_rows'][$k][$v] = strip_tags($value);
		}
	}

	if ($vars['view']->name=='reports_products') {
		foreach ($vars['themed_rows'] as $k => $rw) {

			$profit = (int)$vars['themed_rows'][$k]['field_trc_price'] - (int)$vars['themed_rows'][$k]['field_trc_price_base'];
			$profit = max($profit, 0);

			$vars['themed_rows'][$k]['field_trc_price_base'] = $profit;
		}
	}

	if ($vars['view']->name=='reports_date') {
		foreach ($vars['themed_rows'] as $k => $rw) {

			$profit = (int)$vars['themed_rows'][$k]['field_trc_price'] - (int)$vars['themed_rows'][$k]['field_trc_price_base'];
			$profit = max($profit, 0);

			$vars['themed_rows'][$k]['field_trc_price_base'] = $profit;
		}
	}

  $rows = $vars['themed_rows'];

  $vars['view']->style_plugin->appendRows($rows);
}