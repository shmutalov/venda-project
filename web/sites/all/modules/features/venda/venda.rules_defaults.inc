<?php
/**
 * @file
 * venda.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function venda_default_rules_configuration() {
  $items = array();
  $items['rules_assign_seller_role'] = entity_import('rules_config', '{ "rules_assign_seller_role" : {
      "LABEL" : "Assign seller role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "3" : "3" } }
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ]
    }
  }');
  $items['rules_set_product_title'] = entity_import('rules_config', '{ "rules_set_product_title" : {
      "LABEL" : "Set product title",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--product" : { "bundle" : "product" } },
      "DO" : [
        { "data_set" : {
            "data" : [ "node:title" ],
            "value" : "[node:field-pr-medicament-title] [node:field-pr-manufacturer] [node:field-pr-mn-country]"
          }
        }
      ]
    }
  }');
  return $items;
}
