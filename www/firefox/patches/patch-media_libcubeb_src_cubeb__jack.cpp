$NetBSD: patch-media_libcubeb_src_cubeb__jack.cpp,v 1.1 2017/09/30 05:34:12 ryoon Exp $

--- media/libcubeb/src/cubeb_jack.cpp.orig	2017-09-14 20:16:05.000000000 +0000
+++ media/libcubeb/src/cubeb_jack.cpp
@@ -8,7 +8,9 @@
  */
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#ifndef __FreeBSD__
 #define _POSIX_SOURCE
+#endif
 #include <dlfcn.h>
 #include <stdio.h>
 #include <string.h>
