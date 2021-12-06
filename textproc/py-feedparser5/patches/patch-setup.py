$NetBSD: patch-setup.py,v 1.1 2021/12/06 15:11:25 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2015-07-24 05:00:04.000000000 +0000
+++ setup.py
@@ -2,8 +2,6 @@ from setuptools import setup
 import sys
 
 extra = {}
-if sys.version_info >= (3, ):
-    extra['use_2to3'] = True
 
 setup(
     name = 'feedparser',
