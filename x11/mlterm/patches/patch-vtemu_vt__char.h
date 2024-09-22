$NetBSD: patch-vtemu_vt__char.h,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * vt_parser.[ch], ui_screen.c, ui_screen_manager.c, vterm.c:
  >   Add 'transparent' to vt_xterm_event_listener_t::get_picture_data().
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- vtemu/vt_char.h.orig	2023-04-01 13:54:40.000000000 +0000
+++ vtemu/vt_char.h
@@ -93,9 +93,13 @@ typedef struct vt_char {
       u_int bg_color2 : 16;
 #endif
       u_int code : 21;
+      /*
+       * also used for transparent flag of PICTURE_CHARSET
+       * (see vt_char_{get|set}_picture_transparent_flag()
+       */
       u_int attr2 : 2;
-      u_int fg_color : 9;
-      u_int bg_color : 9;
+      u_int fg_color : 9; /* also used for PICTURE_CHARSET (see vt_char_combine_picture()) */
+      u_int bg_color : 9; /* also used for PICTURE_CHARSET (see vt_char_combine_picture()) */
       u_int attr : 23;
 #else
       u_int attr : 23;
