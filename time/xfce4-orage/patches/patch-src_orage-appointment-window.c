$NetBSD: patch-src_orage-appointment-window.c,v 1.1 2025/01/18 16:59:13 bsiegert Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- src/orage-appointment-window.c.orig	2025-01-18 16:23:05.743471042 +0000
+++ src/orage-appointment-window.c
@@ -24,7 +24,9 @@
 #  include <config.h>
 #endif
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #define _XOPEN_SOURCE /* glibc2 needs this */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
