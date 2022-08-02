$NetBSD: patch-inc_load__plugin__file.php,v 1.4 2022/08/02 20:09:00 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- inc/load_plugin_file.php.orig	2022-05-13 06:25:40.000000000 +0000
+++ inc/load_plugin_file.php
@@ -25,7 +25,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     define('DC_RC_PATH', $_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-    define('DC_RC_PATH', __DIR__ . '/config.php');
+    define('DC_RC_PATH', '@PKG_SYSCONFDIR@/config.php');
 }
 
 if (!is_file(DC_RC_PATH)) {
