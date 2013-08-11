$NetBSD: patch-xwindow_fb_x__window.c,v 1.3 2013/08/11 13:23:34 tsutsui Exp $

- pull a fix from upstream ed13793007b80c8fbd0997c4d74dc23f43dd6b36:
>> fb/x_window.c: The bug of copy_area() which disabled redrawing
>> the margin area is fixed.

--- xwindow/fb/x_window.c.orig	2013-08-05 12:48:52.000000000 +0000
+++ xwindow/fb/x_window.c
@@ -492,7 +492,7 @@ copy_area(
 	u_int  height ,
 	int  dst_x ,	/* can be minus */
 	int  dst_y ,	/* can be minus */
-	int  accept_margin	/* x/y can be minus or not */
+	int  accept_margin	/* x/y can be minus and over width/height */
 	)
 {
 	int  margin ;
@@ -503,7 +503,7 @@ copy_area(
 	u_char *  picture ;
 	size_t  src_width_size ;
 
-	if( ! win->is_mapped || dst_x >= (int)win->width || dst_y >= (int)win->height)
+	if( ! win->is_mapped)
 	{
 		return  0 ;
 	}
@@ -520,6 +520,11 @@ copy_area(
 		bottom_margin = BOTTOM_MARGIN(win) ;
 	}
 
+	if( dst_x >= (int)win->width + margin || dst_y >= (int)win->height + margin)
+	{
+		return  0 ;
+	}
+
 	if( dst_x + width > win->width + margin - right_margin)
 	{
 		width = win->width + margin - right_margin - dst_x ;
