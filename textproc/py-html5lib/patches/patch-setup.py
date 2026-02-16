$NetBSD: patch-setup.py,v 1.2 2026/02/16 19:01:02 wiz Exp $

Fix build with Python 3.14
Based on a comment in
https://github.com/html5lib/html5lib-python/pull/589

--- setup.py.orig	2020-06-22 23:23:02.000000000 +0000
+++ setup.py
@@ -6,9 +6,7 @@ from setuptools import setup, find_packages, __version
 
 from os.path import join, dirname
 from setuptools import setup, find_packages, __version__ as setuptools_version
-from pkg_resources import parse_version
 
-import pkg_resources
 
 try:
     import _markerlib.markers
@@ -46,17 +44,6 @@ if _markerlib and sys.version_info[0] == 3:
 
     _markerlib.default_environment = default_environment
 
-# Avoid the very buggy pkg_resources.parser, which doesn't consistently
-# recognise the markers needed by this setup.py
-# Change this to setuptools 20.10.0 to support all markers.
-if pkg_resources:
-    if parse_version(setuptools_version) < parse_version('18.5'):
-        MarkerEvaluation = pkg_resources.MarkerEvaluation
-
-        del pkg_resources.parser
-        pkg_resources.evaluate_marker = MarkerEvaluation._markerlib_evaluate
-        MarkerEvaluation.evaluate_marker = MarkerEvaluation._markerlib_evaluate
-
 classifiers = [
     'Development Status :: 5 - Production/Stable',
     'Intended Audience :: Developers',
@@ -89,9 +76,14 @@ with open(join(here, "html5lib", "__init__.py"), "rb")
     for a in assignments:
         if (len(a.targets) == 1 and
                 isinstance(a.targets[0], ast.Name) and
-                a.targets[0].id == "__version__" and
-                isinstance(a.value, ast.Str)):
-            version = a.value.s
+                a.targets[0].id == "__version__"):
+            if hasattr(ast, "Str") and isinstance(a.value, ast.Str):
+                version = a.value.s
+            elif (hasattr(ast, "Constant")
+                  and isinstance(a.value, ast.Constant)
+                  and isinstance(a.value.value, str)):
+                version = a.value.value
+assert version is not None
 
 setup(name='html5lib',
       version=version,
