$NetBSD: patch-system_modules_core_library_Contao_Validator.php,v 1.1.2.1 2015/02/14 10:07:52 tron Exp $

Fix for CVE-2015-0269.

--- system/modules/core/library/Contao/Validator.php.orig	2014-11-24 09:12:58.000000000 +0000
+++ system/modules/core/library/Contao/Validator.php
@@ -341,6 +341,12 @@ class Validator
 		$strPath = str_replace('\\', '/', $strPath);
 		$strPath = preg_replace('#/+#', '/', $strPath);
 
+		// Equals ..
+		if ($strPath == '..')
+		{
+			return true;
+		}
+
 		// Begins with ./
 		if (substr($strPath, 0, 2) == './')
 		{
