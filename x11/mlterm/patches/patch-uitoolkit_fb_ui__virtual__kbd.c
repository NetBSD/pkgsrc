$NetBSD: patch-uitoolkit_fb_ui__virtual__kbd.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_virtual_kbd.c, ui_sb_view.h, pixmap_engine.c: Fix with the modification
  >   of ui_imagelib_load_file().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().

--- uitoolkit/fb/ui_virtual_kbd.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/fb/ui_virtual_kbd.c
@@ -240,8 +240,8 @@ static int start_virtual_kbd(ui_display_
   } else {
     width = 0;
     height = 0;
-    if (!ui_imagelib_load_file(disp, KBD_DIR "/pressed_kbd.six", NULL, &pressed_pixmap, NULL,
-                               &width, &height, 0)) {
+    if (!ui_imagelib_load_file(disp, KBD_DIR "/pressed_kbd.six", 0, NULL, &pressed_pixmap, NULL,
+                               &width, &height, NULL)) {
       /*
        * Note that pressed_pixmap can be non-NULL even if
        * ui_imagelib_load_file() fails.
@@ -253,8 +253,8 @@ static int start_virtual_kbd(ui_display_
 
     width = 0;
     height = 0;
-    if (!ui_imagelib_load_file(disp, KBD_DIR "/kbd.six", NULL, &normal_pixmap, NULL, &width,
-                               &height, 0)) {
+    if (!ui_imagelib_load_file(disp, KBD_DIR "/kbd.six", 0, NULL, &normal_pixmap, NULL,
+                               &width, &height, NULL)) {
       /*
        * Note that normal_pixmap can be non-NULL even if
        * ui_imagelib_load_file() fails.
