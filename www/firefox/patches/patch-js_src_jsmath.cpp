$NetBSD: patch-js_src_jsmath.cpp,v 1.3 2014/02/08 09:36:00 ryoon Exp $

--- js/src/jsmath.cpp.orig	2014-01-28 04:03:46.000000000 +0000
+++ js/src/jsmath.cpp
@@ -277,7 +277,7 @@ js::ecmaAtan2(double y, double x)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (y == 0) {
         if (IsNegativeZero(x))
             return js_copysign(M_PI, y);
