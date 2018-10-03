$NetBSD: patch-includes_form.inc,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2885610
Avoid count() calls on uncountable variables
commit 73e12f0ddf1ed60c13331dc3a9b8ea16d1599307

--- includes/form.inc.orig	2018-04-25 15:32:27.000000000 +0000
+++ includes/form.inc
@@ -1438,10 +1438,12 @@ function _form_validate(&$elements, &$fo
       // length if it's a string, and the item count if it's an array.
       // An unchecked checkbox has a #value of integer 0, different than string
       // '0', which could be a valid value.
-      $is_empty_multiple = (!count($elements['#value']));
+      $is_countable = is_array($elements['#value']) || $elements['#value'] instanceof \Countable;
+      $is_empty_multiple = $is_countable && count($elements['#value']) == 0;
       $is_empty_string = (is_string($elements['#value']) && drupal_strlen(trim($elements['#value'])) == 0);
       $is_empty_value = ($elements['#value'] === 0);
-      if ($is_empty_multiple || $is_empty_string || $is_empty_value) {
+      $is_empty_null = is_null($elements['#value']);
+      if ($is_empty_multiple || $is_empty_string || $is_empty_value || $is_empty_null) {
         // Although discouraged, a #title is not mandatory for form elements. In
         // case there is no #title, we cannot set a form error message.
         // Instead of setting no #title, form constructors are encouraged to set
