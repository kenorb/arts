<?php

/**
 * Field handler to display the current signup status of a node.
 */
class signup_handler_field_signup_status extends views_handler_field {
  function render($values) {
    return ($values->{$this->field_alias} == 0) ? t('Closed') : t('Open');
  }
}

