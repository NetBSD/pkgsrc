$NetBSD: patch-xwindow_fb_x__display__linux.c,v 1.1 2014/06/08 16:46:25 tsutsui Exp $

Pull upstream changes:
 * fb/x_display.c, x.h: x_display_get_closest_color() caches 512 + 64 pixels.
https://bitbucket.org/arakiken/mlterm/commits/f3ea4bb79134409b0b66ba22676b9b4d1f5e1c02

--- xwindow/fb/x_display_linux.c.orig	2014-05-25 05:42:25.000000000 +0000
+++ xwindow/fb/x_display_linux.c
@@ -295,6 +295,8 @@ open_display(
 	if( _display.pixels_per_byte > 1 &&
 	    ! ( _display.back_fb = malloc( _display.smem_len)))
 	{
+		cmap_final() ;
+
 		goto  error ;
 	}
 #endif
