$NetBSD: patch-src_bk__edit__misc.c,v 1.1 2026/03/16 11:31:45 nia Exp $

Include headers for alloca.

--- src/bk_edit_misc.c.orig	2026-03-15 22:42:48.742079082 +0000
+++ src/bk_edit_misc.c
@@ -41,7 +41,11 @@
  */
 
 #include <time.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <ctype.h>
 #include <string.h>
