$NetBSD: patch-src_functions.c,v 1.2 2022/04/02 01:24:17 gutteridge Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- src/functions.c.orig	2022-03-17 12:46:01.000000000 +0000
+++ src/functions.c
@@ -25,8 +25,10 @@
 #include <config.h>
 #endif
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #define _XOPEN_SOURCE /* glibc2 needs this */
 #define _XOPEN_SOURCE_EXTENDED 1 /* strptime needs this in posix systems */
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
