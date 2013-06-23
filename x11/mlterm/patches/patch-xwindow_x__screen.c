$NetBSD: patch-xwindow_x__screen.c,v 1.1 2013/06/23 06:02:39 tsutsui Exp $

Pull fix from http://mlterm.sf.net/mlterm-3.2.0-fixes.patch
> Resize the window in attaching a new pty. (enbugged at 3.2.0)
> Fix the bug which lets parcellite reset the selected region.

--- xwindow/x_screen.c.orig	2013-05-26 02:13:14.000000000 +0000
+++ xwindow/x_screen.c
@@ -3696,12 +3696,6 @@ selecting_with_motion(
 	if( ! x_is_selecting( &screen->sel))
 	{
 		restore_selected_region_color_instantly( screen) ;
-
-		if( ! x_window_set_selection_owner( &screen->window , time))
-		{
-			return ;
-		}
-
 		start_selection( screen , char_index , row , SEL_CHAR) ;
 	}
 	else
@@ -3787,12 +3781,6 @@ selecting_word(
 	if( ! x_is_selecting( &screen->sel))
 	{
 		restore_selected_region_color_instantly( screen) ;
-
-		if( ! x_window_set_selection_owner( &screen->window , time))
-		{
-			return ;
-		}
-
 		start_selection( screen , beg_char_index , beg_row , SEL_WORD) ;
 		selecting( screen , end_char_index , end_row) ;
 		x_sel_lock( &screen->sel) ;
@@ -3858,12 +3846,6 @@ selecting_line(
 	if( ! x_is_selecting( &screen->sel))
 	{
 		restore_selected_region_color_instantly( screen) ;
-
-		if( ! x_window_set_selection_owner( &screen->window , time))
-		{
-			return ;
-		}
-
 		start_selection( screen , beg_char_index , beg_row , SEL_LINE) ;
 		selecting( screen , end_char_index , end_row) ;
 		x_sel_lock( &screen->sel) ;
@@ -4518,7 +4500,7 @@ change_font_present(
 	font_size_changed( screen) ;
 }
 
-static void
+static int
 usascii_font_cs_changed(
 	x_screen_t *  screen ,
 	ml_char_encoding_t  encoding
@@ -4548,6 +4530,12 @@ usascii_font_cs_changed(
 		 * x_font_manager_usascii_font_cs_changed()
 		 */
 		x_xic_font_set_changed( &screen->window) ;
+
+		return  1 ;
+	}
+	else
+	{
+		return  0 ;
 	}
 }
 
@@ -6188,7 +6176,16 @@ select_in_window(
 	}
 #endif
 
-	return  1 ;
+	if( ! x_window_set_selection_owner( &screen->window , CurrentTime))
+	{
+		ml_str_delete( *chars , size) ;
+
+		return  0 ;
+	}
+	else
+	{
+		return  1 ;
+	}
 }
 
 
@@ -7923,12 +7920,10 @@ x_screen_attach(
 		return  1 ;
 	}
 
-	/* XXX */
-#ifdef  USE_FRAMEBUFFER
-	window_resized( &screen->window) ;
-#endif
-
-	usascii_font_cs_changed( screen , ml_term_get_encoding( screen->term)) ;
+	if( ! usascii_font_cs_changed( screen , ml_term_get_encoding( screen->term)))
+	{
+		resize_window( screen) ;
+	}
 
 	update_special_visual( screen) ;
 	/* Even if update_special_visual succeeded or not, all screen should be redrawn. */
