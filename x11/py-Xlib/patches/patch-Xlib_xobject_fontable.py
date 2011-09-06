$NetBSD: patch-Xlib_xobject_fontable.py,v 1.2 2011/09/06 20:45:05 wiz Exp $

Python-3.1 compatibility.
https://sourceforge.net/tracker/?func=detail&aid=3405244&group_id=10350&atid=310350

--- Xlib/xobject/fontable.py.orig	2007-06-10 14:11:59.000000000 +0000
+++ Xlib/xobject/fontable.py
@@ -87,8 +87,9 @@ class Font(Fontable):
         self.display.free_resource_id(self.id)
 
     def create_glyph_cursor(self, mask, source_char, mask_char,
-                            (fore_red, fore_green, fore_blue),
-                            (back_red, back_green, back_blue)):
+                            f_rgb, b_rgb):
+        fore_red, fore_green, fore_blue = f_rgb
+        back_red, back_green, back_blue = b_rgb
 
         cid = self.display.allocate_resource_id()
         request.CreateGlyphCursor(display = self.display,
