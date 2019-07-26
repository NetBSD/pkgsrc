$ NetBSD $

- Fix support for fbi_fboffset != 0
- Fix SEGV when using 8-bpp display on LP64 machine

Reported upstream:
https://bitbucket.org/arakiken/mlterm/pull-requests/5/fix-for-wscons-framebuffer/diff

--- uitoolkit/fb/ui_display_wscons.c.orig	2019-03-31 22:10:47.000000000 +0900
+++ uitoolkit/fb/ui_display_wscons.c	2019-07-26 21:54:53.421920873 +0900
@@ -260,6 +260,7 @@ static int open_display(u_int depth /* u
 #ifdef WSDISPLAYIO_GET_FBINFO
   struct wsdisplayio_fbinfo vinfo2;
 #endif
+  int fboffset;
   int mode;
   int wstype;
   struct rgb_info rgbinfos[] = {
@@ -326,12 +327,18 @@ static int open_display(u_int depth /* u
     vinfo.depth = vinfo2.fbi_bitsperpixel;
     vinfo.cmsize = vinfo2.fbi_subtype.fbi_cmapinfo.cmap_entries;
 
-    /* XXX fbi_fboffset is regarded as multiple of fbi_stride */
-    _display.yoffset = vinfo2.fbi_fboffset / vinfo2.fbi_stride;
+    fboffset = vinfo2.fbi_fboffset;
   } else
 #endif
-      if (ioctl(_display.fb_fd, WSDISPLAYIO_GINFO, &vinfo) == 0) {
-    _display.yoffset = 0;
+  if (ioctl(_display.fb_fd, WSDISPLAYIO_GINFO, &vinfo) == 0) {
+#ifdef WSDISPLAY_TYPE_LUNA
+    if (wstype == WSDISPLAY_TYPE_LUNA) {
+      fboffset = 8;
+    } else
+#endif
+    {
+      fboffset = 0;
+    }
   } else {
 #ifdef DEBUG
     bl_debug_printf(BL_DEBUG_TAG " WSDISPLAYIO_GTYPE and WSDISPLAYIO_GET_FBINFO failed.\n");
@@ -341,6 +348,7 @@ static int open_display(u_int depth /* u
   }
 
   _display.xoffset = 0;
+  _display.yoffset = 0;
 
   _display.width = _disp.width = vinfo.width;
   _display.height = _disp.height = vinfo.height;
@@ -403,7 +411,7 @@ static int open_display(u_int depth /* u
   if (wstype == WSDISPLAY_TYPE_LUNA && (_disp.depth == 4 || _disp.depth == 8)) {
     u_int plane;
 
-    _display.smem_len = 0x40000 * _disp.depth;
+    _display.smem_len = (fboffset + 0x40000) * _disp.depth;
 
     for (plane = 0; plane < _disp.depth; plane++) {
       _display.plane_offset[plane] = 0x40000 * plane;
@@ -411,7 +419,7 @@ static int open_display(u_int depth /* u
   } else
 #endif
   {
-    _display.smem_len = _display.line_length * _display.height;
+    _display.smem_len = fboffset + _display.line_length * _display.height;
   }
 
   if ((_display.fb = mmap(NULL, _display.smem_len, PROT_WRITE | PROT_READ, MAP_SHARED,
@@ -421,11 +429,7 @@ static int open_display(u_int depth /* u
     goto error;
   }
 
-#ifdef WSDISPLAY_TYPE_LUNA
-  if (wstype == WSDISPLAY_TYPE_LUNA) {
-    _display.fb += 8;
-  }
-#endif
+  _display.fb_base = _display.fb + fboffset;
 
   if (_disp.depth < 15) {
     if (vinfo.depth >= 2 && _disp.depth == 1) {
@@ -630,7 +634,7 @@ static int open_display(u_int depth /* u
 error:
   if (_display.fb) {
     munmap(_display.fb, _display.smem_len);
-    _display.fb = NULL;
+    _display.fb = _display.fb_base = NULL;
   }
 
   close(_display.fb_fd);
