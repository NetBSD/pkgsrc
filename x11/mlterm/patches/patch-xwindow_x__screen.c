$NetBSD: patch-xwindow_x__screen.c,v 1.5 2014/03/07 18:22:50 tsutsui Exp $

Pull mlterm-3.3.3-fixes.patch from upstream:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.3/mlterm-3.3.3-fixes.patch/download
 - Fix the bug which disabled to start mlconfig

--- xwindow/x_screen.c.orig	2014-02-21 16:51:45.000000000 +0000
+++ xwindow/x_screen.c
@@ -5268,11 +5268,13 @@ change_im(
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
@@ -5285,7 +5287,7 @@ get_config_intern(
 		if( ( term = (*screen->system_listener->get_pty)( screen->system_listener->self ,
 				dev)) == NULL)
 		{
-			return  NULL ;
+			return ;
 		}
 	}
 	else
@@ -5829,7 +5831,34 @@ get_config_intern(
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
@@ -5840,31 +5869,7 @@ get_config(
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
@@ -8286,18 +8291,21 @@ x_screen_set_config(
 	}
 	else if( strcmp( value , "switch") == 0)
 	{
-		char *  val ;
+		int  flag ;
+
+		get_config_intern( screen , /* dev */ NULL , key , -1 , &flag) ;
 
-		if( ( val = get_config_intern( screen , /* dev */ NULL , key)))
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
 
@@ -8312,7 +8320,7 @@ x_screen_set_config(
 		if( ( term = (*screen->system_listener->get_pty)( screen->system_listener->self ,
 				dev)) == NULL)
 		{
-			return  0 ;
+			return  1 ;
 		}
 	}
 	else
@@ -8838,7 +8846,7 @@ x_screen_set_config(
 			}
 			else
 			{
-				return  0 ;
+				return  1 ;
 			}
 
 			usascii_font_cs_changed( screen , ml_term_get_encoding( screen->term)) ;
