$NetBSD: patch-xwindow_fb_x__display__wscons.c,v 1.6 2015/03/21 20:41:37 tsutsui Exp $

Pull upstream fix for NetBSD which also affects RPI2:
https://bitbucket.org/arakiken/mlterm/commits/d2f31b50c2b90bf731ae2223a975d9bb6320478f
> x_display_wscons.c: WSDISPLAYIO_GET_FBINFO is supported.

--- xwindow/fb/x_display_wscons.c.orig	2015-03-14 04:47:23.000000000 +0000
+++ xwindow/fb/x_display_wscons.c
@@ -336,6 +336,9 @@ open_display(
 {
 	char *  dev ;
 	struct wsdisplay_fbinfo  vinfo ;
+#ifdef  WSDISPLAYIO_GET_FBINFO
+	struct wsdisplayio_fbinfo  vinfo2 ;
+#endif
 	int  mode ;
 	int  wstype ;
 	struct rgb_info  rgbinfos[] =
@@ -392,19 +395,45 @@ open_display(
 		goto  error ;
 	}
 
-	if( ioctl( _display.fb_fd , WSDISPLAYIO_GINFO , &vinfo) == -1 ||
-	    ioctl( _display.fb_fd , WSDISPLAYIO_GTYPE , &wstype) == -1)
+	if( ioctl( _display.fb_fd , WSDISPLAYIO_GTYPE , &wstype) == -1)
 	{
 	#ifdef  DEBUG
 		kik_debug_printf( KIK_DEBUG_TAG
-			" WSDISPLAYIO_GINFO or WSDISPLAYIO_GTYPE failed.\n") ;
+			" WSDISPLAYIO_GTYPE failed.\n") ;
+	#endif
+
+		goto  error ;
+	}
+
+#ifdef  WSDISPLAYIO_GET_FBINFO
+	vinfo2.fbi_stride = 0 ;
+	if( ioctl( _display.fb_fd , WSDISPLAYIO_GET_FBINFO , &vinfo2) == 0)
+	{
+		vinfo.width = vinfo2.fbi_width ;
+		vinfo.height = vinfo2.fbi_height ;
+		vinfo.depth = vinfo2.fbi_bitsperpixel ;
+		vinfo.cmsize = vinfo2.fbi_subtype.fbi_cmapinfo.cmap_entries ;
+
+		/* XXX fbi_fboffset is regarded as multiple of fbi_stride */
+		_display.yoffset = vinfo2.fbi_fboffset / vinfo2.fbi_stride ;
+	}
+	else
+#endif
+	if( ioctl( _display.fb_fd , WSDISPLAYIO_GINFO , &vinfo) == 0)
+	{
+		_display.yoffset = 0 ;
+	}
+	else
+	{
+	#ifdef  DEBUG
+		kik_debug_printf( KIK_DEBUG_TAG
+			" WSDISPLAYIO_GTYPE and WSDISPLAYIO_GET_FBINFO failed.\n") ;
 	#endif
 
 		goto  error ;
 	}
 
 	_display.xoffset = 0 ;
-	_display.yoffset = 0 ;
 
 	_display.width = _disp.width = vinfo.width ;
 	_display.height = _disp.height = vinfo.height ;
@@ -453,6 +482,13 @@ open_display(
 		_display.bytes_per_pixel = 4 ;
 	}
 
+#ifdef  WSDISPLAYIO_GET_FBINFO
+	if( vinfo2.fbi_stride > 0)
+	{
+		_display.line_length = vinfo2.fbi_stride ;
+	}
+	else
+#endif
 	if( ioctl( _display.fb_fd , WSDISPLAYIO_LINEBYTES , &_display.line_length) == -1)
 	{
 		/* WSDISPLAYIO_LINEBYTES isn't defined in some ports. */
@@ -554,6 +590,24 @@ open_display(
 			goto  error ;
 		}
 	}
+#ifdef  WSDISPLAYIO_GET_FBINFO
+	else if( vinfo2.fbi_stride > 0)
+	{
+		_display.rgbinfo.r_limit = 8 - vinfo2.fbi_subtype.fbi_rgbmasks.red_size ;
+		_display.rgbinfo.g_limit = 8 - vinfo2.fbi_subtype.fbi_rgbmasks.green_size ;
+		_display.rgbinfo.b_limit = 8 - vinfo2.fbi_subtype.fbi_rgbmasks.blue_size ;
+		_display.rgbinfo.r_offset = vinfo2.fbi_subtype.fbi_rgbmasks.red_offset ;
+		_display.rgbinfo.g_offset = vinfo2.fbi_subtype.fbi_rgbmasks.green_offset ;
+		_display.rgbinfo.b_offset = vinfo2.fbi_subtype.fbi_rgbmasks.blue_offset ;
+
+	#ifdef  DEBUG
+		kik_debug_printf( "FBINFO: (limit)r%d g%d b%d (offset)r%d g%d b%d\n" ,
+			_display.rgbinfo.r_limit , _display.rgbinfo.g_limit ,
+			_display.rgbinfo.b_limit , _display.rgbinfo.r_offset ,
+			_display.rgbinfo.g_offset , _display.rgbinfo.b_offset) ;
+	#endif
+	}
+#endif
 	else
 	{
 		if( _disp.depth == 15)
@@ -569,7 +623,14 @@ open_display(
 			_display.rgbinfo = rgbinfos[2] ;
 		}
 
-		if( wstype == WSDISPLAY_TYPE_SUNFFB
+		if( wstype == WSDISPLAY_TYPE_SUN24 ||
+		    wstype == WSDISPLAY_TYPE_SUNCG12 ||
+		    wstype == WSDISPLAY_TYPE_SUNCG14 ||
+		    wstype == WSDISPLAY_TYPE_SUNTCX ||
+		    wstype == WSDISPLAY_TYPE_SUNFFB
+		#ifdef  WSDISPLAY_TYPE_XVR1000
+		    || wstype == WSDISPLAY_TYPE_XVR1000
+		#endif
 		#ifdef  WSDISPLAY_TYPE_VC4
 		    || wstype == WSDISPLAY_TYPE_VC4
 		#endif
