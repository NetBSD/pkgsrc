$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2014-01-28 04:03:54.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -6,6 +6,9 @@
  */
 #undef NDEBUG
 #define _BSD_SOURCE
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #define _XOPEN_SOURCE 500
 #include <pthread.h>
 #include <sys/time.h>
