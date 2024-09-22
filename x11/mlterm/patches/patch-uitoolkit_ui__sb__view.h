$NetBSD: patch-uitoolkit_ui__sb__view.h,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_virtual_kbd.c, ui_sb_view.h, pixmap_engine.c: Fix with the modification
  >   of ui_imagelib_load_file().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().

--- uitoolkit/ui_sb_view.h.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_sb_view.h
@@ -74,9 +74,9 @@ typedef struct ui_sb_view_conf {
   unsigned int rc_num;
   unsigned int use_count;
 
-  int (*load_image)(__ui_display_ptr_t disp, char *path,
+  int (*load_image)(__ui_display_ptr_t disp, char *path, int keep_aspect,
                     /* u_int32_t */ unsigned int **cardinal, Pixmap *pixmap, PixmapMask *mask,
-                    unsigned int *width, unsigned int *height, int);
+                    unsigned int *width, unsigned int *height, int *transparent);
 
 } ui_sb_view_conf_t;
 
