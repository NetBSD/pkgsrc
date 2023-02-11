$NetBSD: patch-src_appointment.c,v 1.2 2023/02/11 01:26:12 gutteridge Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- src/appointment.c.orig	2023-01-27 10:02:10.000000000 +0000
+++ src/appointment.c
@@ -25,7 +25,9 @@
 #  include <config.h>
 #endif
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #define _XOPEN_SOURCE /* glibc2 needs this */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
