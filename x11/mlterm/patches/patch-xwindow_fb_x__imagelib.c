$NetBSD: patch-xwindow_fb_x__imagelib.c,v 1.1 2013/12/25 16:32:31 tsutsui Exp $

Pull post-3.3.2 fixes:
 - 0b2987a: fix palette handling on 4bpp framebuffers

--- xwindow/fb/x_imagelib.c.orig	2013-12-21 17:11:37.000000000 +0000
+++ xwindow/fb/x_imagelib.c
@@ -211,7 +211,7 @@ modify_pixmap(
 #endif
 
 /* For old machines */
-#if  defined(__NetBSD__) || defined(__OpenBSD__)
+#if  (defined(__NetBSD__) || defined(__OpenBSD__)) && ! defined(USE_GRF)
 
 #ifndef  BUILTIN_IMAGELIB
 #define  BUILTIN_IMAGELIB
@@ -340,7 +340,7 @@ load_file(
 	}
 
 /* For old machines */
-#if  defined(__NetBSD__) || defined(__OpenBSD__)
+#if  (defined(__NetBSD__) || defined(__OpenBSD__)) && ! defined(USE_GRF)
 	if( depth == 1)
 	{
 		if( load_sixel_with_mask_from_file_1bpp( display , path , width , height ,
@@ -358,12 +358,7 @@ load_file(
 						&(*pixmap)->width , &(*pixmap)->height)))
 		{
 		#if  defined(__NetBSD__) || defined(__OpenBSD__)
-		#ifdef  USE_GRF
-			if( ! x68k_set_tvram_cmap( sixel_cmap , sixel_cmap_size))
-		#endif
-			{
-				x_display_set_cmap( sixel_cmap , sixel_cmap_size) ;
-			}
+			x_display_set_cmap( sixel_cmap , sixel_cmap_size) ;
 		#endif
 
 			goto  loaded ;
@@ -570,8 +565,8 @@ x_imagelib_load_file_for_background(
 {
 	Pixmap  pixmap ;
 
-#ifdef  USE_GRF
-	x68k_set_use_tvram_colors( 1) ;
+#if  defined(__NetBSD__) || defined(__OpenBSD__)
+	x_display_enable_to_change_cmap( 1) ;
 #endif
 
 	if( ! load_file( win->disp->display , path ,
@@ -581,8 +576,8 @@ x_imagelib_load_file_for_background(
 		pixmap = None ;
 	}
 
-#ifdef  USE_GRF
-	x68k_set_use_tvram_colors( 0) ;
+#if  defined(__NetBSD__) || defined(__OpenBSD__)
+	x_display_enable_to_change_cmap( 0) ;
 #endif
 
 	return  pixmap ;
