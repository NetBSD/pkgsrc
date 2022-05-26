$NetBSD: patch-inc_prepend.php,v 1.3 2022/05/26 21:08:38 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- inc/prepend.php.orig	2022-05-13 06:26:03.000000000 +0000
+++ inc/prepend.php
@@ -128,7 +128,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     define('DC_RC_PATH', $_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-    define('DC_RC_PATH', __DIR__ . '/config.php');
+    define('DC_RC_PATH', '@PKG_SYSCONFDIR@/config.php');
 }
 
 if (!is_file(DC_RC_PATH)) {
