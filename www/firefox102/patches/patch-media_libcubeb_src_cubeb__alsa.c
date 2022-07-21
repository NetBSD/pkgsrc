$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.1 2022/07/21 23:56:39 nia Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2021-09-04 13:25:19.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,6 +7,7 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #define _XOPEN_SOURCE 500
 #include "cubeb-internal.h"
 #include "cubeb/cubeb.h"
