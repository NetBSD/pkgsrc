$NetBSD: patch-inc_prepend.php,v 1.4 2023/03/05 19:21:24 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- inc/prepend.php.orig	2023-02-25 08:19:34.000000000 +0000
+++ inc/prepend.php
@@ -162,7 +162,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     define('DC_RC_PATH', $_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-    define('DC_RC_PATH', implode(DIRECTORY_SEPARATOR, [__DIR__, 'config.php']));
+    define('DC_RC_PATH', implode(DIRECTORY_SEPARATOR, ['@PKG_SYSCONFDIR@', 'config.php']));
 }
 
 (function () {
