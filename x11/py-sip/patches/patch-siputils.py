$NetBSD: patch-siputils.py,v 1.2 2014/08/21 21:32:39 wiz Exp $

Fix build on Darwin with pkgsrc python.

--- siputils.py.orig	2014-05-10 15:00:48.000000000 +0000
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
