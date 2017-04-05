$NetBSD: patch-setup.py,v 1.1 2017/04/05 17:56:18 adam Exp $

Add multi Python variant support.

--- setup.py.orig	2016-02-04 04:39:06.000000000 +0000
+++ setup.py
@@ -520,9 +520,9 @@ def get_data_files():
     # a list of tuples with (path to install to, a list of local files)
     data_files = []
     if sys.platform == "win32":
-        datadir = os.path.join("doc", PACKAGE)
+        datadir = os.path.join("doc", PACKAGE + sys.version[0:3])
     else:
-        datadir = os.path.join("share", "doc", PACKAGE)
+        datadir = os.path.join("share", "doc", PACKAGE  + sys.version[0:3])
     #
     files = ["AUTHORS", "ChangeLog", "COPYING-LGPL", "COPYING-MIT",
         "INSTALL.rst", "README.rst", "RELEASE-NOTES.rst"]
