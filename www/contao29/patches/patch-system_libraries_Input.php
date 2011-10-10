$NetBSD: patch-system_libraries_Input.php,v 1.1.2.2 2011/10/10 18:03:11 tron Exp $

* Fix potential XSS vulnerability, r1044.

--- system/libraries/Input.php.orig	2011-03-02 13:03:27.000000000 +0000
+++ system/libraries/Input.php
@@ -54,9 +54,14 @@ class Input
 
 
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
@@ -234,6 +239,8 @@ class Input
 	 */
 	public function setGet($strKey, $varValue)
 	{
+		$strKey = $this->cleanKey($strKey);
+
 		unset($this->arrCache['getEncoded'][$strKey]);
 		unset($this->arrCache['getDecoded'][$strKey]);
 
@@ -255,6 +262,8 @@ class Input
 	 */
 	public function setPost($strKey, $varValue)
 	{
+		$strKey = $this->cleanKey($strKey);
+
 		unset($this->arrCache['postEncoded'][$strKey]);
 		unset($this->arrCache['postDecoded'][$strKey]);
 		unset($this->arrCache['postRaw'][$strKey]);
@@ -277,6 +286,8 @@ class Input
 	 */
 	public function setCookie($strKey, $varValue)
 	{
+		$strKey = $this->cleanKey($strKey);
+
 		unset($this->arrCache['cookieEncoded'][$strKey]);
 		unset($this->arrCache['cookieDecoded'][$strKey]);
 
@@ -301,6 +312,42 @@ class Input
 
 
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
