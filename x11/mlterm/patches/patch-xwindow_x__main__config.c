$NetBSD: patch-xwindow_x__main__config.c,v 1.1 2014/03/07 18:22:50 tsutsui Exp $

Pull fixes for NetBSD/x68k framebuffer from upstream:
https://bitbucket.org/arakiken/mlterm/commits/f32b4ef020ab4ce25ab46166efac5c02f5e692eb
 - The default value "separate_wall_picture" option is changed to true

--- xwindow/x_main_config.c.orig	2014-02-21 16:51:45.000000000 +0000
+++ xwindow/x_main_config.c
@@ -282,7 +282,7 @@ x_prepare_for_main_config(
 		"embold glyphs by drawing doubly at 1 pixel leftward instead of rightward.") ;
 #ifdef  USE_GRF
 	kik_conf_add_opt( conf , '\0' , "multivram" , 1 , "separate_wall_picture" ,
-		"draw wall picture on another vram. (available on 4bpp) [false]") ;
+		"draw wall picture on another vram. (available on 4bpp) [true]") ;
 #endif
 #ifdef  USE_FRAMEBUFFER
 	kik_conf_add_opt( conf , '\0' , "rotate" , 0 , "rotate_display" ,
@@ -1368,12 +1368,9 @@ x_main_config_init(
 #ifdef  USE_GRF
 	if( ( value = kik_conf_get_value( conf , "separate_wall_picture")))
 	{
-		if( strcmp( value , "true") == 0)
-		{
-			extern int  separate_wall_picture ;
+		extern int  separate_wall_picture ;
 
-			separate_wall_picture = 1 ;
-		}
+		separate_wall_picture = (strcmp( value , "true") == 0 ? 1 : 0) ;
 	}
 #endif
 
