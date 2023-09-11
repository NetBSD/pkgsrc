$NetBSD: patch-modules_fdlibm_src_math__private.h,v 1.1 2023/09/11 12:33:25 ryoon Exp $

* Fix PR pkg/56457, build failure on NetBSD/i386.
  Do not use FreeBSD-specific definition.

--- modules/fdlibm/src/math_private.h.orig	2022-11-03 21:19:39.000000000 +0000
+++ modules/fdlibm/src/math_private.h
@@ -30,9 +30,9 @@
  * Adapted from https://github.com/freebsd/freebsd-src/search?q=__double_t
  */
 
-typedef double      __double_t;
-typedef __double_t  double_t;
-typedef float       __float_t;
+#include <math.h>
+typedef double_t __double_t;
+typedef float_t __float_t;
 
 /*
  * The original fdlibm code used statements like:
