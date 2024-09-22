$NetBSD: patch-uitoolkit_ui__screen.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream fixes to support backward search
  https://github.com/arakiken/mlterm/commit/64552b10
  > * ui_copymode.[ch], ui_screen.c:
  >   Pressing '?' in copy mode searchs for a string backward.
- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * vt_parser.[ch], ui_screen.c, ui_screen_manager.c, vterm.c:
  >   Add 'transparent' to vt_xterm_event_listener_t::get_picture_data().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/ui_screen.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_screen.c
@@ -2310,13 +2310,25 @@ static void copymode_key(ui_screen_t *sc
         int end_char_index;
         int end_row;
 
-        if (search_find(screen, pattern, 0,
+        if (search_find(screen, pattern, screen->copymode->pattern_editing == 2 ? 1 : 0,
                         &beg_char_index, &beg_row, &end_char_index, &end_row)) {
           vt_line_t *line;
 
-          if (vt_term_convert_scr_row_to_abs(screen->term, 0) + (int)vt_term_get_rows(screen->term)
-              <= beg_row) {
-            bs_scroll_to(screen, beg_row - vt_term_get_rows(screen->term) / 2, 0);
+          if (screen->copymode->pattern_editing == 1) {
+            if (vt_term_convert_scr_row_to_abs(screen->term, 0) +
+                (int)vt_term_get_rows(screen->term) <= beg_row) {
+              bs_scroll_to(screen, beg_row - vt_term_get_rows(screen->term) / 2, 0);
+            }
+          } else /* if (screen->copymode->pattern_editing == 2) */ {
+            if (vt_term_convert_scr_row_to_abs(screen->term, 0) > beg_row) {
+              int row = beg_row - vt_term_get_rows(screen->term) / 2;
+
+              if (row < -vt_term_get_num_logged_lines(screen->term)) {
+                row = -vt_term_get_num_logged_lines(screen->term);
+              }
+              enter_backscroll_mode(screen);
+              bs_scroll_to(screen, row, 0);
+            }
           }
 
           if ((line = vt_term_get_line(screen->term, screen->copymode->cursor_row))) {
@@ -2348,7 +2360,15 @@ static void copymode_key(ui_screen_t *sc
 #endif
   ) {
     if (!screen->copymode->pattern_editing) {
-      ui_copymode_pattern_start_edit(screen->copymode);
+      ui_copymode_pattern_start_edit(screen->copymode, 0);
+    }
+  } else if ((len == 1 && str[0] == '?')
+#if defined(USE_WIN32GUI) && defined(UTF16_IME_CHAR)
+             || (len == 2 && str[0] == 0 && str[1] == '?')
+#endif
+  ) {
+    if (!screen->copymode->pattern_editing) {
+      ui_copymode_pattern_start_edit(screen->copymode, 1);
     }
   } else {
     redraw_mode |= UPDATE_CURSOR;
@@ -6209,8 +6229,9 @@ static vt_char_t *xterm_get_picture_data
                                          int *num_rows /* can be 0 */,
                                          int *num_cols_small /* set only if drcs_sixel is 1. */,
                                          int *num_rows_small /* set only if drcs_sixel is 1. */,
-                                         u_int32_t **sixel_palette, int keep_aspect,
-                                         int drcs_sixel) {
+                                         u_int32_t **sixel_palette,
+                                         int *transparent /* can be NULL */,
+                                         int keep_aspect, int drcs_sixel) {
   ui_screen_t *screen;
   u_int width;
   u_int height;
@@ -6233,8 +6254,8 @@ static vt_char_t *xterm_get_picture_data
     *sixel_palette = ui_set_custom_sixel_palette(*sixel_palette);
   }
 
-  if ((idx = ui_load_inline_picture(screen->window.disp, file_path, &width, &height, col_width,
-                                    line_height, keep_aspect, screen->term)) != -1) {
+  if ((idx = ui_load_inline_picture(screen->window.disp, file_path, &width, &height,
+                                    col_width, line_height, keep_aspect, screen->term)) != -1) {
     vt_char_t *buf;
     u_int cols_padding[2];
     u_int rows_padding[2];
@@ -6326,6 +6347,10 @@ static vt_char_t *xterm_get_picture_data
       *num_cols += (cols_padding[0] + cols_padding[1]);
       *num_rows += (rows_padding[0] + rows_padding[1]);
 
+      if (transparent) {
+        *transparent = ui_get_inline_picture(idx)->transparent;
+      }
+
       return buf;
     }
   }
@@ -6410,8 +6435,8 @@ static void xterm_add_frame_to_animation
   width = (*num_cols) *(col_width = ui_col_width(screen));
   height = (*num_rows) *(line_height = ui_line_height(screen));
 
-  if ((idx = ui_load_inline_picture(screen->window.disp, file_path, &width, &height, col_width,
-                                    line_height, 0, screen->term)) != -1 &&
+  if ((idx = ui_load_inline_picture(screen->window.disp, file_path, &width, &height,
+                                    col_width, line_height, 0, screen->term)) != -1 &&
       screen->prev_inline_pic != idx) {
     ui_add_frame_to_animation(screen->prev_inline_pic, idx);
     screen->prev_inline_pic = idx;
