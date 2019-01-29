$NetBSD: patch-core_lib_Drupal_Core_Extension_ModulesHandler.php,v 1.1.2.2 2019/01/29 12:50:28 bsiegert Exp $

Avoids UnknownExtensionException:
https://www.drupal.org/project/drupal/issues/3000677

--- core/lib/Drupal/Core/Extension/ModuleHandler.php.orig	2019-01-02 21:52:52.000000000 +0000
+++ core/lib/Drupal/Core/Extension/ModuleHandler.php
@@ -777,7 +777,13 @@ class ModuleHandler implements ModuleHan
    * {@inheritdoc}
    */
   public function getName($module) {
-    return \Drupal::service('extension.list.module')->getName($module);
+    try {
+      return \Drupal::service('extension.list.module')->getName($module);
+    }
+    catch (UnknownExtensionException $e) {
+      @trigger_error('Calling ModuleHandler::getName() with an unknown module is deprecated in Drupal 8.7.0 and support for this will be removed in Drupal 9.0.0, check that the module exists before calling this method. See https://www.drupal.org/node/3024541.', E_USER_DEPRECATED);
+      return $module;
+    }
   }
 
 }
