$NetBSD: patch-src_curl.c,v 1.1 2022/06/22 14:55:16 he Exp $

Fix BSWAP_32 define on NetBSD.
Submitted upstream at
https://github.com/jeroen/curl/pull/272

--- src/curl.c.orig	2021-04-28 11:36:30.000000000 +0000
+++ src/curl.c
@@ -24,6 +24,10 @@
 #define BSWAP_32 OSSwapInt32
 #elif (defined(__OpenBSD__))
 #define BSWAP_32(x) swap32(x)
+#elif (defined(__NetBSD__))
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define BSWAP_32(x) bswap32(x)
 #elif (defined(__GLIBC__))
 #include <byteswap.h>
 #define BSWAP_32(x) bswap_32(x)
