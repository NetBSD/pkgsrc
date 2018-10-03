$NetBSD: patch-includes_module.inc,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2925449
Function each() is deprecated since PHP 7.2
commit 28de6772813387bf02a4bf6f75b9119c4c20a3f4

--- includes/module.inc.orig	2018-04-25 15:32:27.000000000 +0000
+++ includes/module.inc
@@ -404,7 +404,11 @@ function module_enable($module_list, $en
     // Create an associative array with weights as values.
     $module_list = array_flip(array_values($module_list));
 
-    while (list($module) = each($module_list)) {
+    // The array is iterated over manually (instead of using a foreach) because
+    // modules may be added to the list within the loop and we need to process
+    // them.
+    while ($module = key($module_list)) {
+      next($module_list);
       if (!isset($module_data[$module])) {
         // This module is not found in the filesystem, abort.
         return FALSE;
@@ -540,7 +544,11 @@ function module_disable($module_list, $d
     $module_list = array_flip(array_values($module_list));
 
     $profile = drupal_get_profile();
-    while (list($module) = each($module_list)) {
+    // The array is iterated over manually (instead of using a foreach) because
+    // modules may be added to the list within the loop and we need to process
+    // them.
+    while ($module = key($module_list)) {
+      next($module_list);
       if (!isset($module_data[$module]) || !$module_data[$module]->status) {
         // This module doesn't exist or is already disabled, skip it.
         unset($module_list[$module]);
