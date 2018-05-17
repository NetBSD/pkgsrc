$NetBSD: patch-src_appointment.c,v 1.1 2018/05/17 09:13:02 jperkin Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- src/appointment.c.orig	2015-04-10 10:26:26.000000000 +0000
+++ src/appointment.c
@@ -25,8 +25,10 @@
 #  include <config.h>
 #endif
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #define _XOPEN_SOURCE /* glibc2 needs this */
 #define _XOPEN_SOURCE_EXTENDED 1 /* strptime needs this in posix systems */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
