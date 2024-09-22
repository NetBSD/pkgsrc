$NetBSD: patch-uitoolkit_ui__picture.h,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_picture.[ch]: Add 'transparent' to ui_inline_picture_t.
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- uitoolkit/ui_picture.h.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_picture.h
@@ -56,8 +56,8 @@ typedef struct ui_inline_picture {
   vt_term_t *term;
   u_int8_t col_width;
   u_int8_t line_height;
-
   int16_t next_frame;
+  int8_t transparent;
 
 } ui_inline_picture_t;
 
