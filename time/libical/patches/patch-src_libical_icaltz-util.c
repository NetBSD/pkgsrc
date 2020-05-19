$NetBSD: patch-src_libical_icaltz-util.c,v 1.4 2020/05/19 15:33:10 nia Exp $

Define bswap_32 on NetBSD

--- src/libical/icaltz-util.c.orig	2020-03-07 14:42:42.000000000 +0000
+++ src/libical/icaltz-util.c
@@ -49,6 +49,10 @@
 #endif
 #endif
 
+#if defined(__NetBSD__) && !defined(bswap_32)
+#define bswap_32 bswap32
+#endif
+
 #if defined(__OpenBSD__) && !defined(bswap_32)
 #define bswap_32 swap32
 #endif
