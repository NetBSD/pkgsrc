$NetBSD: patch-setup.py,v 1.1 2020/05/07 09:29:04 adam Exp $

Always use setuptools.

--- setup.py.orig	2020-05-07 09:23:44.000000000 +0000
+++ setup.py
@@ -9,23 +9,8 @@ try:
 except AttributeError:
     py_major = sys.version_info[0]
 
-distmech = None
-if py_major >= 3:
-    # Python 3, use setuptools first
-    try:
-        from setuptools import setup
-        distmech = 'setuptools'
-    except ImportError:
-        from distutils.core import setup
-        distmech = 'distutils'
-else:
-    # Python 2, use distutils first
-    try:
-        from distutils.core import setup
-        distmech = 'distutils'
-    except ImportError:
-        from setuptools import setup
-        distmech = 'setuptools'
+from setuptools import setup
+distmech = 'setuptools'
 
 if False:
     sys.stdout.write("Using Python:    %s\n" % sys.version.split(None,1)[0])
