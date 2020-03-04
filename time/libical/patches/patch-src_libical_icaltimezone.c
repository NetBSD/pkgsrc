$NetBSD: patch-src_libical_icaltimezone.c,v 1.2 2020/03/04 10:54:25 nia Exp $

Need limits.h for INT_MAX

https://github.com/libical/libical/pull/420

--- src/libical/icaltimezone.c.orig	2019-09-14 16:43:47.000000000 +0000
+++ src/libical/icaltimezone.c
@@ -36,6 +36,7 @@
 #include <ctype.h>
 #include <stddef.h>     /* for ptrdiff_t */
 #include <stdlib.h>
+#include <limits.h>
 
 #if defined(HAVE_PTHREAD)
 #include <pthread.h>
