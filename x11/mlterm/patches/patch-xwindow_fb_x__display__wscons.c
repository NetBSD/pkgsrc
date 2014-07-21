$NetBSD: patch-xwindow_fb_x__display__wscons.c,v 1.4 2014/07/21 15:42:56 tsutsui Exp $

- pull post 3.3.7 fixes:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.7/mlterm-3.3.7-fixes.patch/download
 * x_display_wscons.c: The null pointer bug of_display.color_cache in the case
   of vinfo.depth >= 2 && _disp.depth == 1 is fixed.

--- xwindow/fb/x_display_wscons.c.orig	2014-07-05 21:40:42.000000000 +0000
+++ xwindow/fb/x_display_wscons.c
@@ -522,6 +522,15 @@ open_display(
 
 					goto  error ;
 				}
+
+				if( ! ( _display.color_cache =
+						calloc( 1 , sizeof(*_display.color_cache))))
+				{
+					free( _display.cmap_orig) ;
+					free( _display.cmap) ;
+
+					goto  error ;
+				}
 			}
 
 			for( color = 0 ; color < num_of_colors ; color ++)
