$NetBSD: patch-xwindow_fb_x.h,v 1.1 2014/06/08 16:46:25 tsutsui Exp $

Pull upstream changes:
 * fb/x_display.c, x.h: x_display_get_closest_color() caches 512 + 64 pixels.
https://bitbucket.org/arakiken/mlterm/commits/f3ea4bb79134409b0b66ba22676b9b4d1f5e1c02

--- xwindow/fb/x.h.orig	2014-05-25 05:42:24.000000000 +0000
+++ xwindow/fb/x.h
@@ -72,8 +72,28 @@ typedef struct
 	fb_cmap_t *  cmap ;
 	fb_cmap_t *  cmap_orig ;
 
-	u_long  prev_pixel ;
-	u_long  prev_closest_color ;
+	struct
+	{
+		/*
+		 * Closest color is searched by 15 bits.
+		 *   R(3)G(3)B(3): segment(9bits)
+		 *   R(2)G(2)B(2): offset(6bits)
+		 */
+
+		/* Closest pixels cached by every segment. */
+		u_int8_t  pixels[512] ;		/* 2^9 */
+		u_int8_t  offsets[512] ;	/* 2^9 */
+
+		/* Closest pixels cached in recent segment. */
+		u_int8_t  seg_pixels[64] ;
+		struct
+		{
+			u_int32_t  offsets ;
+			u_int  segment ;
+
+		} seg[2] ;
+
+	} *  color_cache ;
 
 	int  key_state ;
 	int  lock_state ;
