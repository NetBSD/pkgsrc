$NetBSD: patch-system_modules_core_classes_BackendUser.php,v 1.1.2.2 2015/06/12 22:44:26 tron Exp $

Security improvement as Contao 3.2.21.

--- system/modules/core/classes/BackendUser.php.orig	2015-03-27 08:53:59.000000000 +0000
+++ system/modules/core/classes/BackendUser.php
@@ -285,7 +285,7 @@ class BackendUser extends \User
 											->limit(1)
 											->execute($pid);
 
-			while (!$row['chmod'] && $pid > 0 && $objParentPage->numRows)
+			while ($row['chmod'] === false && $pid > 0 && $objParentPage->numRows)
 			{
 				$pid = $objParentPage->pid;
 
@@ -299,15 +299,15 @@ class BackendUser extends \User
 			}
 
 			// Set default values
-			if (!$row['chmod'])
+			if (!$row['chmod'] === false)
 			{
 				$row['chmod'] = \Config::get('defaultChmod');
 			}
-			if (!$row['cuser'])
+			if (!$row['cuser'] === false)
 			{
 				$row['cuser'] = intval(\Config::get('defaultUser'));
 			}
-			if (!$row['cgroup'])
+			if (!$row['cgroup'] === false)
 			{
 				$row['cgroup'] = intval(\Config::get('defaultGroup'));
 			}
