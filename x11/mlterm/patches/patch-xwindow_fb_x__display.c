$NetBSD: patch-xwindow_fb_x__display.c,v 1.7 2014/07/21 15:42:56 tsutsui Exp $

- pull post 3.3.7 fixes:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.7/mlterm-3.3.7-fixes.patch/download
 * x_display.c: Key squences on NetBSD/x68k are added to the table in
   receive_stdin_key_event().

--- xwindow/fb/x_display.c.orig	2014-07-05 21:40:41.000000000 +0000
+++ xwindow/fb/x_display.c
@@ -1084,6 +1084,20 @@ receive_stdin_key_event(void)
 			{ "[B" , XK_Down } ,
 			{ "[C" , XK_Right } ,
 			{ "[D" , XK_Left } ,
+		#if  defined(USE_GRF)
+			{ "[7~" , XK_End } ,
+			{ "[1~" , XK_Home } ,
+			{ "OP" , XK_F1 } ,
+			{ "OQ" , XK_F2 } ,
+			{ "OR" , XK_F3 } ,
+			{ "OS" , XK_F4 } ,
+			{ "[17~" , XK_F5 } ,
+			{ "[18~" , XK_F6 } ,
+			{ "[19~" , XK_F7 } ,
+			{ "[20~" , XK_F8 } ,
+			{ "[21~" , XK_F9 } ,
+			{ "[29~" , XK_F10 } ,
+		#else	/* USE_GRF */
 		#if  defined(__NetBSD__) || defined(__OpenBSD__)
 			{ "[8~" , XK_End } ,
 			{ "[7~" , XK_Home } ,
@@ -1117,6 +1131,7 @@ receive_stdin_key_event(void)
 			{ "[21~" , XK_F10 } ,
 			{ "[23~" , XK_F11 } ,
 			{ "[24~" , XK_F12 } ,
+		#endif	/* USE_GRF */
 		} ;
 
 		size_t  count ;
@@ -1468,7 +1483,7 @@ x_display_close_all(void)
 {
 	if( DISP_IS_INITED)
 	{
-		x_picture_display_closed( &_disp.display) ;
+		x_picture_display_closed( _disp.display) ;
 
 		x_virtual_kbd_hide() ;
 
