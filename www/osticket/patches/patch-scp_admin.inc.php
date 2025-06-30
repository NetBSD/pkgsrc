$NetBSD: patch-scp_admin.inc.php,v 1.1 2025/06/30 14:34:15 hauke Exp $

Removing the setup directory creates noise when the package is
deleted; it is really enough to make it unreadable to the web server.

--- scp/admin.inc.php.orig	2025-06-25 16:45:19.787476545 +0000
+++ scp/admin.inc.php
@@ -43,8 +43,8 @@ if($ost->isUpgradePending()) {
         if(!strcasecmp(basename($_SERVER['SCRIPT_NAME']), 'settings.php'))
             die($sysnotice);
 
-    } elseif(file_exists('../setup/')) {
-        $sysnotice=__('Please take a minute to delete <strong>setup</strong> directory (../setup/) for security reasons.');
+    } elseif(file_exists('../setup/') && is_readable('../setup/')) {
+        $sysnotice=__('For security reasons, make the <strong>setup</strong> directory (../setup/) inaccessible to the web server, or delete it.');
     } elseif(CONFIG_FILE && file_exists(CONFIG_FILE) && is_writable(CONFIG_FILE)) {
             //Confirm for real that the file is writable by group or world.
             clearstatcache(); //clear the cache!
