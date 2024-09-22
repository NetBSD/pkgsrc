$NetBSD: patch-uitoolkit_ui__screen__manager.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * vt_parser.[ch], ui_screen.c, ui_screen_manager.c, vterm.c:
  >   Add 'transparent' to vt_xterm_event_listener_t::get_picture_data().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/ui_screen_manager.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_screen_manager.c
@@ -420,7 +420,8 @@ static vt_char_t *get_picture_data(void 
                                    int *num_rows /* can be 0 */,
                                    int *num_cols_small /* set only if drcs_sixel is 1. */,
                                    int *num_rows_small /* set only if drcs_sixel is 1. */,
-                                   u_int32_t **sixel_palette, int keep_aspect, int drcs_sixel) {
+                                   u_int32_t **sixel_palette, int *transparent,
+                                   int keep_aspect, int drcs_sixel) {
   vt_char_t *data;
 
   if (num_screens > 0) {
@@ -431,7 +432,8 @@ static vt_char_t *get_picture_data(void 
     data = (*screens[0]->xterm_listener.get_picture_data)(screens[0]->xterm_listener.self,
                                                           file_path, num_cols, num_rows,
                                                           num_cols_small, num_rows_small,
-                                                          sixel_palette, 0, drcs_sixel);
+                                                          sixel_palette, transparent,
+                                                          0, drcs_sixel);
     screens[0]->term = orig_term;
   } else {
     data = NULL;
