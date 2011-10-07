$NetBSD: patch-system_modules_frontend_Frontend.php,v 1.1 2011/10/07 12:28:55 taca Exp $

* Fix potential XSS vulnerability, r1041.

--- system/modules/frontend/Frontend.php.orig	2011-03-02 13:03:27.000000000 +0000
+++ system/modules/frontend/Frontend.php
@@ -80,7 +80,7 @@ abstract class Frontend extends Controll
 			return is_numeric($this->Input->get('id')) ? $this->Input->get('id') : null;
 		}
 
-		if (!strlen($this->Environment->request))
+		if ($this->Environment->request == '')
 		{
 			return null;
 		}
@@ -106,13 +106,15 @@ abstract class Frontend extends Controll
 			}
 		}
 
-		// Add fragments to $_GET array
+		// DO NOT USE urldecode() HERE (XSS vulnerability)!
+
+		// Add the fragments to the $_GET array
 		for ($i=1; $i<count($arrFragments); $i+=2)
 		{
-			$_GET[urldecode($arrFragments[$i])] = urldecode($arrFragments[$i+1]);
+			$_GET[$arrFragments[$i]] = $arrFragments[$i+1];
 		}
 
-		return strlen($arrFragments[0]) ? urldecode($arrFragments[0]) : null;
+		return ($arrFragments[0] != '') ? $arrFragments[0] : null;
 	}
 
 
