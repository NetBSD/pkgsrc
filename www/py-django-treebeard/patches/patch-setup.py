$NetBSD: patch-setup.py,v 1.2 2021/03/19 09:09:50 adam Exp $

Fix encoding error for Python 3.6.

--- setup.py.orig	2021-02-15 03:07:11.000000000 +0000
+++ setup.py
@@ -3,7 +3,7 @@ from setuptools import setup, find_packa
 from treebeard import __version__
 
 
-with open('README.md') as fh:
+with open('README.md', encoding='utf-8') as fh:
     long_description = fh.read()
 
 
