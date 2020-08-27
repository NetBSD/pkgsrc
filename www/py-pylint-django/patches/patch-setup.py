$NetBSD: patch-setup.py,v 1.5 2020/08/27 12:25:00 joerg Exp $

--- setup.py.orig	2020-08-26 11:51:51.672175441 +0000
+++ setup.py
@@ -3,8 +3,9 @@
 Setup module for Pylint plugin for Django.
 """
 from setuptools import setup, find_packages
+import sys
 
-LONG_DESCRIPTION = open('README.rst').read() + "\n" + open('CHANGELOG.rst').read()
+LONG_DESCRIPTION = open('README.rst', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read() + "\n" + open('CHANGELOG.rst', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read()
 
 setup(
     name='pylint-django',
