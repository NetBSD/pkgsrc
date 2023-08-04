$NetBSD: patch-pyqtbuild_builder.py,v 1.1 2023/08/04 17:10:08 adam Exp $

On Darwin, do not support application bundles.

--- pyqtbuild/builder.py.orig	2023-08-04 17:04:58.000000000 +0000
+++ pyqtbuild/builder.py
@@ -609,11 +609,7 @@ macx {
         else:
             makefile_target = None
 
-            if project.py_platform == 'darwin':
-                platform_exe = os.path.join(exe + '.app', 'Contents', 'MacOS',
-                        exe)
-            else:
-                platform_exe = os.path.join('.', exe)
+            platform_exe = os.path.join('.', exe)
 
         # Make sure the executable doesn't exist.
         self._remove_file(platform_exe)
