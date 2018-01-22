$NetBSD: patch-configure.py,v 1.6 2018/01/22 04:17:11 dbj Exp $

Do not expect an app bundle on Darwin.

--- configure.py.orig	2017-11-02 10:53:20.000000000 +0000
+++ configure.py
@@ -1968,7 +1968,7 @@ def run_make(target_config, verbose, exe
         make = 'make'
         makefile_target = ''
 
-        if target_config.py_platform == 'darwin':
+        if target_config.py_platform == 'darwin' and False:
             platform_exe = os.path.join(exe + '.app', 'Contents', 'MacOS', exe)
         else:
             platform_exe = os.path.join('.', exe)
