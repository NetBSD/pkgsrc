$NetBSD: patch-uitoolkit_win32_ui__imagelib.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/win32/ui_imagelib.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/win32/ui_imagelib.c
@@ -83,9 +83,9 @@ static void adjust_pixmap(u_char *image,
   }
 }
 
-static int load_file(char *path, /* must be UTF-8 */
-                     u_int *width, u_int *height, int keep_aspect, ui_picture_modifier_t *pic_mod,
-                     HBITMAP *hbmp, HBITMAP *hbmp_mask) {
+static int load_file(char *path /* must be UTF-8 */, int keep_aspect,
+                     u_int *width, u_int *height, ui_picture_modifier_t *pic_mod,
+                     HBITMAP *hbmp, HBITMAP *hbmp_mask, int *transparent) {
   char *suffix;
   char *cmd_line;
   WCHAR *w_cmd_line;
@@ -107,11 +107,15 @@ static int load_file(char *path, /* must
   if (strcasecmp(suffix, ".six") == 0 && *width == 0 && *height == 0 &&
       /* XXX fopen() in load_sixel_from_file() on win32api doesn't support
          UTF-8. */
-      (image = (u_int32_t *)load_sixel_from_file(path, width, height))) {
+      (image = (u_int32_t *)load_sixel_from_file(path, width, height, transparent))) {
     goto loaded;
   }
 #endif
 
+  if (transparent) {
+    *transparent = 0;
+  }
+
   if (strcasecmp(suffix, ".rgs") == 0) {
     convert_regis_to_bmp(path);
   }
@@ -312,7 +316,7 @@ Pixmap ui_imagelib_load_file_for_backgro
   HDC hmdc;
 
   width = height = 0;
-  if (!load_file(path, &width, &height, 0, pic_mod, &hbmp, NULL)) {
+  if (!load_file(path, 0, &width, &height, pic_mod, &hbmp, NULL, NULL)) {
     BITMAP bmp;
 #if defined(__CYGWIN__) || defined(__MSYS__)
     /* MAX_PATH which is 260 (3+255+1+1) is defined in win32 alone. */
@@ -359,8 +363,9 @@ Pixmap ui_imagelib_get_transparent_backg
   return None;
 }
 
-int ui_imagelib_load_file(ui_display_t *disp, char *path, u_int32_t **cardinal, Pixmap *pixmap,
-                          PixmapMask *mask, u_int *width, u_int *height, int keep_aspect) {
+int ui_imagelib_load_file(ui_display_t *disp, char *path, int keep_aspect, u_int32_t **cardinal,
+                          Pixmap *pixmap, PixmapMask *mask, u_int *width, u_int *height,
+                          int *transparent) {
   HBITMAP hbmp;
   HDC hdc;
   HDC hmdc;
@@ -369,7 +374,7 @@ int ui_imagelib_load_file(ui_display_t *
     return 0;
   }
 
-  if (!load_file(path, width, height, keep_aspect, NULL, &hbmp, mask)) {
+  if (!load_file(path, keep_aspect, width, height, NULL, &hbmp, mask, transparent)) {
     BITMAP bmp;
 #if defined(__CYGWIN__) || defined(__MSYS__)
     /* MAX_PATH which is 260 (3+255+1+1) is defined in win32 alone. */
