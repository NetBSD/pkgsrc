$NetBSD: patch-src_libical_icaltz-util.c,v 1.1 2018/04/25 05:51:20 markd Exp $

Define bswap_32 on NetBSD

--- src/libical/icaltz-util.c.orig	2018-02-27 15:34:25.000000000 +0000
+++ src/libical/icaltz-util.c
@@ -48,6 +48,9 @@
 #endif
 #endif
 
+#if defined(__NetBSD__) && !defined(bswap_32)
+#define bswap_32 bswap32
+#endif
 #if defined(__OpenBSD__) && !defined(bswap_32)
 #define bswap_32 swap32
 #endif
