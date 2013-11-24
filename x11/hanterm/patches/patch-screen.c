$NetBSD: patch-screen.c,v 1.1 2013/11/24 05:53:52 dholland Exp $

- use standard headers
- don't declare own calloc/malloc/realloc/free

--- screen.c~	1999-05-31 17:01:47.000000000 +0000
+++ screen.c
@@ -32,6 +32,7 @@
 #include "data.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <signal.h>
 
 #if defined(SVR4) || defined(sco)
@@ -49,11 +50,6 @@
 extern void HideCursor();
 extern void ResizeScrollBar();
 
-#if	!defined(linux) || (__GNUC__ < 2)
-extern Char *calloc(), *malloc(), *realloc();
-#endif
-extern void free();
-
 ScrnBuf Allocate (nrow, ncol, addr)
 /*
    allocates memory for a 2-dimensional array of chars and returns a pointer
