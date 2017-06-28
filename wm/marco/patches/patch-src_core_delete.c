$NetBSD: patch-src_core_delete.c,v 1.1 2017/06/28 15:35:11 jperkin Exp $

Set _XOPEN_SOURCE to 600 to avoid conflict with C99.

--- src/core/delete.c.orig	2017-05-10 15:03:59.000000000 +0000
+++ src/core/delete.c
@@ -23,7 +23,7 @@
  */
 
 #define _GNU_SOURCE
-#define _XOPEN_SOURCE /* for gethostname() and kill() */
+#define _XOPEN_SOURCE 600 /* for gethostname() and kill() */
 
 #include <config.h>
 #include "util.h"
