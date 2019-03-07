$NetBSD: patch-setupinfo.py,v 1.1 2019/03/07 18:01:21 jperkin Exp $

Do not use -isysroot on Darwin, causes wrapper issues.

--- setupinfo.py.orig	2019-01-04 15:34:22.000000000 +0000
+++ setupinfo.py
@@ -130,7 +130,7 @@ def ext_modules(static_include_dirs, sta
         ])
     _library_dirs = _prefer_reldirs(base_dir, library_dirs(static_library_dirs))
     _cflags = cflags(static_cflags)
-    _ldflags = ['-isysroot', get_xcode_isysroot()] if sys.platform == 'darwin' else None
+    _ldflags = ['-isysroot', get_xcode_isysroot()] if sys.platform == 'notdarwin' else None
     _define_macros = define_macros()
     _libraries = libraries()
 
