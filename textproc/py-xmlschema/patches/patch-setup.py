$NetBSD: patch-setup.py,v 1.2 2020/09/14 08:57:38 adam Exp $

Fix for Python 3.6.

--- setup.py.orig	2020-09-13 19:12:09.000000000 +0000
+++ setup.py
@@ -10,7 +10,7 @@
 #
 from setuptools import setup, find_packages
 
-with open("README.rst") as readme:
+with open("README.rst", encoding='utf-8') as readme:
     long_description = readme.read()
 
 
