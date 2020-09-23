$NetBSD: patch-src_sna_sna__video.c,v 1.1 2020/09/23 08:33:35 jperkin Exp $

Support SunOS.

--- src/sna/sna_video.c.orig	2020-05-15 16:56:58.000000000 +0000
+++ src/sna/sna_video.c
@@ -67,6 +67,9 @@
 #else
 #define bswap_32 bswap32
 #endif
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define bswap_32 BSWAP_32
 #else
 #include <byteswap.h>
 #endif
