$NetBSD: patch-xwindow_x__draw__str.c,v 1.1 2014/05/02 05:09:29 tsutsui Exp $

Pull post-3.3.5 bug fix patch:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.5/mlterm-3.3.5-fixes.patch/download
 - Fix partially corrupt screen in drawing animation gif.

--- xwindow/fb/x_display_wscons.c.orig	2014-04-25 23:40:19.000000000 +0000
--- xwindow/x_draw_str.c.orig	2014-04-25 23:40:19.000000000 +0000
+++ xwindow/x_draw_str.c
@@ -129,7 +129,7 @@ draw_picture(
 			}
 		}
 
-		if( need_clear)
+		if( need_clear > 0)
 		{
 			x_window_clear( window , dst_x , dst_y , dst_width , line_height) ;
 		}
@@ -175,7 +175,7 @@ draw_picture(
 		if( strstr( cur_pic->file_path , "mlterm/animx") && cur_pic->next_frame >= 0)
 		{
 			/* Don't clear if cur_pic is 2nd or later GIF Animation frame. */
-			need_clear = 0 ;
+			need_clear = -1 ;
 		}
 
 		if( (src_width = w) < ch_width && ! need_clear)
