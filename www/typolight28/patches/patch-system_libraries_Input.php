$NetBSD: patch-system_libraries_Input.php,v 1.1.2.2 2011/10/10 18:21:57 tron Exp $

* Fix potential XSS vulnerability, r1044.

--- system/libraries/Input.php.orig	2010-04-12 13:08:16.000000000 +0000
+++ system/libraries/Input.php
@@ -52,9 +52,14 @@ class Input
 
 
 	/**
-	 * Prevent direct instantiation (Singleton)
+	 * Clean the keys of the request arrays
 	 */
-	protected function __construct() {}
+	protected function __construct()
+	{
+		$_GET    = $this->cleanKey($_GET);
+		$_POST   = $this->cleanKey($_POST);
+		$_COOKIE = $this->cleanKey($_COOKIE);
+	}
 
 
 	/**
@@ -232,6 +237,8 @@ class Input
 	 */
 	public function setGet($strKey, $varValue)
 	{
+		$strKey = $this->cleanKey($strKey);
+
 		unset($this->arrCache['getEncoded'][$strKey]);
 		unset($this->arrCache['getDecoded'][$strKey]);
 
@@ -246,6 +253,8 @@ class Input
 	 */
 	public function setPost($strKey, $varValue)
 	{
+		$strKey = $this->cleanKey($strKey);
+
 		unset($this->arrCache['postEncoded'][$strKey]);
 		unset($this->arrCache['postDecoded'][$strKey]);
 		unset($this->arrCache['postRaw'][$strKey]);
@@ -261,6 +270,8 @@ class Input
 	 */
 	public function setCookie($strKey, $varValue)
 	{
+		$strKey = $this->cleanKey($strKey);
+
 		unset($this->arrCache['cookieEncoded'][$strKey]);
 		unset($this->arrCache['cookieDecoded'][$strKey]);
 
@@ -278,6 +289,42 @@ class Input
 
 
 	/**
+	 * Sanitize a key name or an array (thanks to Andreas Schempp)
+	 * @param mixed
+	 * @return mixed
+	 */
+	protected function cleanKey($varValue)
+	{
+		// Recursively clean arrays
+		if (is_array($varValue))
+		{
+			$return = array();
+
+			foreach ($varValue as $k=>$v)
+			{
+				$k = $this->cleanKey($k);
+
+				if (is_array($v))
+				{
+					$v = $this->cleanKey($v);
+				}
+
+				$return[$k] = $v;
+			}
+
+			return $return;
+		}
+
+		$varValue = $this->stripSlashes($varValue);
+		$varValue = $this->decodeEntities($varValue);
+		$varValue = $this->xssClean($varValue, true);
+		$varValue = $this->stripTags($varValue);
+
+		return $varValue;
+	}
+
+
+	/**
 	 * Strip slashes
 	 * @param  mixed
 	 * @return mixed
