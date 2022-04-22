$NetBSD: patch-src_edid.cpp,v 1.1 2022/04/22 04:32:33 gutteridge Exp $

Fix build with Qt 5.15.3.

--- src/edid.cpp.orig	2020-05-05 14:47:08.000000000 +0000
+++ src/edid.cpp
@@ -411,7 +411,7 @@ QString Edid::Private::edidParseString(c
 
         for (int i = 0; i < text.length(); ++i) {
             if (!text.at(i).isPrint()) {
-                text[i] = '-';
+                text[i] = QLatin1Char('-');
             }
         }
         return text;
