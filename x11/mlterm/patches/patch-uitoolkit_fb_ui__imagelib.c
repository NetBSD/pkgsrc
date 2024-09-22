$NetBSD: patch-uitoolkit_fb_ui__imagelib.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/fb/ui_imagelib.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/fb/ui_imagelib.c
@@ -294,7 +294,8 @@ error:
 
 /* depth should be checked by the caller. */
 static int load_sixel_with_mask_from_data_1bpp(char *file_data, u_int width, u_int height,
-                                               Pixmap *pixmap, PixmapMask *mask) {
+                                               Pixmap *pixmap, PixmapMask *mask,
+                                               int *transparent) {
   int x;
   int y;
   u_char *src;
@@ -307,7 +308,7 @@ static int load_sixel_with_mask_from_dat
   }
 
   if (!((*pixmap)->image =
-            load_sixel_from_data_1bpp(file_data, &(*pixmap)->width, &(*pixmap)->height)) ||
+        load_sixel_from_data_1bpp(file_data, &(*pixmap)->width, &(*pixmap)->height, transparent)) ||
       /* resize_sixel() frees pixmap->image in failure. */
       !resize_sixel(*pixmap, width, height, 1)) {
     free(*pixmap);
@@ -662,7 +663,7 @@ error:
 
 static int load_file(Display *display, char *path, u_int width, u_int height, int keep_aspect,
                      ui_picture_modifier_t *pic_mod, u_int depth, Pixmap *pixmap,
-                     PixmapMask *mask) {
+                     PixmapMask *mask, int *transparent) {
   if (!path || !*path) {
     return 0;
   }
@@ -679,7 +680,8 @@ static int load_file(Display *display, c
 #if (defined(__NetBSD__) || defined(__OpenBSD__)) && !defined(USE_GRF)
     if (depth == 1) {
       /* pic_mod is ignored. */
-      if (load_sixel_with_mask_from_data_1bpp(file_data, width, height, pixmap, mask)) {
+      if (load_sixel_with_mask_from_data_1bpp(file_data, width, height, pixmap, mask,
+                                              transparent)) {
         free(file_data);
         return 1;
       }
@@ -703,7 +705,8 @@ static int load_file(Display *display, c
       if (depth <= 8) {
         if (ui_picture_modifier_is_normal(pic_mod) /* see modify_pixmap() */) {
           if (((*pixmap)->image = load_sixel_from_data_sharepalette(file_data, &(*pixmap)->width,
-                                                                    &(*pixmap)->height)) &&
+                                                                    &(*pixmap)->height,
+                                                                    transparent)) &&
               resize_sixel(*pixmap, width, height, BPP_PSEUDO)) {
             if (mask) {
               *mask = NULL;
@@ -727,7 +730,7 @@ static int load_file(Display *display, c
 #endif
 
       if (((*pixmap)->image = load_sixel_from_data(file_data, &(*pixmap)->width,
-                                                   &(*pixmap)->height)) &&
+                                                   &(*pixmap)->height, transparent)) &&
           /* resize_sixel() frees pixmap->image in failure. */
           resize_sixel(*pixmap, width, height, 4)) {
 #ifdef WALL_PICTURE_SIXEL_REPLACES_SYSTEM_PALETTE
@@ -748,6 +751,10 @@ static int load_file(Display *display, c
   }
 #endif /* BUILTIN_SIXEL */
 
+  if (transparent) {
+    *transparent = 0;
+  }
+
   if (!exec_mlimgloader(path, width, height, keep_aspect, pixmap)) {
     return 0;
   }
@@ -810,7 +817,7 @@ Pixmap ui_imagelib_load_file_for_backgro
 #endif
 
   if (!load_file(win->disp->display, path, ACTUAL_WIDTH(win), ACTUAL_HEIGHT(win), 0, pic_mod,
-                 win->disp->depth, &pixmap, NULL)) {
+                 win->disp->depth, &pixmap, NULL, NULL)) {
     pixmap = None;
   }
 
@@ -827,14 +834,15 @@ Pixmap ui_imagelib_get_transparent_backg
   return None;
 }
 
-int ui_imagelib_load_file(ui_display_t *disp, char *path, u_int32_t **cardinal, Pixmap *pixmap,
-                          PixmapMask *mask, u_int *width, u_int *height, int keep_aspect) {
+int ui_imagelib_load_file(ui_display_t *disp, char *path, int keep_aspect, u_int32_t **cardinal,
+                          Pixmap *pixmap, PixmapMask *mask, u_int *width, u_int *height,
+                          int *transparent) {
   if (cardinal) {
     return 0;
   }
 
   if (!load_file(disp->display, path, *width, *height, keep_aspect, NULL, disp->depth,
-                 pixmap, mask)) {
+                 pixmap, mask, transparent)) {
     return 0;
   }
 
