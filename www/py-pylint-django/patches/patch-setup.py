$NetBSD: patch-setup.py,v 1.3 2018/02/27 12:42:30 adam Exp $

Do not install tests.

--- setup.py.orig	2018-02-26 21:41:01.000000000 +0000
+++ setup.py
@@ -7,10 +7,8 @@ from setuptools import setup, find_packa
 
 VERSION = '0.9.1'
 PACKAGES = find_packages(exclude=[
-    '*.tests',
-    '*.tests.*',
-    'tests.*',
-    'tests',
+    'test.*',
+    'test',
 ])
 
 SHORT_DESCRIPTION = 'A Pylint plugin to help Pylint understand the Django web framework'
