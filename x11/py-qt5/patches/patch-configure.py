$NetBSD: patch-configure.py,v 1.1 2015/02/07 16:30:37 wiz Exp $

Adapt for pkgsrc change to make qmake create libtool files.

--- configure.py.orig	2014-03-14 14:38:18.000000000 +0000
+++ configure.py
@@ -2149,8 +2149,8 @@ win32 {
     target.files = %s%s.pyd
     LIBS += %s
 } else {
-    PY_MODULE = %s.so
-    target.files = %s.so
+    PY_MODULE = %s.la
+    target.files = %s.la
 }
 ''' % (target_name, debug_suffix, target_name, debug_suffix, link, target_name, target_name)
 
