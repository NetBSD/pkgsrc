$NetBSD: patch-setup.py,v 1.1 2015/07/13 16:13:55 kleink Exp $

Adjust dictionaries path to allow multiple Python version installs.

--- setup.py.orig	2013-12-27 17:53:41.000000000 +0100
+++ setup.py	2015-07-13 17:48:37.000000000 +0200
@@ -1,4 +1,5 @@
 import os.path
+import sys
 from setuptools import setup
 
 classifiers = [
@@ -28,7 +29,7 @@
     py_modules=['pyphen'],
     provides=['pyphen'],
     data_files=[(
-        os.path.join('share', 'pyphen', 'dictionaries'), (
+        os.path.join('share', 'pyphen%s' % sys.version[0:3], 'dictionaries'), (
             os.path.join(_dict_folder, filename)
             for filename in os.listdir(_dict_folder)
             if filename.endswith('.dic')))],
