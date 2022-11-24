$NetBSD: patch-src_core_main.c,v 1.2 2022/11/24 02:25:39 gutteridge Exp $

Set _XOPEN_SOURCE to 600 to avoid conflict with C99.

--- src/core/main.c.orig	2022-11-12 16:47:39.000000000 +0000
+++ src/core/main.c
@@ -42,7 +42,7 @@
  */
 
 #define _GNU_SOURCE
-#define _XOPEN_SOURCE /* for putenv() and some signal-related functions */
+#define _XOPEN_SOURCE 600 /* for putenv() and some signal-related functions */
 
 #include <config.h>
 #include <glib/gi18n-lib.h>
