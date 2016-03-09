$NetBSD: patch-readfile.c,v 1.1 2016/03/09 06:52:02 tnn Exp $

use proper malloc prototypes

--- readfile.c.orig	1999-02-11 10:34:04.000000000 +0000
+++ readfile.c
@@ -34,8 +34,7 @@
 #include <X11/Xos.h>			/* get types.h */
 #include <sys/stat.h>
 
-extern char *malloc();
-extern char *realloc();
+#include <stdlib.h>
 
 /*
  * readinlump - read data from a file into a single buffer in 1 go
