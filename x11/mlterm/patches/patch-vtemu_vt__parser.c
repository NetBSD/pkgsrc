$NetBSD: patch-vtemu_vt__parser.c,v 1.3 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * vt_parser.[ch], ui_screen.c, ui_screen_manager.c, vterm.c:
  >   Add 'transparent' to vt_xterm_event_listener_t::get_picture_data().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.
- pull additional upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/92fa70f1
  > * ui_draw_str.c: Add 'int draw_bg' to arguments of draw_picture().
  > * vt_parser.c: show_picture() calls interrupt_vt100_cmd() if
  >   vt_screen_line_feed() returns 2.
  > * vt_edit.c: vt_edit_go_downward() returns 2 if screen scrolling occurs.

--- vtemu/vt_parser.c.orig	2024-09-22 18:21:57.997376990 +0000
+++ vtemu/vt_parser.c
@@ -1948,6 +1948,7 @@ static void show_picture(vt_parser_t *vt
 
   if (HAS_XTERM_LISTENER(vt_parser, get_picture_data)) {
     vt_char_t *data;
+    int transparent;
 
 #ifdef __DEBUG
     struct timeval tv1, tv2;
@@ -1956,7 +1957,7 @@ static void show_picture(vt_parser_t *vt
 
     if ((data = (*vt_parser->xterm_listener->get_picture_data)(
                     vt_parser->xterm_listener->self, file_path, &img_cols, &img_rows, NULL, NULL,
-                    is_sixel ? &vt_parser->sixel_palette : NULL, keep_aspect, 0)) &&
+                    is_sixel ? &vt_parser->sixel_palette : NULL, &transparent, keep_aspect, 0)) &&
         clip_beg_row < img_rows && clip_beg_col < img_cols) {
       vt_char_t *p;
       int row;
@@ -1967,6 +1968,14 @@ static void show_picture(vt_parser_t *vt
       /* Flush buffer before vt_screen_overwrite_chars(picture data). */
       flush_buffer(vt_parser);
 
+      if (transparent) {
+        /*
+         * Clear the cursor not to show it in the background of the transparent
+         * (sixel P2=1) image.
+         */
+        interrupt_vt100_cmd(vt_parser);
+      }
+
 #ifdef __DEBUG
       gettimeofday(&tv2, NULL);
       bl_debug_printf("Processing sixel time (msec) %lu - %lu = %lu\n",
@@ -2033,7 +2042,10 @@ static void show_picture(vt_parser_t *vt
             break;
           }
         } else {
-          vt_screen_line_feed(vt_parser->screen);
+          if (vt_screen_line_feed(vt_parser->screen) == 2 /* scrolled */ && transparent) {
+            /* Clear the background of the line scrolled in */
+            interrupt_vt100_cmd(vt_parser);
+          }
         }
 
         vt_screen_go_horizontally(vt_parser->screen, cursor_col);
@@ -2096,9 +2108,13 @@ static void define_drcs_picture(vt_parse
     }
 
     if (idx <= 0x5f &&
+        /*
+         * DRCS Sixel doesn't support P2=1 (transparent) for now.
+         * (RLogin 2.28.9 also doesn't support it)
+         */
         (data = (*vt_parser->xterm_listener->get_picture_data)(vt_parser->xterm_listener->self,
                                                                path, &cols, &rows, &cols_small,
-                                                               &rows_small, NULL, 0, 1))) {
+                                                               &rows_small, NULL, NULL, 0, 1))) {
       u_int pages;
       u_int offset = 0;
       vt_drcs_font_t *font;
