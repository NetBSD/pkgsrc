$NetBSD: patch-xwindow_fb_x__display__wscons.c,v 1.3 2014/06/08 16:46:25 tsutsui Exp $

Pull upstream changes:
 * fb/x_display.c, x.h: x_display_get_closest_color() caches 512 + 64 pixels.
https://bitbucket.org/arakiken/mlterm/commits/f3ea4bb79134409b0b66ba22676b9b4d1f5e1c02

--- xwindow/fb/x_display_wscons.c.orig	2014-05-25 05:42:25.000000000 +0000
+++ xwindow/fb/x_display_wscons.c
@@ -532,9 +532,6 @@ open_display(
 			}
 
 			ioctl( _display.fb_fd , FBIOPUTCMAP , _display.cmap) ;
-
-			_display.prev_pixel = 0xff000000 ;
-			_display.prev_closest_color = 0 ;
 		}
 		else if( ! cmap_init())
 		{
