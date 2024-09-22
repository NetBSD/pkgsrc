$NetBSD: patch-uitoolkit_ui__imagelib.h,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/ui_imagelib.h.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_imagelib.h
@@ -17,8 +17,9 @@ Pixmap ui_imagelib_load_file_for_backgro
 
 Pixmap ui_imagelib_get_transparent_background(ui_window_t *win, ui_picture_modifier_t *pic_mod);
 
-int ui_imagelib_load_file(ui_display_t *disp, char *path, u_int32_t **cardinal, Pixmap *pixmap,
-                          PixmapMask *mask, u_int *width, u_int *height, int keep_aspect);
+int ui_imagelib_load_file(ui_display_t *disp, char *path, int keep_aspect,
+                          u_int32_t **cardinal, Pixmap *pixmap, PixmapMask *mask,
+                          u_int *width, u_int *height, int *transparent);
 
 Pixmap ui_imagelib_pixbuf_to_pixmap(ui_window_t *win, ui_picture_modifier_t *pic_mod,
                                     GdkPixbufPtr pixbuf);
