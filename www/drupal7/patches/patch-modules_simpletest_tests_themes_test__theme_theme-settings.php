$NetBSD: patch-modules_simpletest_tests_themes_test__theme_theme-settings.php,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2900373
When a theme has a managed_file field and a submit callback, call
to undefined function error is thrown
commit b014c196e1eab417e0703c3fc77e340a213a8824

--- modules/simpletest/tests/themes/test_theme/theme-settings.php.orig	2018-10-03 09:31:14.310243910 +0000
+++ modules/simpletest/tests/themes/test_theme/theme-settings.php
@@ -0,0 +1,32 @@
+<?php
+
+/**
+ * @file
+ * Theme setting callbacks for the test_theme theme.
+ */
+
+/**
+ * Implements hook_form_FORM_ID_alter().
+ */
+function test_theme_form_system_theme_settings_alter(&$form, &$form_state) {
+  $form['test_theme_checkbox'] = array(
+    '#type' => 'checkbox',
+    '#title' => 'Test theme checkbox',
+    '#default_value' => theme_get_setting('test_theme_checkbox'),
+  );
+
+  // Force the form to be cached so we can test that this file is properly
+  // loaded and the custom submit handler is properly called even on a cached
+  // form build.
+  $form_state['cache'] = TRUE;
+  $form['#submit'][] = 'test_theme_form_system_theme_settings_submit';
+}
+
+/**
+ * Form submission handler for the test theme settings form.
+ *
+ * @see test_theme_form_system_theme_settings_alter()
+ */
+function test_theme_form_system_theme_settings_submit($form, &$form_state) {
+  drupal_set_message('The test theme setting was saved.');
+}
