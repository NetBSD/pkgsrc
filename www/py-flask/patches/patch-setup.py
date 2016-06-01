$NetBSD: patch-setup.py,v 1.1 2016/06/01 21:05:46 kleink Exp $

Adjust script path to allow multiple Python version installs.

--- setup.py.orig	2016-05-22 08:33:12.000000000 +0000
+++ setup.py
@@ -43,6 +43,7 @@ Links
 
 """
 import re
+import sys
 import ast
 from setuptools import setup
 
@@ -93,6 +94,6 @@ setup(
     ],
     entry_points='''
         [console_scripts]
-        flask=flask.cli:main
-    '''
+        flask%s=flask.cli:main
+    ''' % sys.version[0:3]
 )
