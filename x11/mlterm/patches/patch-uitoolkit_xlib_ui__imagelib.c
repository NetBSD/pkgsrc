$NetBSD: patch-uitoolkit_xlib_ui__imagelib.c,v 1.6 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.
- pull upstream <8 depth fixes:
  https://github.com/arakiken/mlterm/commit/63bb60ee
  > * xlib/ui_imagelib.c: load_sixel() supports less than 8 depth.

--- uitoolkit/xlib/ui_imagelib.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/xlib/ui_imagelib.c
@@ -415,8 +415,8 @@ static void update_diff_table_last(char 
 static int load_sixel(ui_display_t *disp, char *path, Pixmap *pixmap,
                       Pixmap *mask, /* Can be NULL */
                       u_int *width, /* Can be NULL */
-                      u_int *height /* Can be NULL */
-                      ) {
+                      u_int *height, /* Can be NULL */
+                      int *transparent /* Can be NULL */) {
   XImage *image;
   u_int32_t *data;
   u_int32_t *in;
@@ -428,7 +428,7 @@ static int load_sixel(ui_display_t *disp
   GC mask_gc;
   int num_cells;
 
-  if (disp->depth < 8 || !(data = in = load_sixel_from_file(path, &w, &h))) {
+  if (!(data = in = load_sixel_from_file(path, &w, &h, transparent))) {
     return 0;
   }
 
@@ -436,7 +436,7 @@ static int load_sixel(ui_display_t *disp
     *mask = None;
   }
 
-  if (disp->depth == 8) {
+  if (disp->depth <= 8) {
     XColor *color_list;
     int closest;
     u_char *out8;
@@ -577,23 +577,43 @@ static int load_sixel(ui_display_t *disp
     XFreeGC(disp->display, mask_gc);
   }
 
-  image = XCreateImage(disp->display, disp->visual, disp->depth, ZPixmap, 0, data, w, h,
-                       /* in case depth isn't multiple of 8 */
-                       bytes_per_pixel * 8, w * bytes_per_pixel);
+  if (!(*pixmap = XCreatePixmap(disp->display, ui_display_get_group_leader(disp),
+                                w, h, disp->depth))) {
+    free(data);
+
+    return 0;
+  }
+
+  if (disp->depth < 8) {
+    XGCValues gcv;
+    GC gc = XCreateGC(disp->display, ui_display_get_group_leader(disp), 0, &gcv);
+    u_char *out8 = data;
+
+    for (y = 0; y < h; y++) {
+      for (x = 0; x < w; x++) {
+        XSetForeground(disp->display, gc, *(out8++));
+        XDrawPoint(disp->display, *pixmap, gc, x, y);
+      }
+    }
+
+    free(data);
+    XFreeGC(disp->display, gc);
+  } else {
+    image = XCreateImage(disp->display, disp->visual, disp->depth, ZPixmap, 0, data, w, h,
+                         /* in case depth isn't multiple of 8 */
+                         bytes_per_pixel * 8, w * bytes_per_pixel);
 #ifdef WORDS_BIGENDIAN
-  image->byte_order = MSBFirst;
+    image->byte_order = MSBFirst;
 #else
-  image->byte_order = LSBFirst;
+    image->byte_order = LSBFirst;
 #endif
-
-  *pixmap = XCreatePixmap(disp->display, ui_display_get_group_leader(disp), w, h, disp->depth);
-
-  XPutImage(disp->display, *pixmap, disp->gc->gc, image, 0, 0, 0, 0, w, h);
+    XPutImage(disp->display, *pixmap, disp->gc->gc, image, 0, 0, 0, 0, w, h);
 #ifdef BL_DEBUG
-  destroy_image(image);
+    destroy_image(image);
 #else
-  XDestroyImage(image);
+    XDestroyImage(image);
 #endif
+  }
 
   if (width) {
     *width = w;
@@ -1711,8 +1731,9 @@ Pixmap ui_imagelib_get_transparent_backg
  *
  *\return  Success => 1, Failure => 0
  */
-int ui_imagelib_load_file(ui_display_t *disp, char *path, u_int32_t **cardinal, Pixmap *pixmap,
-                          PixmapMask *mask, u_int *width, u_int *height, int keep_aspect) {
+int ui_imagelib_load_file(ui_display_t *disp, char *path, int keep_aspect, u_int32_t **cardinal,
+                          Pixmap *pixmap, PixmapMask *mask, u_int *width, u_int *height,
+                          int *transparent) {
   u_int dst_height, dst_width;
 #ifdef BUILTIN_IMAGELIB
   GdkPixbuf *pixbuf;
@@ -1723,11 +1744,15 @@ int ui_imagelib_load_file(ui_display_t *
 
 #if defined(BUILTIN_IMAGELIB) || defined(BUILTIN_SIXEL)
   if (!cardinal && strcasecmp(path + strlen(path) - 4, ".six") == 0 && dst_width == 0 &&
-      dst_height == 0 && load_sixel(disp, path, pixmap, mask, width, height)) {
+      dst_height == 0 && load_sixel(disp, path, pixmap, mask, width, height, transparent)) {
     return 1;
   }
 #endif
 
+  if (transparent) {
+    *transparent = 0;
+  }
+
 #ifdef BUILTIN_IMAGELIB
 
   if (path) {
