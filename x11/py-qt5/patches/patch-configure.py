$NetBSD: patch-configure.py,v 1.10 2023/08/04 22:30:09 adam Exp $

Do not expect an app bundle on Darwin.

--- configure.py.orig	2022-06-18 17:04:05.000000000 +0000
+++ configure.py
@@ -442,7 +442,7 @@ class HostPythonConfiguration:
             self.lib_dir = sys.prefix + '/lib'
 
         # The name of the interpreter used by the pyuic5 wrapper.
-        if sys.platform == 'darwin':
+        if False:
             # The installation of MacOS's python is a mess that changes from
             # version to version and where sys.executable is useless.
 
@@ -2136,7 +2136,7 @@ def run_make(target_config, verbose, exe
         make = 'make'
         makefile_target = ''
 
-        if target_config.py_platform == 'darwin':
+        if False:
             platform_exe = os.path.join(exe + '.app', 'Contents', 'MacOS', exe)
         else:
             platform_exe = os.path.join('.', exe)
@@ -2701,7 +2701,7 @@ def generate_module_makefile(target_conf
 
     # Note some version of Qt5 (probably incorrectly) implements
     # 'plugin_bundle' instead of 'plugin' so we specify both.
-    pro_lines.append('CONFIG += warn_on exceptions_off %s' % ('staticlib hide_symbols' if target_config.static else 'plugin plugin_bundle'))
+    pro_lines.append('CONFIG += warn_on exceptions_off %s' % ('staticlib hide_symbols' if target_config.static else 'plugin'))
 
     pro_add_qt_dependencies(target_config, metadata, pro_lines)
 
@@ -2747,7 +2747,7 @@ win32 {
     PY_MODULE = %s.so
 
     macx {
-        PY_MODULE_SRC = $(TARGET).plugin/Contents/MacOS/$(TARGET)
+        PY_MODULE_SRC = $(TARGET)
 
         QMAKE_LFLAGS += "-undefined dynamic_lookup"
 
