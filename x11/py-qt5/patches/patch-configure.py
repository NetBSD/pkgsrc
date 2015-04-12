$NetBSD: patch-configure.py,v 1.2 2015/04/12 17:55:46 adam Exp $

On Darwin, do not expect application bundle.
Adapt for pkgsrc change to make qmake create libtool files.

--- configure.py.orig	2014-12-25 10:18:15.000000000 +0000
+++ configure.py
@@ -1858,10 +1858,7 @@ def run_make(target_config, verbose, exe
         make = 'make'
         makefile_target = ''
 
-        if target_config.py_platform == 'darwin':
-            platform_exe = os.path.join(exe + '.app', 'Contents', 'MacOS', exe)
-        else:
-            platform_exe = os.path.join('.', exe)
+        platform_exe = os.path.join('.', exe)
 
     remove_file(platform_exe)
 
@@ -2363,8 +2360,8 @@ win32 {
     target.files = %s%s.pyd
     LIBS += %s
 } else {
-    PY_MODULE = %s.so
-    target.files = %s.so
+    PY_MODULE = %s.la
+    target.files = %s.la
 }
 ''' % (target_name, debug_suffix, target_name, debug_suffix, link, target_name, target_name)
 
@@ -2434,7 +2431,6 @@ win32 {
 }
 macx {
     QMAKE_LFLAGS += "-undefined dynamic_lookup"
-    QMAKE_LFLAGS += "-install_name $$absolute_path($$PY_MODULE, $$target.path)"
 }
 '''
 
