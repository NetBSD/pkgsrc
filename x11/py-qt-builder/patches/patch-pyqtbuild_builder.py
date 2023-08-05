$NetBSD: patch-pyqtbuild_builder.py,v 1.2 2023/08/05 06:16:27 adam Exp $

On Darwin, do not support application bundles.

--- pyqtbuild/builder.py.orig	2023-07-21 13:05:11.000000000 +0000
+++ pyqtbuild/builder.py
@@ -379,7 +379,7 @@ class QmakeBuilder(Builder):
         else:
             # Note some version of Qt5 (probably incorrectly) implements
             # 'plugin_bundle' instead of 'plugin' so we specify both.
-            pro_lines.append('CONFIG += plugin plugin_bundle no_default_rpath')
+            pro_lines.append('CONFIG += plugin no_default_rpath')
 
         if project.qml_debug:
             pro_lines.append('CONFIG += qml_debug')
@@ -419,7 +419,7 @@ win32 {
     PY_MODULE_SRC = $(DESTDIR_TARGET)
 } else {
     macx {
-        PY_MODULE_SRC = $(TARGET).plugin/Contents/MacOS/$(TARGET)
+        PY_MODULE_SRC = $(TARGET)
         QMAKE_LFLAGS += "-undefined dynamic_lookup"
     } else {
         PY_MODULE_SRC = $(TARGET)
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
