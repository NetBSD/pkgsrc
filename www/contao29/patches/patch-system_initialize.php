$NetBSD: patch-system_initialize.php,v 1.1.2.2 2012/03/14 17:42:33 tron Exp $

* More strict check against POST.

--- system/initialize.php.orig	2011-03-04 14:13:25.000000000 +0000
+++ system/initialize.php
@@ -157,7 +157,7 @@ else
 /**
  * Check referer address if there are $_POST variables
  */
-if ($_POST && !$GLOBALS['TL_CONFIG']['disableRefererCheck'])
+if ($_SERVER['REQUEST_METHOD'] == 'POST' && !$GLOBALS['TL_CONFIG']['disableRefererCheck'])
 {
 	$self = parse_url($objEnvironment->url);
 	$referer = parse_url($objEnvironment->httpReferer);
