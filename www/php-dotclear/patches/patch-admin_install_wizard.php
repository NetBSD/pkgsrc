$NetBSD: patch-admin_install_wizard.php,v 1.2 2022/01/25 08:31:38 triaxx Exp $

Honor PKG_SYSCONFDIR.
Set pkgsrc compliant directories for SQLite database.

--- admin/install/wizard.php.orig	2021-11-19 12:51:15.000000000 +0000
+++ admin/install/wizard.php
@@ -11,7 +11,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     define('DC_RC_PATH', $_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-    define('DC_RC_PATH', dirname(__FILE__) . '/../../inc/config.php');
+    define('DC_RC_PATH', '@PKG_SYSCONFDIR@/config.php');
 }
 
 #  ClearBricks and DotClear classes auto-loader
@@ -61,7 +61,7 @@ if (!empty($_POST)) {
     try {
         if ($DBDRIVER == 'sqlite') {
             if (strpos($DBNAME, '/') === false) {
-                $sqlite_db_directory = dirname(DC_RC_PATH) . '/../db/';
+                $sqlite_db_directory = '@DOTCLEAR_DBDIR@';
                 files::makeDir($sqlite_db_directory, true);
 
                 # Can we write sqlite_db_directory ?
@@ -98,7 +98,7 @@ if (!empty($_POST)) {
         }
 
         # Does config.php.in exist?
-        $config_in = dirname(__FILE__) . '/../../inc/config.php.in';
+        $config_in = '@PKG_SYSCONFDIR@/config.php.in';
         if (!is_file($config_in)) {
             throw new Exception(sprintf(__('File %s does not exist.'), $config_in));
         }
