$NetBSD: patch-xwindow_fb_x__display__x68kgrf.c,v 1.1 2013/12/25 16:32:31 tsutsui Exp $

Pull post-3.3.2 fixes:
 - 0b2987a: fix palette handling on 4bpp framebuffers

--- xwindow/fb/x_display_x68kgrf.c.orig	2013-12-21 17:11:34.000000000 +0000
+++ xwindow/fb/x_display_x68kgrf.c
@@ -563,16 +563,7 @@ gpal_init(
 	return  1 ;
 }
 
-
-/* --- global functions --- */
-
-int
-x68k_tvram_is_enabled(void)
-{
-	return  (grf0_fd != -1) ? 1 : 0 ;
-}
-
-void
+static void
 x68k_set_use_tvram_colors(
 	int  use
 	)
@@ -600,7 +591,7 @@ x68k_set_use_tvram_colors(
 
 static fb_cmap_t *  cmap_new( int  num_of_colors) ;
 
-int
+static int
 x68k_set_tvram_cmap(
 	u_int32_t *  pixels ,
 	u_int  cmap_size
@@ -629,6 +620,15 @@ x68k_set_tvram_cmap(
 	return  0 ;
 }
 
+
+/* --- global functions --- */
+
+int
+x68k_tvram_is_enabled(void)
+{
+	return  (grf0_fd != -1) ? 1 : 0 ;
+}
+
 /*
  * On success, if /dev/grf0 is opened just now, 2 is returned, while if
  * /dev/grf0 has been already opened, 1 is returned.
@@ -676,8 +676,6 @@ x68k_tvram_set_wall_picture(
 							MAP_FILE|MAP_SHARED ,
 							grf0_fd , (off_t)0)) != MAP_FAILED)
 				{
-					u_long  color ;
-
 					/* Enale the text vram. */
 					grf0_reg->videoc.r2 = 0x0030 ;
 
