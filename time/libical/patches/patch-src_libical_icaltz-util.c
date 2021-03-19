$NetBSD: patch-src_libical_icaltz-util.c,v 1.5 2021/03/19 10:45:31 nia Exp $

Define bswap_32 on NetBSD

--- src/libical/icaltz-util.c.orig	2021-01-16 14:19:41.000000000 +0000
+++ src/libical/icaltz-util.c
@@ -42,6 +42,7 @@
 #include <sys/endian.h>
 #if defined(bswap32)
 #define bswap_32 bswap32
+#define bswap_64 bswap64
 #else
 #define bswap_32 swap32
 #endif
@@ -49,8 +50,14 @@
 #endif
 #endif
 
+#if defined(__NetBSD__) && !defined(bswap_32)
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#endif
+
 #if defined(__OpenBSD__) && !defined(bswap_32)
 #define bswap_32 swap32
+#define bswap_64 swap64
 #endif
 
 #if defined(_MSC_VER)
