$NetBSD: patch-setup.py,v 1.5 2022/12/17 06:22:02 adam Exp $

Add multi Python variant support.

--- setup.py.orig	2022-12-16 19:31:55.000000000 +0000
+++ setup.py
@@ -662,10 +662,11 @@ def get_extension(argv, split_extension_
 def get_data_files():
     # a list of tuples with (path to install to, a list of local files)
     data_files = []
+    version = '{}.{}'.format(sys.version_info.major, sys.version_info.minor)
     if sys.platform == "win32":
-        datadir = os.path.join("doc", PACKAGE)
+        datadir = os.path.join("doc", PACKAGE + version)
     else:
-        datadir = os.path.join("share", "doc", PACKAGE)
+        datadir = os.path.join("share", "doc", PACKAGE  + version)
     #
     files = ["AUTHORS", "ChangeLog", "COPYING-LGPL", "COPYING-MIT",
         "INSTALL.rst", "README.rst", "RELEASE-NOTES.rst"]
