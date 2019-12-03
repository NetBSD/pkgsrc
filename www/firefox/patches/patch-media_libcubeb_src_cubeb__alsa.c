$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.30 2019/12/03 14:21:20 ryoon Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2019-12-02 12:23:28.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,6 +7,7 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #define _XOPEN_SOURCE 500
 #include <pthread.h>
 #include <sys/time.h>
