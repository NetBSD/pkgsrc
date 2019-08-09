$ NetBSD $

- Fix support for fbi_fboffset != 0
- Fix SEGV when using 8-bpp display on LP64 machine

Reported upstream:
https://bitbucket.org/arakiken/mlterm/pull-requests/5/fix-for-wscons-framebuffer/diff

--- uitoolkit/fb/ui_display.c.orig	2019-07-24 10:51:04.212256656 +0900
+++ uitoolkit/fb/ui_display.c	2019-07-24 10:27:19.883218709 +0900
@@ -214,7 +214,7 @@ static inline ui_window_t *get_window(in
 }
 
 static inline u_char *get_fb(int x, int y) {
-  return _display.fb + (_display.yoffset + y) * _display.line_length +
+  return _display.fb_base + (_display.yoffset + y) * _display.line_length +
          (_display.xoffset + x) * _display.bytes_per_pixel / _display.pixels_per_byte;
 }
 
@@ -2170,8 +2170,11 @@ int ui_cmap_get_closest_color(u_long *cl
   }
 
   if ((linear_search_max = CMAP_SIZE(_display.cmap)) == 256) {
-    if ((linear_search_max = vt_get_closest_256_color(closest, &min, red, green, blue,
-                                                      COLOR_DISTANCE_THRESHOLD)) == 0) {
+    vt_color_t tmp;
+    linear_search_max = vt_get_closest_256_color(&tmp, &min, red, green, blue,
+                                                 COLOR_DISTANCE_THRESHOLD);
+    *closest = tmp; /* XXX needs for LP64 */
+    if (linear_search_max == 0) {
       goto end;
     }
   }
