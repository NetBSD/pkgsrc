$NetBSD: patch-Xlib_xobject_drawable.py,v 1.2 2011/09/06 20:45:05 wiz Exp $

Python-3.1 compatibility.
https://sourceforge.net/tracker/?func=detail&aid=3405244&group_id=10350&atid=310350

--- Xlib/xobject/drawable.py.orig	2007-06-10 14:11:59.000000000 +0000
+++ Xlib/xobject/drawable.py
@@ -233,7 +233,7 @@ class Drawable(resource.Resource):
             unit = self.display.info.bitmap_format_scanline_unit
             stride = roundup(width * unit, pad) >> 3
         else:
-            raise ValueError, 'Unknown data format'
+            raise ValueError('Unknown data format')
 
         maxlen = (self.display.info.max_request_length << 2) \
                  - request.PutImage._request.static_size
@@ -800,9 +800,10 @@ class Pixmap(Drawable):
         self.display.free_resource_id(self.id)
 
     def create_cursor(self, mask,
-                      (fore_red, fore_green, fore_blue),
-                      (back_red, back_green, back_blue),
+                      f_rgb, b_rgb,
                       x, y):
+        fore_red, fore_green, fore_blue = f_rgb
+        back_red, back_green, back_blue = b_rgb
         cid = self.display.allocate_resource_id()
         request.CreateCursor(display = self.display,
                              cid = cid,
