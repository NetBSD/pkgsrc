$NetBSD: patch-inc_prepend.php,v 1.2 2022/01/25 08:31:38 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- inc/prepend.php.orig	2021-02-13 10:32:13.000000000 +0000
+++ inc/prepend.php
@@ -127,7 +127,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     define('DC_RC_PATH', $_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-    define('DC_RC_PATH', dirname(__FILE__) . '/config.php');
+    define('DC_RC_PATH', '@PKG_SYSCONFDIR@/config.php');
 }
 
 if (!is_file(DC_RC_PATH)) {
