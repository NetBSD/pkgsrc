$NetBSD: patch-xwindow_fb_x__display__wscons.c,v 1.1 2014/05/02 05:09:29 tsutsui Exp $

Pull post-3.3.5 bug fix:
https://bitbucket.org/arakiken/mlterm/commits/aea132fea6b324125be7383f210c09d24cfe67d4?at=default#chg-xwindow/fb/x_display_wscons.c
 - WSDISPLAYIO_MODE_DUMBFB is used instead of WSDISPLAYIO_MODE_MAPPED
   on NetBSD.

+++ xwindow/fb/x_display_wscons.c
@@ -359,9 +359,7 @@ open_display(
 
 	ioctl( STDIN_FILENO , WSDISPLAYIO_GMODE , &orig_console_mode) ;
 
-#ifdef  __NetBSD__
-	mode = WSDISPLAYIO_MODE_MAPPED ;
-#else
+#ifdef  __OpenBSD__
 	{
 		struct wsdisplay_gfx_mode  gfx_mode ;
 
@@ -371,13 +369,12 @@ open_display(
 
 		if( ioctl( _display.fb_fd , WSDISPLAYIO_SETGFXMODE , &gfx_mode) == -1)
 		{
-			/* Always failed on OpenBSD/luna88k. */
 			kik_error_printf( "Couldn't set screen resolution (gfx mode).\n") ;
 		}
 	}
+#endif
 
 	mode = WSDISPLAYIO_MODE_DUMBFB ;
-#endif
 
 	if( ioctl( STDIN_FILENO , WSDISPLAYIO_SMODE , &mode) == -1)
 	{
