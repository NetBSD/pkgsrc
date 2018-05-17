$NetBSD: patch-src_functions.c,v 1.1 2018/05/17 09:13:02 jperkin Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- src/functions.c.orig	2015-04-10 10:26:26.000000000 +0000
+++ src/functions.c
@@ -21,8 +21,10 @@
 
  */
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #define _XOPEN_SOURCE /* glibc2 needs this */
 #define _XOPEN_SOURCE_EXTENDED 1 /* strptime needs this in posix systems */
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
