$NetBSD: patch-modules_fdlibm_src_math__private.h,v 1.1 2022/07/21 23:56:39 nia Exp $

* Fix PR pkg/56457, build failure on NetBSD/i386.
  Do not use FreeBSD-specific definition.

--- modules/fdlibm/src/math_private.h.orig	2021-09-27 22:47:42.000000000 +0000
+++ modules/fdlibm/src/math_private.h
@@ -30,8 +30,8 @@
  * Adapted from https://github.com/freebsd/freebsd-src/search?q=__double_t
  */
 
-typedef double      __double_t;
-typedef __double_t  double_t;
+#include <math.h>
+typedef double_t __double_t;
 
 /*
  * The original fdlibm code used statements like:
