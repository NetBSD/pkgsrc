$NetBSD: patch-xwindow_fb_x__display.c,v 1.4 2013/12/25 16:32:31 tsutsui Exp $

Pull post-3.3.2 fixes:
 - 4d974f7: fix mlterm-fb scroll on >=8bpp framebuffers
 - 0b2987a: fix palette handling on 4bpp framebuffers

--- xwindow/fb/x_display.c.orig	2013-12-21 17:11:35.000000000 +0000
+++ xwindow/fb/x_display.c
@@ -1180,6 +1180,7 @@ cmap_init(void)
 		_display.cmap->blue[color] = BYTE_COLOR_TO_WORD(b) ;
 	}
 
+	/* Same processing as x_display_set_cmap(). */
 #ifndef  USE_GRF
 	ioctl( _display.fb_fd , FBIOPUTCMAP , _display.cmap) ;
 #else
@@ -1553,12 +1554,45 @@ x_display_set_use_ansi_colors(
 }
 
 void
+x_display_enable_to_change_cmap(
+	int  flag
+	)
+{
+	if( flag)
+	{
+	#ifdef  USE_GRF
+		x68k_set_use_tvram_colors( 1) ;
+	#endif
+
+		if( ! use_ansi_colors)
+		{
+			use_ansi_colors = -1 ;
+		}
+	}
+	else
+	{
+	#ifdef  USE_GRF
+		x68k_set_use_tvram_colors( 0) ;
+	#endif
+
+		if( use_ansi_colors == -1)
+		{
+			use_ansi_colors = 0 ;
+		}
+	}
+}
+
+void
 x_display_set_cmap(
 	u_int32_t *  pixels ,
 	u_int  cmap_size
 	)
 {
-	if( ! use_ansi_colors && cmap_size <= 16 && _disp.depth == 4)
+	if(
+	#ifdef  USE_GRF
+	    ! x68k_set_tvram_cmap( pixels , cmap_size) &&
+	#endif
+	    use_ansi_colors == -1 && cmap_size <= 16 && _disp.depth == 4)
 	{
 		u_int  count ;
 		ml_color_t  color ;
@@ -1584,7 +1618,18 @@ x_display_set_cmap(
 			_display.cmap->blue[color] = pixels[count] & 0xff ;
 		}
 
+		/* Same processing as cmap_init(). */
+	#ifndef  USE_GRF
 		ioctl( _display.fb_fd , FBIOPUTCMAP , _display.cmap) ;
+	#else
+		for( count = 0 ; count < CMAP_SIZE(_display.cmap) ; count++)
+		{
+			((fb_reg_t*)_display.fb)->gpal[count] =
+				(_display.cmap->red[count] >> 3) << 6 |
+				(_display.cmap->green[count] >> 3) << 11 |
+				(_display.cmap->blue[count] >> 3) << 1 ;
+		}
+	#endif
 	}
 }
 
@@ -1829,12 +1874,14 @@ x_display_fill_with(
 				fb_end += _display.line_length ;
 			}
 
+		#ifndef  ENABLE_2_4_PPB
 			if( ++plane < _disp.depth)
 			{
 				fb = fb_orig + _display.plane_len * plane ;
 				fb_end = fb + (buf_end - buf) ;
 			}
 			else
+		#endif
 			{
 				break ;
 			}
@@ -1870,6 +1917,7 @@ x_display_copy_lines(
 	u_char *  dst ;
 	u_int  copy_len ;
 	u_int  count ;
+	int  num_of_planes ;
 	int  plane ;
 
 	/* XXX cheap implementation. */
@@ -1878,7 +1926,16 @@ x_display_copy_lines(
 	/* XXX could be different from FB_WIDTH_BYTES(display, dst_x, width) */
 	copy_len = FB_WIDTH_BYTES(&_display, src_x, width) ;
 
-	for( plane = 0 ; plane < _disp.depth ; plane++)
+	if( _display.pixels_per_byte == 8)
+	{
+		num_of_planes = _disp.depth ;
+	}
+	else
+	{
+		num_of_planes = 1 ;
+	}
+
+	for( plane = 0 ; plane < num_of_planes ; plane++)
 	{
 		if( src_y <= dst_y)
 		{
