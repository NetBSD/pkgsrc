$NetBSD: patch-system_initialize.php,v 1.1 2012/03/28 15:14:24 taca Exp $

* Unofficial fix for CVE-2012-1297 by checking Referer as days of Contao 2.9.

--- system/initialize.php.orig	2011-12-30 09:00:10.000000000 +0000
+++ system/initialize.php
@@ -166,8 +166,24 @@ include(TL_ROOT . '/system/config/initco
  */
 if ($_POST && !$GLOBALS['TL_CONFIG']['disableRefererCheck'] && !defined('BYPASS_TOKEN_CHECK'))
 {
-	// Exit if the token cannot be validated
-	if (!$objInput->post('REQUEST_TOKEN') || !is_array($_SESSION['REQUEST_TOKEN'][TL_MODE]) || !in_array($objInput->post('REQUEST_TOKEN'), $_SESSION['REQUEST_TOKEN'][TL_MODE]))
+    $bad = false;
+
+	// Exit if traditional referer check is enabled.
+    if (!$GLOBALS['TL_CONFIG']['disableCompatRefererCheck'])
+    {
+        $self = parse_url($objEnvironment->url);
+        $referer = parse_url($objEnvironment->httpReferer);
+
+        $bad = (!strlen($referer['host']) || $referer['host'] != $self['host']);
+    }
+
+    if (!$bad)
+    {
+        // Exit if the token cannot be validated
+        $bad = (!$objInput->post('REQUEST_TOKEN') || !is_array($_SESSION['REQUEST_TOKEN'][TL_MODE]) || !in_array($objInput->post('REQUEST_TOKEN'), $_SESSION['REQUEST_TOKEN'][TL_MODE]));
+    }
+    
+	if ($bad)
 	{
 		header('HTTP/1.1 400 Bad Request');
 
