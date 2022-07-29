$NetBSD: patch-src_pixmap.c,v 1.1 2022/07/29 06:05:49 rin Exp $

imlib_strerror() has been introduced to imlib2; mangle local version.

--- src/pixmap.c.orig	2022-07-29 02:12:11.471134723 +0900
+++ src/pixmap.c	2022-07-29 02:12:47.891883811 +0900
@@ -172,7 +172,7 @@ image_mode_any(unsigned char mode)
 
 #ifdef PIXMAP_SUPPORT
 const char *
-imlib_strerror(Imlib_Load_Error err)
+eterm_imlib_strerror(Imlib_Load_Error err)
 {
     switch (err) {
         case IMLIB_LOAD_ERROR_NONE:
@@ -1447,7 +1447,7 @@ load_image(const char *file, simage_t *s
         if (f) {
             im = imlib_load_image_with_error_return(f, &im_err);
             if (!im) {
-                libast_print_error("Unable to load image file \"%s\" -- %s\n", file, imlib_strerror(im_err));
+                libast_print_error("Unable to load image file \"%s\" -- %s\n", file, eterm_imlib_strerror(im_err));
                 return 0;
             } else {
                 reset_simage(simg, (RESET_IMLIB_IM | RESET_PMAP_PIXMAP | RESET_PMAP_MASK));
@@ -2178,7 +2178,7 @@ set_icon_pixmap(char *filename, XWMHints
 
             temp_im = imlib_load_image_with_error_return(icon_path, &im_err);
             if (!temp_im) {
-                libast_print_error("Unable to load icon file \"%s\" -- %s\n", icon_path, imlib_strerror(im_err));
+                libast_print_error("Unable to load icon file \"%s\" -- %s\n", icon_path, eterm_imlib_strerror(im_err));
             } else {
                 /* If we're going to render the image anyway, might as well be nice and give it to the WM in a size it likes. */
                 if (XGetIconSizes(Xdisplay, Xroot, &icon_sizes, &count)) {
