$NetBSD: patch-xcursorgen.c,v 1.1 2011/04/05 11:06:59 wiz Exp $

Fix build with png-1.5.

--- xcursorgen.c.orig	2003-02-28 13:19:21.000000000 +0000
+++ xcursorgen.c
@@ -182,7 +182,7 @@ load_image (struct flist *list, char *pr
       return NULL;
     }
 
-  if (setjmp (png->jmpbuf))
+  if (setjmp (png_jmpbuf(png)))
     {
       png_destroy_read_struct (&png, &info, NULL);
       return NULL;
