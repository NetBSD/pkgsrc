$NetBSD: patch-contrib_scrollbar_pixmap__engine_pixmap__engine.c,v 1.1 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_virtual_kbd.c, ui_sb_view.h, pixmap_engine.c: Fix with the modification
  >   of ui_imagelib_load_file().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().

--- contrib/scrollbar/pixmap_engine/pixmap_engine.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ contrib/scrollbar/pixmap_engine/pixmap_engine.c
@@ -143,7 +143,7 @@ static void load_image(ui_display_t *dis
   path = malloc(sizeof(char) * (len + 1));
   sprintf(path, "%s/%s.png", conf->dir, file);
 
-  if (!(*conf->load_image)(disp, path, NULL, pixmap, mask, width, height, 0)) {
+  if (!(*conf->load_image)(disp, path, 0, NULL, pixmap, mask, width, height, NULL)) {
 #ifdef __DEBUG
     printf("ui_imagelib_load_file() failed\n");
     ;
