$NetBSD: patch-readpng.c,v 1.1 2022/12/09 14:13:00 vins Exp $

png_check_sig() removed since libpng-1.4.
Include missing <string.h> for memcpy().

--- readpng.c.orig	2005-10-23 19:36:29.000000000 +0000
+++ readpng.c
@@ -16,6 +16,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <png.h>
 
 #include <X11/Xlib.h>
@@ -57,7 +58,7 @@ TestPNG(char *file)  /* gets called a LO
     fread(header, 1, 8, fp);
     fclose(fp);
 
-    return png_check_sig(header, 8);
+    return !png_sig_cmp(header, 0, 8);
 }
 
 static void
