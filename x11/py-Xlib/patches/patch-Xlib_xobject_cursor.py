$NetBSD: patch-Xlib_xobject_cursor.py,v 1.2 2011/09/06 20:45:05 wiz Exp $

Python-3.1 compatibility.
https://sourceforge.net/tracker/?func=detail&aid=3405244&group_id=10350&atid=310350

--- Xlib/xobject/cursor.py.orig	2007-06-10 14:11:59.000000000 +0000
+++ Xlib/xobject/cursor.py
@@ -31,9 +31,9 @@ class Cursor(resource.Resource):
                            cursor = self.id)
         self.display.free_resource_id(self.id)
 
-    def recolor(self, (fore_red, fore_green, fore_blue),
-                (back_red, back_green, back_blue), onerror = None):
-
+    def recolor(self, f_rgb, b_rgb, onerror = None):
+        back_red, back_green, back_blue = b_rgb
+        fore_red, fore_green, fore_blue = f_rgb
         request.RecolorCursor(display = self.display,
                               onerror = onerror,
                               cursor = self.id,
