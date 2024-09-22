$NetBSD: patch-libvterm_vterm.c,v 1.1 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * vt_parser.[ch], ui_screen.c, ui_screen_manager.c, vterm.c:
  >   Add 'transparent' to vt_xterm_event_listener_t::get_picture_data().

--- libvterm/vterm.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ libvterm/vterm.c
@@ -239,7 +239,8 @@ static vt_char_t *xterm_get_picture_data
                                          int *num_rows, /* If *num_rows > 0, ignored. */
                                          int *num_cols_small /* set only if drcs_sixel is 1. */,
                                          int *num_rows_small /* set only if drcs_sixel is 1. */,
-                                         u_int32_t **sixel_palette, int drcs_sixel) {
+                                         u_int32_t **sixel_palette, int *transparent,
+                                         int keep_aspect, int drcs_sixel) {
   static int old_drcs_sixel = -1;
   VTerm *vterm = p;
   u_int width;
@@ -293,6 +294,10 @@ static vt_char_t *xterm_get_picture_data
     }
   }
 
+  if (transparent) {
+    *transparent = 0;
+  }
+
   if (sscanf(data_p, "\"%d;%d;%d;%d", &x, &y, &width, &height) != 4 ||
       width == 0 || height == 0) {
     struct stat st;
@@ -308,7 +313,7 @@ static vt_char_t *xterm_get_picture_data
     len += fread(all_data + len, 1, st.st_size - len, fp);
     all_data[len] = '\0';
 
-    if (!(picture = load_sixel_from_data_1bpp(all_data, &width, &height))) {
+    if (!(picture = load_sixel_from_data_1bpp(all_data, &width, &height, transparent))) {
       free(all_data);
 
       goto error_closing_fp;
