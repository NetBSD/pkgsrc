$NetBSD: patch-src_core_main.c,v 1.1 2017/06/28 15:35:11 jperkin Exp $

Set _XOPEN_SOURCE to 600 to avoid conflict with C99.

--- src/core/main.c.orig	2017-05-10 15:03:59.000000000 +0000
+++ src/core/main.c
@@ -42,7 +42,7 @@
  */
 
 #define _GNU_SOURCE
-#define _XOPEN_SOURCE /* for putenv() and some signal-related functions */
+#define _XOPEN_SOURCE 600 /* for putenv() and some signal-related functions */
 
 #include <config.h>
 #include "main.h"
