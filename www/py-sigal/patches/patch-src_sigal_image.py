$NetBSD: patch-src_sigal_image.py,v 1.1 2023/10/19 15:39:44 wiz Exp $

Add HEIF support using pillow_heif, if it's installed.
https://github.com/saimn/sigal/issues/436

--- src/sigal/image.py.orig	2023-09-29 07:03:55.000000000 +0000
+++ src/sigal/image.py
@@ -49,6 +49,11 @@ from . import signals, utils
 # Force loading of truncated files
 ImageFile.LOAD_TRUNCATED_IMAGES = True
 
+try:
+    from pillow_heif import HeifImagePlugin
+except ImportError:
+    HeifImagePlugin = None
+
 
 def _has_exif_tags(img):
     return hasattr(img, "info") and "exif" in img.info
