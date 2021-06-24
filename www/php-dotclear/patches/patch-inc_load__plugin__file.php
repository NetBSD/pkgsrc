$NetBSD: patch-inc_load__plugin__file.php,v 1.1 2021/06/24 02:32:28 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- inc/load_plugin_file.php.orig	2021-02-13 10:31:06.000000000 +0000
+++ inc/load_plugin_file.php
@@ -26,7 +26,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     define('DC_RC_PATH', $_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-    define('DC_RC_PATH', dirname(__FILE__) . '/config.php');
+    define('DC_RC_PATH', '@PKG_SYSCONFDIR@/config.php');
 }
 
 if (!is_file(DC_RC_PATH)) {
