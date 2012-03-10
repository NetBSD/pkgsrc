$NetBSD: patch-plugins_idna_idna__convert.class.php,v 1.1 2012/03/10 03:42:30 taca Exp $

* Fix problem on PHP 5.2.

--- plugins/idna/idna_convert.class.php.orig	2012-03-09 11:31:02.000000000 +0000
+++ plugins/idna/idna_convert.class.php
@@ -973,7 +973,7 @@ class idna_convert
         }
         // PATCH: support PHP 5.2 (see #4044)
         //return strlen((binary) $string);
-        return version_compare(PHP_VERSION, '5.3.0', '>=') ? strlen((binary) $string) : strlen(unpack('c*', $string));
+        return version_compare(PHP_VERSION, '5.3.0', '>=') ? strlen((binary) $string) : count(unpack('c*', $string));
     }
 
     /**
