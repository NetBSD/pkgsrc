$NetBSD: patch-setup.py,v 1.6 2026/06/30 20:27:08 adam Exp $

Add multi Python variant support.

--- setup.py.orig	2026-06-29 18:09:02.000000000 +0000
+++ setup.py
@@ -673,10 +673,11 @@ def get_extension(argv, split_extension_
 def get_data_files():
     # a list of tuples with (path to install to, a list of local files)
     data_files = []
+    version = '{}.{}'.format(sys.version_info.major, sys.version_info.minor)
     if sys.platform == "win32":
-        datadir = os.path.join("doc", PROJECT_NAME)
+        datadir = os.path.join("doc", PROJECT_NAME + version)
     else:
-        datadir = os.path.join("share", "doc", PROJECT_NAME)
+        datadir = os.path.join("share", "doc", PROJECT_NAME + version)
     #
     files = ["AUTHORS", "ChangeLog", "COPYING-LGPL", "COPYING-MIT",
         "INSTALL.rst", "README.rst", "RELEASE-NOTES.rst"]
