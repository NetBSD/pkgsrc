$NetBSD: patch-admin_install_index.php,v 1.3 2022/05/26 21:08:38 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- admin/install/index.php.orig	2022-05-13 06:25:40.000000000 +0000
+++ admin/install/index.php
@@ -11,7 +11,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     $rc_path = $_SERVER['REDIRECT_DC_RC_PATH'];
 } else {
-    $rc_path = __DIR__ . '/../../inc/config.php';
+    $rc_path = '@PKG_SYSCONFDIR@/config.php';
 }
 
 require __DIR__ . '/../../inc/prepend.php';
