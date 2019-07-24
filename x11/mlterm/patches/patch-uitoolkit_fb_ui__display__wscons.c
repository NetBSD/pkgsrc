$ NetBSD $

- Fix support for fbi_fboffset != 0
- Fix SEGV when using 8-bpp display on LP64 machine
- Add better handling for 24-bpp display

Reported upstream:
https://bitbucket.org/arakiken/mlterm/pull-requests/5/fix-for-wscons-framebuffer/diff

--- uitoolkit/fb/ui_display_wscons.c	2019-07-24 10:51:04.210666890 +0900
+++ ../mlterm.patched/uitoolkit/fb/ui_display_wscons.c	2019-07-24 10:31:06.733563761 +0900
@@ -260,6 +260,7 @@ static int open_display(u_int depth /* u
 #ifdef WSDISPLAYIO_GET_FBINFO
   struct wsdisplayio_fbinfo vinfo2;
 #endif
+  int fboffset;
   int mode;
   int wstype;
   struct rgb_info rgbinfos[] = {
@@ -323,15 +324,26 @@ static int open_display(u_int depth /* u
   if (ioctl(_display.fb_fd, WSDISPLAYIO_GET_FBINFO, &vinfo2) == 0) {
     vinfo.width = vinfo2.fbi_width;
     vinfo.height = vinfo2.fbi_height;
-    vinfo.depth = vinfo2.fbi_bitsperpixel;
+    if (vinfo2.fbi_bitsperpixel == 32 &&
+        vinfo2.fbi_subtype.fbi_rgbmasks.alpha_size == 0) {
+      vinfo.depth = 24;
+    } else {
+      vinfo.depth = vinfo2.fbi_bitsperpixel;
+    }
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
@@ -341,6 +353,7 @@ static int open_display(u_int depth /* u
   }
 
   _display.xoffset = 0;
+  _display.yoffset = 0;
 
   _display.width = _disp.width = vinfo.width;
   _display.height = _disp.height = vinfo.height;
@@ -403,7 +416,7 @@ static int open_display(u_int depth /* u
   if (wstype == WSDISPLAY_TYPE_LUNA && (_disp.depth == 4 || _disp.depth == 8)) {
     u_int plane;
 
-    _display.smem_len = 0x40000 * _disp.depth;
+    _display.smem_len = (fboffset + 0x40000) * _disp.depth;
 
     for (plane = 0; plane < _disp.depth; plane++) {
       _display.plane_offset[plane] = 0x40000 * plane;
@@ -411,7 +424,7 @@ static int open_display(u_int depth /* u
   } else
 #endif
   {
-    _display.smem_len = _display.line_length * _display.height;
+    _display.smem_len = fboffset + _display.line_length * _display.height;
   }
 
   if ((_display.fb = mmap(NULL, _display.smem_len, PROT_WRITE | PROT_READ, MAP_SHARED,
@@ -421,11 +434,7 @@ static int open_display(u_int depth /* u
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
@@ -630,7 +639,7 @@ static int open_display(u_int depth /* u
 error:
   if (_display.fb) {
     munmap(_display.fb, _display.smem_len);
-    _display.fb = NULL;
+    _display.fb = _display.fb_base = NULL;
   }
 
   close(_display.fb_fd);
