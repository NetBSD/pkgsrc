$NetBSD: patch-xwindow_fb_x__display.c,v 1.6 2014/06/08 16:46:25 tsutsui Exp $

Pull upstream changes:
 * fb/x_display.c, x.h: x_display_get_closest_color() caches 512 + 64 pixels.
https://bitbucket.org/arakiken/mlterm/commits/f3ea4bb79134409b0b66ba22676b9b4d1f5e1c02

--- xwindow/fb/x_display.c.orig	2014-05-25 05:42:24.000000000 +0000
+++ xwindow/fb/x_display.c
@@ -1311,6 +1311,14 @@ cmap_init(void)
 
 			return  0 ;
 		}
+
+		if( ! ( _display.color_cache = calloc( 1 , sizeof(*_display.color_cache))))
+		{
+			free( _display.cmap_orig) ;
+			free( _display.cmap) ;
+
+			return  0 ;
+		}
 	}
 
 	if( num_of_colors == 2)
@@ -1361,9 +1369,6 @@ cmap_init(void)
 	}
 #endif
 
-	_display.prev_pixel = 0xff000000 ;
-	_display.prev_closest_color = 0 ;
-
 	return  1 ;
 }
 
@@ -1383,6 +1388,7 @@ cmap_final(void)
 	}
 
 	free( _display.cmap) ;
+	free( _display.color_cache) ;
 }
 
 
@@ -1716,8 +1722,10 @@ x_display_get_group_leader(
 int
 x_display_reset_cmap(void)
 {
-	_display.prev_pixel = 0xff000000 ;
-	_display.prev_closest_color = 0 ;
+	if( _display.color_cache)
+	{
+		memset( _display.color_cache , 0 , sizeof(*_display.color_cache)) ;
+	}
 
 	return  _display.cmap && cmap_init()
 	#ifdef  USE_GRF
@@ -1814,8 +1822,10 @@ x_display_set_cmap(
 		gpal_init( ((fb_reg_t*)_display.fb)->gpal) ;
 	#endif
 
-		_display.prev_pixel = 0xff000000 ;
-		_display.prev_closest_color = 0 ;
+		if( _display.color_cache)
+		{
+			memset( _display.color_cache , 0 , sizeof(*_display.color_cache)) ;
+		}
 
 		kik_msg_printf( "Palette changed.\n") ;
 	}
@@ -2418,7 +2428,10 @@ x_cmap_get_closest_color(
 	int  blue
 	)
 {
-	u_long  pixel ;
+	u_int  segment ;
+	u_int  offset ;
+	u_int  offset_arr ;
+	int  arr_idx ;
 	u_int  color ;
 	u_long  min = 0xffffff ;
 	u_long  diff ;
@@ -2429,16 +2442,51 @@ x_cmap_get_closest_color(
 		return  0 ;
 	}
 
-	/* 0xf8f8f8 ignores least significant 3bits */
-	if( (((pixel = (red << 16) | (green << 8) | blue) ^ _display.prev_pixel)
-	     & 0xfff8f8f8) == 0)
-	{
-		*closest = _display.prev_closest_color ;
+	/* R(3)G(3)B(3) */
+	segment = ((red << 1) & 0x1c0) | ((green >> 2) & 0x38) | ((blue >> 5) & 0x7) ;
+	/* R(2)G(2)B(2) */
+	offset = ((red << 1) & 0x30) | ((green >> 1) & 0xc) | ((blue >> 3) & 0x3) ;
+
+	if( _display.color_cache->offsets[segment] == (offset|0x80))
+	{
+		*closest = _display.color_cache->pixels[segment] ;
+	#ifdef  __DEBUG
+		kik_debug_printf( "CACHED PIXEL %x <= r%x g%x b%x segment %x offset %x\n" ,
+			*closest , red , green , blue , segment , offset) ;
+	#endif
 
 		return  1 ;
 	}
 
-	_display.prev_pixel = pixel ;
+	if( offset >= 32)
+	{
+		arr_idx = 1 ;
+		offset_arr = offset - 32 ;
+	}
+	else
+	{
+		arr_idx = 0 ;
+		offset_arr = offset ;
+	}
+
+	if( _display.color_cache->seg[arr_idx].segment == segment)
+	{
+		if( _display.color_cache->seg[arr_idx].offsets & (1U << offset_arr))
+		{
+			*closest = _display.color_cache->seg_pixels[offset] ;
+		#ifdef  __DEBUG
+			kik_debug_printf( "CACHED2 PIXEL %x <= r%x g%x b%x segment %x offset %x\n" ,
+				*closest , red , green , blue , segment , offset) ;
+		#endif
+
+			return  1 ;
+		}
+	}
+	else
+	{
+		_display.color_cache->seg[arr_idx].segment = segment ;
+		_display.color_cache->seg[arr_idx].offsets = 0U ;
+	}
 
 	for( color = 0 ; color < CMAP_SIZE(_display.cmap) ; color++)
 	{
@@ -2468,7 +2516,15 @@ x_cmap_get_closest_color(
 		}
 	}
 
-	_display.prev_closest_color = *closest ;
+	_display.color_cache->seg_pixels[offset] =
+		_display.color_cache->pixels[segment] = *closest ;
+	_display.color_cache->offsets[segment] = (offset|0x80) ;
+	_display.color_cache->seg[arr_idx].offsets |= (1U << offset_arr) ;
+
+#ifdef  __DEBUG
+	kik_debug_printf( "NEW PIXEL %x <= r%x g%x b%x segment %x offset %x\n" ,
+		*closest , red , green , blue , segment , offset) ;
+#endif
 
 	return  1 ;
 }
