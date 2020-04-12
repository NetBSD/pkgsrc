$NetBSD: patch-configure.py,v 1.8 2020/04/12 06:24:31 adam Exp $

Do not expect an app bundle on Darwin.

--- configure.py.orig	2020-04-02 14:58:06.000000000 +0000
+++ configure.py
@@ -2137,10 +2137,7 @@ def run_make(target_config, verbose, exe
         make = 'make'
         makefile_target = ''
 
-        if target_config.py_platform == 'darwin':
-            platform_exe = os.path.join(exe + '.app', 'Contents', 'MacOS', exe)
-        else:
-            platform_exe = os.path.join('.', exe)
+        platform_exe = os.path.join('.', exe)
 
     remove_file(platform_exe)
 
@@ -2702,7 +2699,7 @@ def generate_module_makefile(target_conf
 
     # Note some version of Qt5 (probably incorrectly) implements
     # 'plugin_bundle' instead of 'plugin' so we specify both.
-    pro_lines.append('CONFIG += warn_on exceptions_off %s' % ('staticlib hide_symbols' if target_config.static else 'plugin plugin_bundle'))
+    pro_lines.append('CONFIG += warn_on exceptions_off %s' % ('staticlib hide_symbols' if target_config.static else 'plugin'))
 
     pro_add_qt_dependencies(target_config, metadata, pro_lines)
 
@@ -2748,7 +2745,7 @@ win32 {
     PY_MODULE = %s.so
 
     macx {
-        PY_MODULE_SRC = $(TARGET).plugin/Contents/MacOS/$(TARGET)
+        PY_MODULE_SRC = $(TARGET)
 
         QMAKE_LFLAGS += "-undefined dynamic_lookup"
 
@@ -3008,7 +3005,7 @@ def check_sip(target_config, verbose):
 
             os.makedirs(target_config.sip_inc_dir, exist_ok=True)
 
-            argv = ['sip-module', '--sip-h']
+            argv = ['sip-module-@PYVERSSUFFIX@', '--sip-h']
 
             if target_config.abi_version:
                 argv.append('--abi-version')
