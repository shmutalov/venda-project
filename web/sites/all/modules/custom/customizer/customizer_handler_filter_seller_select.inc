<?php
/**
 * My custom filter handler.
 */
class customizer_handler_filter_seller_select extends views_handler_filter_in_operator
{
  /**
   * Override parent get_value_options() function.
   * @return
   *   Return the stored values in $this->value_options if someone expects it.
   */
  function get_value_options() {
    $self_uid = $GLOBALS['user']->uid;
    $sellers_uids = customizer_get_manager_sellers($GLOBALS['user']);
    $users_uids = array($self_uid);
    $users_uids = array_merge($users_uids, $sellers_uids);
    $users_list = user_load_multiple($users_uids);
    $users = array();

    foreach ($users_list as $user) {
      $users[$user->uid] = $user->name;
    }

    $this->value_options = $users;
    return $users;
  }
}

