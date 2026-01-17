$NetBSD: patch-Str.c,v 1.2 2026/01/17 22:35:59 wiz Exp $

Include strings.h for bcopy().

--- Str.c.orig	2025-08-20 09:32:27.000000000 +0000
+++ Str.c
@@ -18,9 +18,7 @@
 #include <gc/gc.h>
 #include <stdarg.h>
 #include <string.h>
-#ifdef __EMX__			/* or include "fm.h" for HAVE_BCOPY? */
-#include <strings.h>
-#endif
+#include "fm.h"
 #include "Str.h"
 #include "myctype.h"
 
