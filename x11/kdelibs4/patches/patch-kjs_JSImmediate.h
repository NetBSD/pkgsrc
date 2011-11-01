--- kjs/JSImmediate.h.orig	2010-05-16 22:04:04.000000000 +0200
+++ kjs/JSImmediate.h	2011-10-24 17:26:02.608429864 +0200
@@ -33,7 +33,7 @@
 #endif
 #include <stdlib.h>
 
-#if PLATFORM(SOLARIS_OS)
+#if PLATFORM(SOLARIS_OS) && COMPILER(GCC) && (__GNUC__ <= 4 && __GNUC_MINOR__ < 6)
 static inline int signbit(double x)
 {
     return (x<0.0) ? 1 : 0;
