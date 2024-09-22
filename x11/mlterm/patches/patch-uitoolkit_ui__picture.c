$NetBSD: patch-uitoolkit_ui__picture.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_picture.[ch]: Add 'transparent' to ui_inline_picture_t.
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/ui_picture.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_picture.c
@@ -189,8 +189,8 @@ static ui_icon_picture_t *create_icon_pi
   }
 
   if ((pic->file_path = strdup(file_path)) == NULL ||
-      !ui_imagelib_load_file(disp, file_path, &(pic->cardinal), &(pic->pixmap), &(pic->mask),
-                             &icon_size, &icon_size, 0)) {
+      !ui_imagelib_load_file(disp, file_path, 0, &(pic->cardinal), &(pic->pixmap), &(pic->mask),
+                             &icon_size, &icon_size, NULL)) {
     free(pic->file_path);
     free(pic);
 
@@ -536,13 +536,15 @@ static int load_file(void *p) {
   PixmapMask mask;
   u_int width;
   u_int height;
+  int transparent;
 
   idx = ((inline_pic_args_t*)p)->idx;
   width = inline_pics[idx].width;
   height = inline_pics[idx].height;
 
-  if (ui_imagelib_load_file(inline_pics[idx].disp, inline_pics[idx].file_path, NULL, &pixmap, &mask,
-                            &width, &height, ((inline_pic_args_t*)p)->keep_aspect)) {
+  if (ui_imagelib_load_file(inline_pics[idx].disp, inline_pics[idx].file_path,
+                            ((inline_pic_args_t*)p)->keep_aspect, NULL,
+                            &pixmap, &mask, &width, &height, &transparent)) {
     if (strstr(inline_pics[idx].file_path, "mlterm/anim")) {
       /* GIF Animation frame */
       unlink(inline_pics[idx].file_path);
@@ -553,11 +555,12 @@ static int load_file(void *p) {
     inline_pics[idx].width = width;
     inline_pics[idx].height = height;
     inline_pics[idx].pixmap = pixmap;
+    inline_pics[idx].transparent = transparent;
 
 #ifdef DEBUG
-    bl_debug_printf(BL_DEBUG_TAG " new inline picture (%s %d %d %d %p %p) is created.\n",
-                    inline_pics[idx].file_path, idx, width, height, inline_pics[idx].pixmap,
-                    inline_pics[idx].mask);
+    bl_debug_printf(BL_DEBUG_TAG " new inline picture (%s %d %d %d %d %p %p) is created.\n",
+                    inline_pics[idx].file_path, idx, width, height, transparent,
+                    pixmap, mask);
 #endif
 
     return 1;
@@ -1173,7 +1176,7 @@ int ui_load_tmp_picture(ui_display_t *di
                         u_int *width, u_int *height) {
   *width = *height = 0;
 
-  if (ui_imagelib_load_file(disp, file_path, NULL, pixmap, mask, width, height, 0)) {
+  if (ui_imagelib_load_file(disp, file_path, 0, NULL, pixmap, mask, width, height, NULL)) {
     return 1;
   } else {
     return 0;
