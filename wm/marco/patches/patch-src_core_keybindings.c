$NetBSD: patch-src_core_keybindings.c,v 1.2 2022/11/24 02:25:39 gutteridge Exp $

Set _XOPEN_SOURCE to 600 to avoid conflict with C99.

--- src/core/keybindings.c.orig	2022-11-12 16:47:39.000000000 +0000
+++ src/core/keybindings.c
@@ -24,7 +24,7 @@
  */
 
 #define _GNU_SOURCE
-#define _XOPEN_SOURCE /* for putenv() */
+#define _XOPEN_SOURCE 600 /* for putenv() */
 
 #include <config.h>
 #include <glib/gi18n-lib.h>
