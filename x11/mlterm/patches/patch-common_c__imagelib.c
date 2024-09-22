$NetBSD: patch-common_c__imagelib.c,v 1.5 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- common/c_imagelib.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ common/c_imagelib.c
@@ -152,7 +152,7 @@ static GdkPixbuf *gdk_pixbuf_new_from_si
   u_int width;
   u_int height;
 
-  if (!(pixels = load_sixel_from_file(path, &width, &height))) {
+  if (!(pixels = load_sixel_from_file(path, &width, &height, NULL))) {
     return NULL;
   }
 
