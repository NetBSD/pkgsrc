$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.32 2023/04/05 14:22:36 ryoon Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2023-03-02 21:15:48.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,6 +7,9 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE /* timersub() */
+#endif
 #define _XOPEN_SOURCE 500
 #include "cubeb-internal.h"
 #include "cubeb/cubeb.h"
