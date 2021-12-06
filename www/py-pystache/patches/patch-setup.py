$NetBSD: patch-setup.py,v 1.1 2021/12/06 14:17:03 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2014-05-12 12:15:34.000000000 +0000
+++ setup.py
@@ -351,12 +351,6 @@ def get_extra_args():
 
     """
     extra = {}
-    # TODO: it might be more correct to check whether we are using
-    #   Distribute instead of setuptools, since use_2to3 doesn't take
-    #   effect when using Python 2, even when using Distribute.
-    if py_version >= (3, ):
-        # Causes 2to3 to be run during the build step.
-        extra['use_2to3'] = True
 
     return extra
 
