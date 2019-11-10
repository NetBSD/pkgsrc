$NetBSD: patch-src_libical_icaltimezone.c,v 1.1 2019/11/10 11:12:53 nia Exp $

Need limits.h for INT_MAX

--- src/libical/icaltimezone.c.orig	2019-09-14 16:43:47.000000000 +0000
+++ src/libical/icaltimezone.c
@@ -36,6 +36,7 @@
 #include <ctype.h>
 #include <stddef.h>     /* for ptrdiff_t */
 #include <stdlib.h>
+#include <limits.h>
 
 #if defined(HAVE_PTHREAD)
 #include <pthread.h>
