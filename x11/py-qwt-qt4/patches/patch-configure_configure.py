$NetBSD: patch-configure_configure.py,v 1.2 2019/09/16 01:51:42 mef Exp $

1. On pkgsrc, python is installed more like generic unix and less like Mac OS.
2. build with py-sip 4.19.18

--- configure/configure.py.orig	2009-08-01 16:28:33.000000000 +0900
+++ configure/configure.py	2019-09-16 08:03:52.221548278 +0900
@@ -155,8 +155,6 @@ def make_and_run_qt_program(name, code, 
     if sys.platform == "win32":
         exe = os.path.join("release", name + ".exe")
         make_target = " release"
-    elif sys.platform == "darwin":
-        exe = os.path.join(name + ".app", "Contents", "MacOS", name)
     else:
         exe = os.path.join(".", name)
 
@@ -1075,7 +1073,7 @@ def main():
     
     options = check_sip(configuration, options)
     options = check_os(configuration, options)
-    options = check_compiler(configuration, options)
+#   options = check_compiler(configuration, options)
     options = check_numarray(configuration, options, 'PyQwt')
     options = check_numeric(configuration, options, 'PyQwt')
     options = check_numpy(configuration, options, 'PyQwt')
