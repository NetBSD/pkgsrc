$NetBSD: patch-js_src_jsmath.cpp,v 1.1 2013/07/17 11:00:13 jperkin Exp $

--- js/src/jsmath.cpp.orig	2013-05-11 19:19:34.000000000 +0000
+++ js/src/jsmath.cpp
@@ -195,7 +195,7 @@ math_atan2_kernel(double x, double y)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (x == 0) {
         if (MOZ_DOUBLE_IS_NEGZERO(y))
             return js_copysign(M_PI, x);
