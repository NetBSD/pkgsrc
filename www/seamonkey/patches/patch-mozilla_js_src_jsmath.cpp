$NetBSD: patch-mozilla_js_src_jsmath.cpp,v 1.1 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/js/src/jsmath.cpp.orig	2013-08-04 03:05:33.000000000 +0000
+++ mozilla/js/src/jsmath.cpp
@@ -219,7 +219,7 @@ js::ecmaAtan2(double x, double y)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (x == 0) {
         if (MOZ_DOUBLE_IS_NEGZERO(y))
             return js_copysign(M_PI, x);
