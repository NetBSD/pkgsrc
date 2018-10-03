$NetBSD: patch-includes_install.inc,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2925449
Function each() is deprecated since PHP 7.2
commit 28de6772813387bf02a4bf6f75b9119c4c20a3f4

--- includes/install.inc.orig	2018-04-25 15:32:27.000000000 +0000
+++ includes/install.inc
@@ -779,7 +779,7 @@ function drupal_uninstall_modules($modul
     $module_list = array_flip(array_values($module_list));
 
     $profile = drupal_get_profile();
-    while (list($module) = each($module_list)) {
+    foreach (array_keys($module_list) as $module) {
       if (!isset($module_data[$module]) || drupal_get_installed_schema_version($module) == SCHEMA_UNINSTALLED) {
         // This module doesn't exist or is already uninstalled. Skip it.
         unset($module_list[$module]);
