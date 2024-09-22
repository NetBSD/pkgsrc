$NetBSD: patch-uitoolkit_console_ui__imagelib.c,v 1.1 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/console/ui_imagelib.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/console/ui_imagelib.c
@@ -253,7 +253,7 @@ error:
 
 static int load_file(Display *display, char *path, u_int width, u_int height, int keep_aspect,
                      ui_picture_modifier_t *pic_mod, u_int depth, Pixmap *pixmap,
-                     PixmapMask *mask) {
+                     PixmapMask *mask, int *transparent) {
   pid_t pid;
   int fds[2];
   ssize_t size;
@@ -270,7 +270,8 @@ static int load_file(Display *display, c
       width == 0 && height == 0 &&
 #endif
       (*pixmap = calloc(1, sizeof(**pixmap)))) {
-    if (((*pixmap)->image = load_sixel_from_file(path, &(*pixmap)->width, &(*pixmap)->height)) &&
+    if (((*pixmap)->image = load_sixel_from_file(path, &(*pixmap)->width, &(*pixmap)->height,
+                                                 NULL)) &&
         /* resize_sixel() frees pixmap->image in failure. */
         resize_sixel(*pixmap, width, height, 4)) {
       goto loaded;
@@ -280,6 +281,10 @@ static int load_file(Display *display, c
   }
 #endif
 
+  if (transparent) {
+    *transparent = 0;
+  }
+
 #ifdef __ANDROID__
   if (!(*pixmap = calloc(1, sizeof(**pixmap)))) {
     return 0;
@@ -415,7 +420,7 @@ Pixmap ui_imagelib_load_file_for_backgro
   Pixmap pixmap;
 
   if (!load_file(win->disp->display, path, ACTUAL_WIDTH(win), ACTUAL_HEIGHT(win), 0, pic_mod,
-                 win->disp->depth, &pixmap, NULL)) {
+                 win->disp->depth, &pixmap, NULL, NULL)) {
     pixmap = None;
   }
 
@@ -428,14 +433,15 @@ Pixmap ui_imagelib_get_transparent_backg
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
 
   if (!load_file(disp->display, path, *width, *height, keep_aspect, NULL,
-                 disp->depth, pixmap, mask)) {
+                 disp->depth, pixmap, mask, transparent)) {
     return 0;
   }
 
