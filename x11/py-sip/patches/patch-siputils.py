$NetBSD: patch-siputils.py,v 1.1 2014/01/10 17:41:07 jperkin Exp $

Fix build on Darwin with pkgsrc python.

--- siputils.py.orig	2013-03-28 21:14:10.000000000 +0000
+++ siputils.py
@@ -258,6 +258,9 @@ class Makefile:
         self._installs = installs
         self._infix = ""
 
+        if sys.platform == "darwin":
+            self.config.qt_framework = 0
+
         # Make sure the destination directory is an absolute path.
         if dir:
             self.dir = os.path.abspath(dir)
@@ -1561,8 +1564,8 @@ class ModuleMakefile(Makefile):
             # Note that I can't remember why we need a framework build.
             dl = get_python_inc().split(os.sep)
 
-            if "Python.framework" not in dl:
-                error("SIP requires Python to be built as a framework")
+            #if "Python.framework" not in dl:
+            #    error("SIP requires Python to be built as a framework")
 
             self.LFLAGS.append("-undefined dynamic_lookup")
 
