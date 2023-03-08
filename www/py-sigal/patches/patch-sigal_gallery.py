$NetBSD: patch-sigal_gallery.py,v 1.1 2023/03/08 21:05:58 wiz Exp $

Fix bug in img_format configuration parameter.
https://github.com/saimn/sigal/issues/436

--- sigal/gallery.py.orig	2022-04-08 18:19:56.000000000 +0000
+++ sigal/gallery.py
@@ -235,6 +235,7 @@ class Image(Media):
         super().__init__(filename, path, settings)
         imgformat = settings.get('img_format')
 
+        PILImage.registered_extensions()
         if imgformat and PILImage.EXTENSION[self.src_ext] != imgformat.upper():
             # Find the extension that should match img_format
             extensions = {v: k for k, v in PILImage.EXTENSION.items()}
