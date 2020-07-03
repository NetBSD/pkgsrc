$NetBSD: patch-Python_configure.py,v 1.1.2.2 2020/07/03 10:29:50 bsiegert Exp $

Avoid app bundles and use proper dylib id on Darwin.

--- Python/configure.py.orig	2020-06-09 14:28:23.000000000 +0000
+++ Python/configure.py
@@ -1470,7 +1470,7 @@ def _generate_pro(target_config, opts, m
         pro.write('QT += %s\n' % qt)
 
     pro.write('CONFIG += %s\n' % ('debug' if target_config.debug else 'release'))
-    pro.write('CONFIG += %s\n' % ('staticlib' if opts.static else 'plugin plugin_bundle'))
+    pro.write('CONFIG += %s\n' % ('staticlib' if opts.static else 'plugin'))
 
     config = qmake_config.get('CONFIG')
     if config:
@@ -1511,7 +1511,7 @@ win32 {
     PY_MODULE = %s.so
 
     macx {
-        PY_MODULE_SRC = $(TARGET).plugin/Contents/MacOS/$(TARGET)
+        PY_MODULE_SRC = $(TARGET)
 
         QMAKE_LFLAGS += "-undefined dynamic_lookup"
 
@@ -1621,12 +1621,11 @@ INSTALLS += sip
     if not opts.static:
         dylib = module_config.get_mac_wrapped_library_file(target_config)
 
-        if dylib:
-            pro.write('''
+        pro.write('''
 macx {
-    QMAKE_POST_LINK = $$QMAKE_POST_LINK$$escape_expand(\\\\n\\\\t)$$quote(install_name_tool -change %s %s $$PY_MODULE)
+    QMAKE_POST_LINK = $$QMAKE_POST_LINK$$escape_expand(\\\\n\\\\t)$$quote(install_name_tool -id $$target.path/$$PY_MODULE $$PY_MODULE)
 }
-''' % (os.path.basename(dylib), dylib))
+''')
 
     pro.write('\n')
     pro.write('HEADERS = sipAPI%s.h\n' % mname)
