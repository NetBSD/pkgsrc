$NetBSD: patch-js_src_jsapi.cpp,v 1.1 2015/02/16 16:16:17 bad Exp $

--- js/src/jsapi.cpp.orig	2015-01-23 06:00:01.000000000 +0000
+++ js/src/jsapi.cpp	2015-02-05 12:13:20.000000000 +0000
@@ -236,7 +236,7 @@
     assertSameCompartment(cx, args);
     required = true;
     while ((c = *format++) != '\0') {
-        if (isspace(c))
+        if (isspace(((unsigned char)c)))
             continue;
         if (c == '/') {
             required = false;
