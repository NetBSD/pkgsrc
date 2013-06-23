$NetBSD: patch-xwindow_fb_x__display.c,v 1.1 2013/06/23 06:02:39 tsutsui Exp $

Pull fix from http://mlterm.sf.net/mlterm-3.2.0-fixes.patch
> Fix the bug which caused segmentation fault in closing input method
> status window.

--- xwindow/fb/x_display.c.orig	2013-05-26 02:13:13.000000000 +0000
+++ xwindow/fb/x_display.c
@@ -849,19 +849,17 @@ receive_event_for_multi_roots(
 
 	x_window_receive_event( _disp.roots[0] , xev) ;
 
-	if( redraw_im_win)
+	if( redraw_im_win && _disp.num_of_roots == 2)
 	{
 		/* Restart drawing input method window */
 		_disp.roots[1]->is_mapped = 1 ;
 	}
 
-	if( ! check_visibility_of_im_window())
+	if( check_visibility_of_im_window())
 	{
-		return ;
+		expose_window( _disp.roots[1] , _disp.roots[1]->x , _disp.roots[1]->y ,
+				ACTUAL_WIDTH(_disp.roots[1]) , ACTUAL_HEIGHT(_disp.roots[1])) ;
 	}
-
-	expose_window( _disp.roots[1] , _disp.roots[1]->x , _disp.roots[1]->y ,
-			ACTUAL_WIDTH(_disp.roots[1]) , ACTUAL_HEIGHT(_disp.roots[1])) ;
 }
 
 #ifndef  __FreeBSD__
