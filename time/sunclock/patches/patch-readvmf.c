$NetBSD: patch-readvmf.c,v 1.1 2022/12/09 14:13:00 vins Exp $

Fix incorrect type usage (gzFile is already a pointer type).
Don't use data read from file as a format string.

--- readvmf.c.orig	2008-08-22 13:58:52.000000000 +0000
+++ readvmf.c
@@ -340,7 +340,7 @@ pixmap_image()
 char *
 getdata(fd)
 #ifdef ZLIB
-gzFile * fd;
+gzFile fd;
 #else
 FILE *fd;
 #endif
@@ -433,7 +433,7 @@ struct Sundata * Context;
   double theta, phi;
   char *str, *ptr;
 #ifdef ZLIB
-  gzFile * fd;
+  gzFile fd;
   int plen;
   char *zpath;
 #else
@@ -505,7 +505,7 @@ struct Sundata * Context;
      ret_value = 5;
      goto abort;
   }
-  if (reformat) printf(str);
+  if (reformat) printf("%s", str);
 
   k = 0;
   num_colors = 0;
