$NetBSD: patch-plugins_GeoIp2_LocationProvider_GeoIp2_Php.php,v 1.1 2025/03/06 01:21:38 manu Exp $

Avoid using //TRANSLIT which exists only in GNU iconv

--- plugins/GeoIp2/LocationProvider/GeoIp2/Php.php.orig	2025-03-05 17:02:29.003477793 +0100
+++ plugins/GeoIp2/LocationProvider/GeoIp2/Php.php	2025-03-05 17:02:38.578017630 +0100
@@ -315,10 +315,10 @@
         }
 
         // try converting umlauts to closted ascii char if iconv is available
         if (function_exists('iconv')) {
-            $str1 = iconv('UTF-8', 'ASCII//TRANSLIT', $str1);
-            $str2 = iconv('UTF-8', 'ASCII//TRANSLIT', $str2);
+            $str1 = iconv('UTF-8', 'ASCII', $str1);
+            $str2 = iconv('UTF-8', 'ASCII', $str2);
         }
 
         return strtolower($str1) === strtolower($str2);
     }
