$NetBSD: patch-system_modules_frontend_Frontend.php,v 1.2 2011/10/10 16:35:11 taca Exp $

* Fix potential XSS vulnerability, r1041 and r1044.

--- system/modules/frontend/Frontend.php.orig	2011-03-02 13:03:27.000000000 +0000
+++ system/modules/frontend/Frontend.php
@@ -80,14 +80,13 @@ abstract class Frontend extends Controll
 			return is_numeric($this->Input->get('id')) ? $this->Input->get('id') : null;
 		}
 
-		if (!strlen($this->Environment->request))
+		if ($this->Environment->request == '')
 		{
 			return null;
 		}
 
 		$strRequest = preg_replace('/\?.*$/i', '', $this->Environment->request);
 		$strRequest = preg_replace('/' . preg_quote($GLOBALS['TL_CONFIG']['urlSuffix'], '/') . '$/i', '', $strRequest);
-
 		$arrFragments = explode('/', $strRequest);
 
 		// Skip index.php
@@ -106,13 +105,15 @@ abstract class Frontend extends Controll
 			}
 		}
 
-		// Add fragments to $_GET array
+		$arrFragments = array_map('urldecode', $arrFragments);
+
+		// Add the fragments to the $_GET array
 		for ($i=1; $i<count($arrFragments); $i+=2)
 		{
-			$_GET[urldecode($arrFragments[$i])] = urldecode($arrFragments[$i+1]);
+			$this->Input->setGet($arrFragments[$i], $arrFragments[$i+1]);
 		}
 
-		return strlen($arrFragments[0]) ? urldecode($arrFragments[0]) : null;
+		return ($arrFragments[0] != '') ? $arrFragments[0] : null;
 	}
 
 
@@ -136,7 +137,7 @@ abstract class Frontend extends Controll
 
 
 	/**
-	 * Overwrite parent method as front end URLs are handled differently
+	 * Overwrite the parent method as front end URLs are handled differently
 	 * @param string
 	 * @param boolean
 	 * @return string
@@ -170,9 +171,22 @@ abstract class Frontend extends Controll
 
 		$strParams = '';
 
+		// Determine connector and separator
+		if ($GLOBALS['TL_CONFIG']['disableAlias'])
+		{
+			$strConnector = '&amp;';
+			$strSeparator = '=';
+		}
+		else
+		{
+			$strConnector = '/';
+			$strSeparator = '/';
+		}
+
+		// Compile the parameters string
 		foreach ($arrGet as $k=>$v)
 		{
-			$strParams .= $GLOBALS['TL_CONFIG']['disableAlias'] ? '&amp;' . $k . '=' . $v  : '/' . $k . '/' . $v;
+			$strParams .= $strConnector . urlencode($k) . $strSeparator . urlencode($v);
 		}
 
 		// Do not use aliases
