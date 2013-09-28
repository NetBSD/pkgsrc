$NetBSD: patch-mozilla_js_src_jsmath.cpp,v 1.2 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/js/src/jsmath.cpp.orig	2013-09-16 18:26:41.000000000 +0000
+++ mozilla/js/src/jsmath.cpp
@@ -244,7 +244,7 @@ js::ecmaAtan2(double y, double x)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (y == 0) {
         if (IsNegativeZero(x))
             return js_copysign(M_PI, y);
