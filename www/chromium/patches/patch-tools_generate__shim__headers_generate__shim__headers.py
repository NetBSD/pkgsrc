$NetBSD: patch-tools_generate__shim__headers_generate__shim__headers.py,v 1.1 2025/02/06 09:58:29 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/generate_shim_headers/generate_shim_headers.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ tools/generate_shim_headers/generate_shim_headers.py
@@ -18,7 +18,7 @@ import sys
 
 
 SHIM_TEMPLATE = """
-#if defined(OFFICIAL_BUILD)
+#if defined(GOOGLE_CHROME_BUILD)
 #error shim headers must not be used in official builds!
 #endif
 """
@@ -65,6 +65,9 @@ def GeneratorMain(argv):
       if options.outputs:
         yield os.path.join(target_directory, header_filename)
       if options.generate:
+        source_file = os.path.join(root, header_filename)
+        if os.path.exists(source_file):
+          os.unlink(source_file)
         header_path = os.path.join(target_directory, header_filename)
         header_dir = os.path.dirname(header_path)
         if not os.path.exists(header_dir):
