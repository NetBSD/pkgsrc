$NetBSD: patch-setup.py,v 1.3 2021/06/11 05:24:08 adam Exp $

Fix for Python 3.6.

--- setup.py.orig	2021-06-09 17:22:21.000000000 +0000
+++ setup.py
@@ -12,7 +12,7 @@ from setuptools import setup, find_packa
 from pathlib import Path
 
 
-with Path(__file__).parent.joinpath('README.rst').open() as readme:
+with Path(__file__).parent.joinpath('README.rst').open(encoding='utf-8') as readme:
     long_description = readme.read()
 
 
