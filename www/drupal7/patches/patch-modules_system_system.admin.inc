$NetBSD: patch-modules_system_system.admin.inc,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2900373
When a theme has a managed_file field and a submit callback, call
to undefined function error is thrown
commit b014c196e1eab417e0703c3fc77e340a213a8824

--- modules/system/system.admin.inc.orig	2018-04-25 15:32:27.000000000 +0000
+++ modules/system/system.admin.inc
@@ -572,9 +572,10 @@ function system_theme_settings($form, &$
     // Process the theme and all its base themes.
     foreach ($theme_keys as $theme) {
       // Include the theme-settings.php file.
-      $filename = DRUPAL_ROOT . '/' . str_replace("/$theme.info", '', $themes[$theme]->filename) . '/theme-settings.php';
-      if (file_exists($filename)) {
-        require_once $filename;
+      $theme_settings_path = drupal_get_path('theme', $theme) . '/theme-settings.php';
+      if (file_exists(DRUPAL_ROOT . '/' . $theme_settings_path)) {
+        require_once DRUPAL_ROOT . '/' . $theme_settings_path;
+        $form_state['build_info']['files'][] = $theme_settings_path;
       }
 
       // Call theme-specific settings.
