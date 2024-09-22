$NetBSD: patch-uitoolkit_beos_ui__imagelib.c,v 1.1 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/beos/ui_imagelib.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/beos/ui_imagelib.c
@@ -132,15 +132,15 @@ static int check_has_alpha(u_char *image
 }
 
 static int load_file(char *path, /* must be UTF-8 */
-                     u_int *width, u_int *height, ui_picture_modifier_t *pic_mod, Pixmap *pixmap,
-                     PixmapMask *mask) {
+                     u_int *width, u_int *height, ui_picture_modifier_t *pic_mod,
+                     Pixmap *pixmap, PixmapMask *mask, int *transparent) {
   char *suffix;
   u_char *image;
 
   suffix = path + strlen(path) - 4;
 #ifdef BUILTIN_SIXEL
   if (strcasecmp(suffix, ".six") == 0 && *width == 0 && *height == 0 &&
-      (image = load_sixel_from_file(path, width, height))) {
+      (image = load_sixel_from_file(path, width, height, transparent))) {
     adjust_pixmap(image, *width, *height, pic_mod);
     *pixmap = beos_create_image(image, (*width) * (*height) * 4, *width, *height);
   } else
@@ -163,19 +163,48 @@ static int load_file(char *path, /* must
       return 0;
     }
 
+    if (transparent) {
+      *transparent = 0;
+    }
+
     if (!ui_picture_modifier_is_normal(pic_mod)) {
       Pixmap new_pixmap;
+      u_char *image2;
 
       image = beos_get_bits(*pixmap);
-      adjust_pixmap2(image, *width, *height, pic_mod);
-      new_pixmap = beos_create_image(image, (*width) * (*height) * 4, *width, *height);
-      beos_destroy_image(*pixmap);
-      *pixmap = new_pixmap;
+      if ((image2 = malloc((*width) * (*height) * 4))) {
+        image = memcpy(image2, image, (*width) * (*height) * 4);
+        beos_destroy_image(*pixmap);
+        adjust_pixmap2(image, *width, *height, pic_mod);
+        new_pixmap = beos_create_image(image, (*width) * (*height) * 4, *width, *height);
+        free(image);
+        *pixmap = new_pixmap;
+      }
     }
   }
 
-  if (mask) {
-    *mask = None;
+  if (transparent && *transparent) {
+  dummy_mask:
+    if (mask) {
+      /* dummy (If cur_pic->mask is non-zero, need_clear = 1 in draw_picture() in ui_draw_str.c) */
+      *mask = 1;
+    }
+  } else {
+    int x, y;
+    u_int32_t *p = (u_int32_t*)image;
+
+    for (y = 0; y < *height; y++) {
+      for (x = 0; x < *width; x++) {
+        if ((((*p) >> 24) & 0xff) <= 0x7f) { /* alpha */
+          goto dummy_mask;
+        }
+        p ++;
+      }
+    }
+
+    if (mask) {
+      *mask = None;
+    }
   }
 
   return 1;
@@ -193,7 +222,7 @@ Pixmap ui_imagelib_load_file_for_backgro
   u_int width = 0;
   u_int height = 0;
 
-  if (!load_file(path, &width, &height, pic_mod, &pixmap, NULL)) {
+  if (!load_file(path, &width, &height, pic_mod, &pixmap, NULL, NULL)) {
     return None;
   }
 
@@ -210,8 +239,9 @@ Pixmap ui_imagelib_get_transparent_backg
   return None;
 }
 
-int ui_imagelib_load_file(ui_display_t *disp, char *path, u_int32_t **cardinal, Pixmap *pixmap,
-                          PixmapMask *mask, u_int *width, u_int *height, int keep_aspect) {
+int ui_imagelib_load_file(ui_display_t *disp, char *path, int keep_aspect, u_int32_t **cardinal,
+                          Pixmap *pixmap, PixmapMask *mask, u_int *width, u_int *height,
+                          int *transparent) {
   u_int pix_width = 0;
   u_int pix_height = 0;
 
@@ -219,7 +249,7 @@ int ui_imagelib_load_file(ui_display_t *
     return 0;
   }
 
-  if (!load_file(path, &pix_width, &pix_height, NULL, pixmap, mask)) {
+  if (!load_file(path, &pix_width, &pix_height, NULL, pixmap, mask, transparent)) {
     return 0;
   }
 
