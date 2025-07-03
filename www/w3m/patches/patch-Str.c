$NetBSD: patch-Str.c,v 1.1 2025/07/03 10:50:37 jperkin Exp $

Include strings.h for bcopy().

--- Str.c.orig	2025-07-03 10:48:29.508854520 +0000
+++ Str.c
@@ -18,9 +18,7 @@
 #include <gc.h>
 #include <stdarg.h>
 #include <string.h>
-#ifdef __EMX__			/* or include "fm.h" for HAVE_BCOPY? */
-#include <strings.h>
-#endif
+#include "fm.h"
 #include "Str.h"
 #include "myctype.h"
 
