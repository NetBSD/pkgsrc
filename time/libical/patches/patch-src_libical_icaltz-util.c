$NetBSD: patch-src_libical_icaltz-util.c,v 1.3 2020/03/04 10:54:25 nia Exp $

Define bswap_32 on NetBSD
Need limits.h for CHAR_BIT

https://github.com/libical/libical/pull/420

--- src/libical/icaltz-util.c.orig	2018-02-27 15:34:25.000000000 +0000
+++ src/libical/icaltz-util.c
@@ -25,6 +25,7 @@
 #include "icalerror.h"
 #include "icaltimezone.h"
 
+#include <limits.h>
 #include <stdlib.h>
 
 #if defined(sun) && defined(__SVR4)
@@ -48,6 +49,9 @@
 #endif
 #endif
 
+#if defined(__NetBSD__) && !defined(bswap_32)
+#define bswap_32 bswap32
+#endif
 #if defined(__OpenBSD__) && !defined(bswap_32)
 #define bswap_32 swap32
 #endif
