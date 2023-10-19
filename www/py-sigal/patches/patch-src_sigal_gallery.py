$NetBSD: patch-src_sigal_gallery.py,v 1.1 2023/10/19 15:39:44 wiz Exp $

Fix bug in img_format configuration parameter.
https://github.com/saimn/sigal/issues/436

--- src/sigal/gallery.py.orig	2023-09-29 07:03:55.000000000 +0000
+++ src/sigal/gallery.py
@@ -243,6 +243,7 @@ class Image(Media):
         # Register all formats
         PILImage.init()
 
+        PILImage.registered_extensions()
         if imgformat and PILImage.EXTENSION[self.src_ext] != imgformat.upper():
             # Find the extension that should match img_format
             extensions = {v: k for k, v in PILImage.EXTENSION.items()}
