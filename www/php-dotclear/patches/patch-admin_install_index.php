$NetBSD: patch-admin_install_index.php,v 1.1 2021/06/24 02:32:28 triaxx Exp $

Honor PKG_SYSCONFDIR.

--- admin/install/index.php.orig	2021-02-13 10:31:06.000000000 +0000
+++ admin/install/index.php
@@ -12,7 +12,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     $rc_path = $_SERVER['REDIRECT_DC_RC_PATH'];
 } else {
-    $rc_path = dirname(__FILE__) . '/../../inc/config.php';
+    $rc_path = '@PKG_SYSCONFDIR@/config.php';
 }
 
 require dirname(__FILE__) . '/../../inc/prepend.php';
