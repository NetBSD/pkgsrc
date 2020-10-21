$NetBSD: patch-system_modules_core_library_Contao_Input.php,v 1.1.2.2 2020/10/21 21:51:28 spz Exp $

Apply fix for CVE-2020-25768.

--- system/modules/core/library/Contao/Input.php.orig	2019-04-11 11:11:34.000000000 +0000
+++ system/modules/core/library/Contao/Input.php
@@ -765,7 +765,18 @@ class Input
 	 */
 	public static function encodeInsertTags($varValue)
 	{
-		return str_replace(array('{{', '}}'), array('&#123;&#123;', '&#125;&#125;'), $varValue);
+		// Recursively encode insert tags
+		if (\is_array($varValue))
+		{
+			foreach ($varValue as $k=>$v)
+			{
+				$varValue[$k] = static::encodeInsertTags($v);
+			}
+
+			return $varValue;
+		}
+
+		return str_replace(array('{{', '}}'), array('&#123;&#123;', '&#125;&#125;'), (string) $varValue);
 	}
 
 
