$NetBSD: patch-system_initialize.php,v 1.1 2012/03/28 15:14:43 taca Exp $

* Unofficial fix for CVE-2012-1297 by checking Referer as days of Contao 2.9.

--- system/initialize.php.orig	2012-03-14 15:13:14.000000000 +0000
+++ system/initialize.php
@@ -168,10 +168,28 @@ if (file_exists(TL_ROOT . '/system/confi
 /**
  * Check the request token upon POST requests
  */
-if ($_POST && !$GLOBALS['TL_CONFIG']['disableRefererCheck'] && !defined('BYPASS_TOKEN_CHECK'))
+if (!$GLOBALS['TL_CONFIG']['disableRefererCheck'] &&
+    ($_POST && !defined('BYPASS_TOKEN_CHECK') ||
+     $_SERVER['REQUEST_METHOD'] == 'POST' && !$GLOBALS['TL_CONFIG']['disableCompatRefererCheck']))
 {
-	// Exit if the token cannot be validated
-	if (!$objToken->validate($objInput->post('REQUEST_TOKEN')))
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
+        $bad = !$objToken->validate($objInput->post('REQUEST_TOKEN'));
+    }
+    
+	if ($bad)
 	{
 		// Force JavaScript redirect upon Ajax requests (IE requires absolute link)
 		if ($objEnvironment->isAjaxRequest)
