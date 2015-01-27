$NetBSD: patch-configure_configure.py,v 1.1 2015/01/27 06:11:12 dbj Exp $

On pkgsrc, python is installed more like generic unix and less like Mac OS.

--- configure/configure.py.orig	2009-08-01 07:28:33.000000000 +0000
+++ configure/configure.py
@@ -155,8 +155,6 @@ def make_and_run_qt_program(name, code, 
     if sys.platform == "win32":
         exe = os.path.join("release", name + ".exe")
         make_target = " release"
-    elif sys.platform == "darwin":
-        exe = os.path.join(name + ".app", "Contents", "MacOS", name)
     else:
         exe = os.path.join(".", name)
 
