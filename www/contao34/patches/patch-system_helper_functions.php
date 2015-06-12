$NetBSD: patch-system_helper_functions.php,v 1.1.2.2 2015/06/12 22:44:26 tron Exp $

Security improvement as Contao 3.2.21.

--- system/helper/functions.php.orig	2015-03-27 08:53:59.000000000 +0000
+++ system/helper/functions.php
@@ -216,9 +216,10 @@ function scan($strFolder, $blnUncached=f
  * entities are never double converted.
  * @param string
  * @param boolean
+ * @param boolean
  * @return string
  */
-function specialchars($strString, $blnStripInsertTags=false)
+function specialchars($strString, $blnStripInsertTags=false, $blnDoubleEncode=false)
 {
 	if ($blnStripInsertTags)
 	{
@@ -226,7 +227,7 @@ function specialchars($strString, $blnSt
 	}
 
 	// Use ENT_COMPAT here (see #4889)
-	return htmlspecialchars($strString, ENT_COMPAT, $GLOBALS['TL_CONFIG']['characterSet'], false);
+	return htmlspecialchars($strString, ENT_COMPAT, $GLOBALS['TL_CONFIG']['characterSet'], $blnDoubleEncode);
 }
 
 
