$NetBSD: patch-media_libcubeb_src_cubeb__jack.cpp,v 1.1 2022/07/21 23:56:39 nia Exp $

* Enable strdup(3) for NetBSD too.

--- media/libcubeb/src/cubeb_jack.cpp.orig	2022-04-28 22:03:04.000000000 +0000
+++ media/libcubeb/src/cubeb_jack.cpp
@@ -8,7 +8,7 @@
  */
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #define _POSIX_SOURCE
 #endif
 #include "cubeb-internal.h"
