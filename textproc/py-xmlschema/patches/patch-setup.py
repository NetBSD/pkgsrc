$NetBSD: patch-setup.py,v 1.1 2020/05/31 20:49:34 joerg Exp $

--- setup.py.orig	2020-05-31 18:07:15.361949598 +0000
+++ setup.py
@@ -8,12 +8,13 @@
 #
 # @author Davide Brunato <brunato@sissa.it>
 #
+import sys
 import importlib
 from setuptools import setup
 from setuptools.command.develop import develop
 from setuptools.command.install import install
 
-with open("README.rst") as readme:
+with open("README.rst", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as readme:
     long_description = readme.read()
 
 
