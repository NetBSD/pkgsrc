$NetBSD: patch-xgrk.c,v 1.1 2026/06/18 16:15:31 nia Exp $

Include <string.h> for strcmp(3) and memcmp(3).

Fix an implicit int so that this compiles with GCC 14.

--- xgrk.c.orig	2026-06-18 16:12:40.410866772 +0000
+++ xgrk.c
@@ -11,6 +11,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <errno.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
@@ -94,6 +95,7 @@ pipe_hdl(int koko)
   exit(koko);
 }
 
+void
 quit() {
   fprintf(stderr,"xgrk:Reseting to Latin...\n");
   setmap (d, -1);
