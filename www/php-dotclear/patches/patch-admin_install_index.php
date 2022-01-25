$NetBSD: patch-admin_install_index.php,v 1.2 2022/01/25 08:31:38 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- admin/install/index.php.orig	2021-02-13 10:31:06.000000000 +0000
+++ admin/install/index.php
@@ -11,7 +11,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     $rc_path = $_SERVER['REDIRECT_DC_RC_PATH'];
 } else {
-    $rc_path = dirname(__FILE__) . '/../../inc/config.php';
+    $rc_path = '@PKG_SYSCONFDIR@/config.php';
 }
 
 require dirname(__FILE__) . '/../../inc/prepend.php';
