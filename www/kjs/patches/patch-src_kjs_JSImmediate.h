$NetBSD: patch-src_kjs_JSImmediate.h,v 1.1 2016/08/21 22:27:17 markd Exp $

--- src/kjs/JSImmediate.h.orig	2016-04-03 20:34:48.000000000 +0000
+++ src/kjs/JSImmediate.h
@@ -33,7 +33,7 @@
 #endif
 #include <stdlib.h>
 
-#if PLATFORM(SOLARIS_OS)
+#if PLATFORM(SOLARIS_OS) && COMPILER(GCC) && (__GNUC__ <= 4 && __GNUC_MINOR__ < 6)
 static inline int signbit(double x)
 {
     return (x < 0.0) ? 1 : 0;
