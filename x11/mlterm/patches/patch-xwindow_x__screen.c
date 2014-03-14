$NetBSD: patch-xwindow_x__screen.c,v 1.6 2014/03/14 17:42:17 tsutsui Exp $

Pull mlterm-3.3.3-fixes.patch from upstream:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.3/mlterm-3.3.3-fixes.patch/download
 - Fix the bug which disabled to start mlconfig

https://bitbucket.org/arakiken/mlterm/commits/1b9ecfa74b0f305c89cff60310f671aef7479246#chg-xwindow/x_screen.c
 - x_color_cache and x_color_manager are reloaded after loading a wall
   picture on NetBSD/OpenBSD 4bpp framebuffer.

https://bitbucket.org/arakiken/mlterm/commits/fa6c82190cc62d356285d7dde71e49a9f671b132#chg-xwindow/x_screen.c
 - update mouse cursor fg and bg colors after loading a wall picture
   on NetBSD/OpenBSD 4bpp framebuffer.

--- xwindow/x_screen.c.orig	2014-02-21 16:51:45.000000000 +0000
+++ xwindow/x_screen.c
@@ -1275,6 +1275,28 @@ set_wall_picture(
 		return  0 ;
 	}
 
+#if  defined(USE_FRAMEBUFFER) && (defined(__NetBSD__) || defined(__OpenBSD__))
+	if( screen->window.disp->depth == 4 && strstr( screen->pic_file_path , "six"))
+	{
+		/*
+		 * Color pallette of x_display can be changed by x_acquire_bg_picture().
+		 * (see x_display_set_cmap() called from fb/x_imagelib.c.)
+		 */
+		x_color_cache_unload( screen->color_man->color_cache) ;
+
+		x_color_manager_reload( screen->color_man) ;
+		x_window_set_fg_color( &screen->window ,
+			x_get_xcolor( screen->color_man , ML_FG_COLOR)) ;
+		x_xic_fg_color_changed( &screen->window) ;
+		/* XXX should change scrollbar fg color */
+
+		x_window_set_bg_color( &screen->window ,
+			x_get_xcolor( screen->color_man , ML_BG_COLOR)) ;
+		x_xic_bg_color_changed( &screen->window) ;
+		/* XXX should change scrollbar bg color */
+	}
+#endif
+
 	if( ! x_window_set_wall_picture( &screen->window , pic->pixmap))
 	{
 		x_release_picture( pic) ;
@@ -5268,11 +5290,13 @@ change_im(
  * Callbacks of x_config_event_listener_t events.
  */
 
-static char *
+static void
 get_config_intern(
 	x_screen_t *  screen ,
 	char *  dev ,	/* can be NULL */
-	char *  key	/* can be "error" */
+	char *  key ,	/* can be "error" */
+	int  to_menu ,	/* -1: don't output to pty and menu. */
+	int *  flag	/* 1(true), 0(false) or -1(other) is returned. */
 	)
 {
 	ml_term_t *  term ;
@@ -5285,7 +5309,7 @@ get_config_intern(
 		if( ( term = (*screen->system_listener->get_pty)( screen->system_listener->self ,
 				dev)) == NULL)
 		{
-			return  NULL ;
+			return ;
 		}
 	}
 	else
@@ -5829,7 +5853,34 @@ get_config_intern(
 		}
 	}
 
-	return  value ;
+	if( to_menu >= 0)
+	{
+		if( value == NULL)
+		{
+			ml_term_write( screen->term , "#error\n" , 7 , to_menu) ;
+
+		#ifdef  __DEBUG
+			kik_debug_printf( KIK_DEBUG_TAG " #error\n") ;
+		#endif
+		}
+		else
+		{
+			ml_term_write( screen->term , "#" , 1 , to_menu) ;
+			ml_term_write( screen->term , key , strlen( key) , to_menu) ;
+			ml_term_write( screen->term , "=" , 1 , to_menu) ;
+			ml_term_write( screen->term , value , strlen( value) , to_menu) ;
+			ml_term_write( screen->term , "\n" , 1 , to_menu) ;
+
+		#ifdef  __DEBUG
+			kik_debug_printf( KIK_DEBUG_TAG " #%s=%s\n" , key , value) ;
+		#endif
+		}
+	}
+
+	if( flag)
+	{
+		*flag = value ? true_or_false( value) : -1 ;
+	}
 }
 
 static void
@@ -5840,31 +5891,7 @@ get_config(
 	int  to_menu
 	)
 {
-	x_screen_t *  screen ;
-	char *  value ;
-
-	screen = p ;
-
-	if( ( value = get_config_intern( screen , dev , key)) == NULL)
-	{
-		ml_term_write( screen->term , "#error\n" , 7 , to_menu) ;
-
-	#ifdef  __DEBUG
-		kik_debug_printf( KIK_DEBUG_TAG " #error\n") ;
-	#endif
-	}
-	else
-	{
-		ml_term_write( screen->term , "#" , 1 , to_menu) ;
-		ml_term_write( screen->term , key , strlen( key) , to_menu) ;
-		ml_term_write( screen->term , "=" , 1 , to_menu) ;
-		ml_term_write( screen->term , value , strlen( value) , to_menu) ;
-		ml_term_write( screen->term , "\n" , 1 , to_menu) ;
-
-	#ifdef  __DEBUG
-		kik_debug_printf( KIK_DEBUG_TAG " #%s=%s\n" , key , value) ;
-	#endif
-	}
+	get_config_intern( p , dev , key , to_menu , NULL) ;
 }
 
 static void
@@ -8286,18 +8313,21 @@ x_screen_set_config(
 	}
 	else if( strcmp( value , "switch") == 0)
 	{
-		char *  val ;
+		int  flag ;
 
-		if( ( val = get_config_intern( screen , /* dev */ NULL , key)))
+		get_config_intern( screen , /* dev */ NULL , key , -1 , &flag) ;
+
+		if( flag == 1)
 		{
-			if( strcmp( val , "true") == 0)
-			{
-				value = "false" ;
-			}
-			else if( strcmp( val , "false") == 0)
-			{
-				value = "true" ;
-			}
+			value = "false" ;
+		}
+		else if( flag == 0)
+		{
+			value = "true" ;
+		}
+		else
+		{
+			return  1 ;
 		}
 	}
 
@@ -8312,7 +8342,7 @@ x_screen_set_config(
 		if( ( term = (*screen->system_listener->get_pty)( screen->system_listener->self ,
 				dev)) == NULL)
 		{
-			return  0 ;
+			return  1 ;
 		}
 	}
 	else
@@ -8838,7 +8868,7 @@ x_screen_set_config(
 			}
 			else
 			{
-				return  0 ;
+				return  1 ;
 			}
 
 			usascii_font_cs_changed( screen , ml_term_get_encoding( screen->term)) ;
