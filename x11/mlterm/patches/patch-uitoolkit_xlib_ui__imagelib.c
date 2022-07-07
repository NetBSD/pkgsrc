$NetBSD: patch-uitoolkit_xlib_ui__imagelib.c,v 1.4 2022/07/07 00:08:29 rin Exp $

Fix color of sixel image on X server whose byte-order is opposite to client.

This patch has been merged to upstream, and will be in the next release.

--- uitoolkit/xlib/ui_imagelib.c.orig	2022-07-02 10:56:15.200011767 +0900
+++ uitoolkit/xlib/ui_imagelib.c	2022-07-02 10:58:10.298442685 +0900
@@ -580,6 +580,11 @@ static int load_sixel(ui_display_t *disp
   image = XCreateImage(disp->display, disp->visual, disp->depth, ZPixmap, 0, data, w, h,
                        /* in case depth isn't multiple of 8 */
                        bytes_per_pixel * 8, w * bytes_per_pixel);
+#ifdef WORDS_BIGENDIAN
+  image->byte_order = MSBFirst;
+#else
+  image->byte_order = LSBFirst;
+#endif
 
   *pixmap = XCreatePixmap(disp->display, ui_display_get_group_leader(disp), w, h, disp->depth);
 
@@ -944,6 +949,11 @@ static XImage *pixbuf_to_ximage_truecolo
 
     return NULL;
   }
+#ifdef WORDS_BIGENDIAN
+  image->byte_order = MSBFirst;
+#else
+  image->byte_order = LSBFirst;
+#endif
 
   /* set num of bytes per pixel of pixbuf */
   bytes_per_pixel = (gdk_pixbuf_get_has_alpha(pixbuf)) ? 4 : 3;
@@ -1617,6 +1627,11 @@ Pixmap ui_imagelib_get_transparent_backg
 
       return None;
     }
+#ifdef WORDS_BIGENDIAN
+    image->byte_order = MSBFirst;
+#else
+    image->byte_order = LSBFirst;
+#endif
 
     vinfo_template.visualid =
         XVisualIDFromVisual(DefaultVisual(win->disp->display, DefaultScreen(win->disp->display)));
