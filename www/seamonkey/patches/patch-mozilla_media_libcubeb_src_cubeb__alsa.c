$NetBSD: patch-mozilla_media_libcubeb_src_cubeb__alsa.c,v 1.1 2013/11/08 12:55:52 ryoon Exp $

--- mozilla/media/libcubeb/src/cubeb_alsa.c.orig	2013-10-29 01:21:03.000000000 +0000
+++ mozilla/media/libcubeb/src/cubeb_alsa.c
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
