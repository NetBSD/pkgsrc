$NetBSD: patch-xwindow_fb_x__display.h,v 1.1 2013/12/25 16:32:31 tsutsui Exp $

Pull post-3.3.2 fixes:
 - 0b2987a: fix palette handling on 4bpp framebuffers  

--- xwindow/fb/x_display.h.orig	2013-12-21 17:11:36.000000000 +0000
+++ xwindow/fb/x_display.h
@@ -43,15 +43,13 @@ int  x_cmap_get_closest_color( u_long * 
 int  x_cmap_get_pixel_rgb( u_int8_t *  red , u_int8_t *  green ,
 	u_int8_t *  blue , u_long  pixel) ;
 
+void  x_display_enable_to_change_cmap( int  flag) ;
+
 void  x_display_set_cmap( u_int32_t *  cmap , u_int  cmap_size) ;
 
 #ifdef  USE_GRF
 int  x68k_tvram_is_enabled(void) ;
 
-void  x68k_set_use_tvram_colors( int  use) ;
-
-int  x68k_set_tvram_cmap( u_int32_t *  cmap , u_int  cmap_size) ;
-
 int  x68k_tvram_set_wall_picture( u_short *  image , u_int  width , u_int  height) ;
 #endif
 
