$NetBSD: patch-xwindow_x__screen.c,v 1.3 2013/12/14 16:30:18 tsutsui Exp $

Pull fix from upstream 4ccecc4cbc90ed69054f0e94179bdccb6fda5868:
 * x_screen.c: The limitation of the column width and the line height (< 32)
   is removed.

--- xwindow/x_screen.c.orig	2013-11-22 15:31:39.000000000 +0000
+++ xwindow/x_screen.c
@@ -7244,15 +7244,13 @@ xterm_get_picture_data(
 
 	screen = p ;
 
-	if( ml_term_get_vertical_mode( screen->term) ||
-	    ( col_width = x_col_width(screen)) >= 32 ||
-	    ( line_height = x_line_height(screen)) >= 32)
+	if( ml_term_get_vertical_mode( screen->term))
 	{
 		return  NULL ;
 	}
 
-	width = (*num_of_cols) * col_width ;
-	height = (*num_of_rows) * line_height ;
+	width = (*num_of_cols) * (col_width = x_col_width(screen)) ;
+	height = (*num_of_rows) * (line_height = x_line_height(screen)) ;
 
 	if( ( idx = x_load_inline_picture( screen->window.disp , file_path ,
 			&width , &height , col_width , line_height , screen->term)) != -1)
