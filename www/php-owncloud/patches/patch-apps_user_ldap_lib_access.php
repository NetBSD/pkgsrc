$NetBSD: patch-apps_user_ldap_lib_access.php,v 1.2 2013/03/19 15:10:09 ryoon Exp $

--- apps/user_ldap/lib/access.php.orig	2013-03-16 18:19:18.000000000 +0100
+++ apps/user_ldap/lib/access.php	2013-03-16 18:19:35.000000000 +0100
@@ -602,7 +602,7 @@
 
 		// Translitaration
 		//latin characters to ASCII
-		$name = iconv('UTF-8', 'ASCII//TRANSLIT', $name);
+		$name = iconv('UTF-8', 'ASCII', $name);
 
 		//REPLACEMENTS
 		$name = \OCP\Util::mb_str_replace(' ', '_', $name, 'UTF-8');
