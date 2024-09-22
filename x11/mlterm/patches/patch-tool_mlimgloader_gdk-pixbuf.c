$NetBSD: patch-tool_mlimgloader_gdk-pixbuf.c,v 1.1 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream fixes to use libpng if gdk-pixbuf is not used.
  https://github.com/arakiken/mlterm/commit/0af65caa
  > * README, doc/ja/README.ja: Updated.
  > * uitoolkit/ui_copymode.c: Replace the first character of input text
  >   by '/' or '?' in starting the copy mode every time.
  > * configure.in: Check libpng if gdk-pixbuf is not found.
  > * tool/mlimgloader/libpng.c, stb_image_resize2.h: Added.

--- tool/mlimgloader/gdk-pixbuf.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ tool/mlimgloader/gdk-pixbuf.c
@@ -13,7 +13,9 @@
                      */
 #include <stdlib.h> /* malloc/free/atoi */
 
+#ifndef USE_LIBPNG
 #include <gdk-pixbuf/gdk-pixbuf.h>
+#endif
 
 #include <pobl/bl_debug.h>
 #include <pobl/bl_types.h> /* u_int32_t/u_int16_t */
