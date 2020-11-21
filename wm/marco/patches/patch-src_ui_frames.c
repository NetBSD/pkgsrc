$NetBSD: patch-src_ui_frames.c,v 1.1 2020/11/21 03:48:07 gutteridge Exp $

Do not call cairo_paint() on generate_pixmaps. Fixes transparent windows.
https://github.com/mate-desktop/marco/commit/0c2baf71f18f39058edc8459990da27c4d448d81

--- src/ui/frames.c.orig	2020-08-04 18:35:42.000000000 +0000
+++ src/ui/frames.c
@@ -2282,8 +2282,6 @@ generate_pixmap (MetaFrames            *
   cr = cairo_create (result);
   cairo_translate (cr, -rect->x, -rect->y);
 
-  cairo_paint (cr);
-
   meta_frames_paint_to_drawable (frames, frame, cr);
 
   cairo_destroy (cr);
