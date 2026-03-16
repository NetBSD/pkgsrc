$NetBSD: patch-readvmf.c,v 1.2 2026/03/16 11:24:48 nia Exp $

Fix implicit declaration of alloca.

Fix incorrect type usage (gzFile is already a pointer type).
Don't use data read from file as a format string.

--- readvmf.c.orig	2008-08-22 13:58:52.000000000 +0000
+++ readvmf.c
@@ -25,8 +25,12 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <math.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #ifdef ZLIB
 #include <zlib.h>
 #include <errno.h>
@@ -340,7 +344,7 @@ pixmap_image()
 char *
 getdata(fd)
 #ifdef ZLIB
-gzFile * fd;
+gzFile fd;
 #else
 FILE *fd;
 #endif
@@ -433,7 +437,7 @@ struct Sundata * Context;
   double theta, phi;
   char *str, *ptr;
 #ifdef ZLIB
-  gzFile * fd;
+  gzFile fd;
   int plen;
   char *zpath;
 #else
@@ -505,7 +509,7 @@ struct Sundata * Context;
      ret_value = 5;
      goto abort;
   }
-  if (reformat) printf(str);
+  if (reformat) printf("%s", str);
 
   k = 0;
   num_colors = 0;
