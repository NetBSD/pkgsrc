$NetBSD: patch-configure.py,v 1.7 2018/02/01 21:09:29 adam Exp $

Do not expect an app bundle on Darwin.

--- configure.py.orig	2018-01-23 10:20:28.000000000 +0000
+++ configure.py
@@ -2009,10 +2009,7 @@ def run_make(target_config, verbose, exe
         make = 'make'
         makefile_target = ''
 
-        if target_config.py_platform == 'darwin':
-            platform_exe = os.path.join(exe + '.app', 'Contents', 'MacOS', exe)
-        else:
-            platform_exe = os.path.join('.', exe)
+        platform_exe = os.path.join('.', exe)
 
     remove_file(platform_exe)
 
@@ -2568,7 +2565,7 @@ def generate_module_makefile(target_conf
 
     # Note some version of Qt5 (probably incorrectly) implements
     # 'plugin_bundle' instead of 'plugin' so we specify both.
-    pro_lines.append('CONFIG += warn_on exceptions_off %s' % ('staticlib hide_symbols' if target_config.static else 'plugin plugin_bundle'))
+    pro_lines.append('CONFIG += warn_on exceptions_off %s' % ('staticlib hide_symbols' if target_config.static else 'plugin'))
 
     pro_add_qt_dependencies(target_config, metadata, pro_lines)
 
@@ -2614,7 +2611,7 @@ win32 {
     PY_MODULE = %s.so
 
     macx {
-        PY_MODULE_SRC = $(TARGET).plugin/Contents/MacOS/$(TARGET)
+        PY_MODULE_SRC = $(TARGET)
 
         QMAKE_LFLAGS += "-undefined dynamic_lookup"
 
