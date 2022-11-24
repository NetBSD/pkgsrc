$NetBSD: patch-src_core_delete.c,v 1.2 2022/11/24 02:25:39 gutteridge Exp $

Set _XOPEN_SOURCE to 600 to avoid conflict with C99.

--- src/core/delete.c.orig	2022-11-12 16:47:39.000000000 +0000
+++ src/core/delete.c
@@ -23,7 +23,7 @@
  */
 
 #define _GNU_SOURCE
-#define _XOPEN_SOURCE /* for gethostname() and kill() */
+#define _XOPEN_SOURCE 600 /* for gethostname() and kill() */
 
 #include <config.h>
 #include <glib/gi18n-lib.h>
