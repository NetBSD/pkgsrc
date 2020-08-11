$NetBSD: patch-setup.py,v 1.1 2020/08/11 18:41:55 joerg Exp $

--- setup.py.orig	2020-02-09 10:45:34.000000000 +0000
+++ setup.py
@@ -2,13 +2,13 @@
 
 # Using setuptools rather than distutils to get the `develop` command
 from setuptools import setup
-
+import sys
 
 NAME = 'feedgenerator'
 PACKAGES = ['feedgenerator', 'feedgenerator.django',
             'feedgenerator.django.utils']
 DESCRIPTION = 'Standalone version of django.utils.feedgenerator'
-LONG_DESCRIPTION = open('README.rst').read()
+LONG_DESCRIPTION = open('README.rst', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read()
 
 URL = "https://github.com/getpelican/feedgenerator"
 
