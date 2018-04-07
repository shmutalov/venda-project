<?php

/**
 * Implements of hook_views_data().
 */
function customizer_views_data() {
  return array(
    'node' => array(
      'seller_select' => array(
        'group' => t('Content'),
        'title' => 'Seller UID (select list)',
        'help' => 'Filter by seller uid, choosing from dropdown list.',
        'filter' => array('handler' => 'customizer_handler_filter_seller_select'),
        'real field' => 'uid',
      ),
    ),
  );
}


