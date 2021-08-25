$NetBSD: patch-setup.py,v 1.3 2021/08/25 09:01:07 adam Exp $

Stick to distutils.
Add multi Python variant support.

--- setup.py.orig	2021-08-15 19:30:48.000000000 +0000
+++ setup.py
@@ -10,10 +10,7 @@ VERSION = "7.44.1"
 
 import glob, os, re, sys, subprocess
 import distutils
-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 from distutils.extension import Extension
 from distutils.util import split_quoted
 from distutils.version import LooseVersion
@@ -687,9 +684,9 @@ def get_data_files():
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
