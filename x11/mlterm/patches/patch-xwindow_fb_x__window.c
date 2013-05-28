$NetBSD: patch-xwindow_fb_x__window.c,v 1.1 2013/05/28 15:22:18 tsutsui Exp $

Pull a fix from upstream:
 https://bitbucket.org/arakiken/mlterm/commits/7c4748b4e79b9bf749685d944c174f2145074e9f#chg-xwindow/fb/x_window.c
 > fb/x_display.c: Segfault in x_font_t::x_off > 0 is fixed.

--- xwindow/fb/x_window.c.orig	2013-05-26 02:13:13.000000000 +0000
+++ xwindow/fb/x_window.c
@@ -322,7 +322,7 @@ draw_string(
 					{
 						p += (font->x_off * 4) ;
 
-						for( x_off = 0 ; x_off < font->width ; x_off++)
+						for( x_off = 0 ; x_off < glyph_width ; x_off++)
 						{
 							if( x_get_bitmap_cell( bitmap_line ,
 									x_off))
