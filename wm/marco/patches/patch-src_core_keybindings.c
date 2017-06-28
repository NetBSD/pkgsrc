$NetBSD: patch-src_core_keybindings.c,v 1.1 2017/06/28 15:35:11 jperkin Exp $

Set _XOPEN_SOURCE to 600 to avoid conflict with C99.

--- src/core/keybindings.c.orig	2017-05-10 15:03:59.000000000 +0000
+++ src/core/keybindings.c
@@ -24,7 +24,7 @@
  */
 
 #define _GNU_SOURCE
-#define _XOPEN_SOURCE /* for putenv() */
+#define _XOPEN_SOURCE 600 /* for putenv() */
 
 #include <config.h>
 #include "keybindings.h"
