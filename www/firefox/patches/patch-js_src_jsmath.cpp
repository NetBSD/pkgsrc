$NetBSD: patch-js_src_jsmath.cpp,v 1.5 2016/06/16 12:08:21 ryoon Exp $

* Support Solaris

--- js/src/jsmath.cpp.orig	2013-09-10 03:43:36.000000000 +0000
+++ js/src/jsmath.cpp
@@ -244,7 +244,7 @@ js::ecmaAtan2(double y, double x)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (y == 0) {
         if (IsNegativeZero(x))
             return js_copysign(M_PI, y);
