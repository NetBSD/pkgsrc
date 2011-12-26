$NetBSD: patch-lib_wiki-plugins_wikiplugin__snarf.php,v 1.1 2011/12/26 19:05:32 ryoon Exp $

* Fix security bug, http://dev.tiki.org/item4059 .

--- lib/wiki-plugins/wikiplugin_snarf.php.orig	2011-07-14 22:36:39.000000000 +0000
+++ lib/wiki-plugins/wikiplugin_snarf.php
@@ -178,8 +178,13 @@ function wikiplugin_snarf($data, $params
 	}
 
 	// If the user specified a more specialized regex
-	if ( isset($params['regex']) && isset($params['regexres']) && preg_match('/^(.)(.)+\1[^e]*$/', $params['regex']) ) {
-		$snarf = preg_replace( $params['regex'], $params['regexres'], $snarf );
+	if (isset($params['regex']) && isset($params['regexres'])) { 
+		// fixes http://dev.tiki.org/item4059
+		$params['regex'] = str_replace("\0", "", $params['regex']);
+		
+		if (preg_match('/^(.)(.)+\1[^e]*$/', $params['regex'])) {
+			$snarf = preg_replace($params['regex'], $params['regexres'], $snarf);
+		}
 	}
 
 	if ( $data == '' ) $data = NULL;
