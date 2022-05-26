$NetBSD: patch-admin_install_wizard.php,v 1.3 2022/05/26 21:08:38 triaxx Exp $

Honor PKG_SYSCONFDIR.
Set pkgsrc compliant directories for SQLite database.

--- admin/install/wizard.php.orig	2022-05-13 06:25:40.000000000 +0000
+++ admin/install/wizard.php
@@ -61,7 +61,7 @@ if (!empty($_POST)) {
     try {
         if ($DBDRIVER == 'sqlite') {
             if (strpos($DBNAME, '/') === false) {
-                $sqlite_db_directory = dirname(DC_RC_PATH) . '/../db/';
+                $sqlite_db_directory = '@DOTCLEAR_DBDIR@';
                 files::makeDir($sqlite_db_directory, true);
 
                 # Can we write sqlite_db_directory ?
