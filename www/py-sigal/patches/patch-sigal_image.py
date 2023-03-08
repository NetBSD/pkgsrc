$NetBSD: patch-sigal_image.py,v 1.1 2023/03/08 21:05:58 wiz Exp $

Add HEIF support using pillow_heif, if it's installed.
https://github.com/saimn/sigal/issues/436

--- sigal/image.py.orig	2022-04-08 18:19:56.000000000 +0000
+++ sigal/image.py
@@ -56,6 +56,11 @@ except ImportError:
 # Force loading of truncated files
 ImageFile.LOAD_TRUNCATED_IMAGES = True
 
+try:
+    from pillow_heif import HeifImagePlugin
+except ImportError:
+    HeifImagePlugin = None
+
 
 def _has_exif_tags(img):
     return hasattr(img, 'info') and 'exif' in img.info
