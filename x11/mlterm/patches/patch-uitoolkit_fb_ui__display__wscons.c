$NetBSD: patch-uitoolkit_fb_ui__display__wscons.c,v 1.6 2022/07/09 09:40:20 rin Exp $

Add support for 8- and 4-bpp planar fb found on NetBSD/amiga.

Requires amidisplaycc(4) driver from NetBSD-current. With older
drivers, automatically falls back to monochrome mode.

XXX
Only tested for 8-bpp mode. As 4-bpp mode requires ancient
analogue monitors.

XXX
Logic to detect planar fb is not very elegant...

This has been merged to upstream, and will be in the next release.

--- uitoolkit/fb/ui_display_wscons.c.orig	2022-01-17 00:20:31.000000000 +0900
+++ uitoolkit/fb/ui_display_wscons.c	2022-07-07 05:22:09.475716704 +0900
@@ -380,8 +380,17 @@ static int open_display(u_int depth /* u
   _display.height = _disp.height = vinfo.height;
   _disp.depth = vinfo.depth;
 
-#ifdef WSDISPLAY_TYPE_LUNA
-  if (wstype == WSDISPLAY_TYPE_LUNA) {
+#if defined(WSDISPLAY_TYPE_LUNA) && defined(WSDISPLAY_TYPE_AMIGACC)
+#define	WSTYPE_PLANAR(wstype)	\
+  ((wstype) == WSDISPLAY_TYPE_LUNA || (wstype) == WSDISPLAY_TYPE_AMIGACC)
+#elif defined(WSDISPLAY_TYPE_LUNA)
+#define	WSTYPE_PLANAR(wstype)	((wstype) == WSDISPLAY_TYPE_LUNA)
+#elif defined(WSDISPLAY_TYPE_AMIGACC)
+#define	WSTYPE_PLANAR(wstype)	((wstype) == WSDISPLAY_TYPE_AMIGACC)
+#endif
+
+#ifdef WSTYPE_PLANAR
+  if (WSTYPE_PLANAR(wstype)) {
     /* always 8 or less bpp */
 
     if (_disp.depth > 8) {
@@ -394,7 +403,7 @@ static int open_display(u_int depth /* u
     _display.shift_0 = 7;
     _display.mask = 1;
   } else
-#endif
+#endif
       if (_disp.depth < 8) {
 #ifdef ENABLE_2_4_PPB
     _display.pixels_per_byte = 8 / _disp.depth;
@@ -444,6 +453,19 @@ static int open_display(u_int depth /* u
     }
   } else
 #endif
+#ifdef WSDISPLAY_TYPE_AMIGACC
+  if (wstype == WSDISPLAY_TYPE_AMIGACC &&
+      (_disp.depth == 4 || _disp.depth == 8)) {
+    u_int len_per_plane, plane;
+
+    len_per_plane = _display.line_length * _display.height;
+    _display.smem_len = fboffset + len_per_plane * _disp.depth;
+
+    for (plane = 0; plane < _disp.depth; plane++) {
+      _display.plane_offset[plane] = len_per_plane * plane;
+    }
+  } else
+#endif
   {
     _display.smem_len = fboffset + _display.line_length * _display.height;
   }
