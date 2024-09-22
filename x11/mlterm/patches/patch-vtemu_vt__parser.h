$NetBSD: patch-vtemu_vt__parser.h,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * vt_parser.[ch], ui_screen.c, ui_screen_manager.c, vterm.c:
  >   Add 'transparent' to vt_xterm_event_listener_t::get_picture_data().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- vtemu/vt_parser.h.orig	2023-04-01 13:54:40.000000000 +0000
+++ vtemu/vt_parser.h
@@ -128,8 +128,8 @@ typedef struct vt_xterm_event_listener {
   void (*get_window_size)(void *, u_int *, u_int *);           /* called in logical context. */
   int (*get_rgb)(void *, u_int8_t *, u_int8_t *, u_int8_t *,
                  vt_color_t);                                  /* called in logical context. */
-  vt_char_t *(*get_picture_data)(void *, char *, int *, int *, int *, int *,
-                                 u_int32_t **, int, int);      /* called in logical context. */
+  vt_char_t *(*get_picture_data)(void *, char *, int *, int *, int *, int *, u_int32_t **,
+                                 int *, int, int);             /* called in logical context. */
   int (*get_emoji_data)(void *, vt_char_t *, vt_char_t *);     /* called in logical context. */
   void (*show_tmp_picture)(void *, char *);                    /* called in logical context. */
 #ifdef ENABLE_OSC5379PICTURE
