$NetBSD: patch-admin_install_wizard.php,v 1.4 2023/03/05 19:21:24 triaxx Exp $

Honor PKG_SYSCONFDIR.
Set pkgsrc compliant directories for SQLite database.

--- admin/install/wizard.php.orig	2023-02-25 08:19:11.000000000 +0000
+++ admin/install/wizard.php
@@ -61,7 +61,7 @@ $ADMINMAILFROM = !empty($_POST['ADMINMAI
 if (!empty($_POST)) {
     try {
         if ($DBDRIVER == 'sqlite' && strpos($DBNAME, '/') === false) {
-            $sqlite_db_directory = dirname(DC_RC_PATH) . '/../db/';
+            $sqlite_db_directory = '@DOTCLEAR_DBDIR@';
             files::makeDir($sqlite_db_directory, true);
 
             # Can we write sqlite_db_directory ?
