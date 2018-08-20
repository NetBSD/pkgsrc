$NetBSD: patch-setup.py,v 1.2 2018/08/20 07:31:51 adam Exp $

Stick to distutils.
Add multi Python variant support.

--- setup.py.orig	2018-06-02 04:59:02.000000000 +0000
+++ setup.py
@@ -10,12 +10,7 @@ VERSION = "7.43.0.2"
 
 import glob, os, re, sys, subprocess
 import distutils
-try:
-    import wheel
-    if wheel:
-        from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 from distutils.extension import Extension
 from distutils.util import split_quoted
 from distutils.version import LooseVersion
@@ -605,9 +600,9 @@ def get_data_files():
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
