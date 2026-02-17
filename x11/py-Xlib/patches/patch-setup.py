$NetBSD: patch-setup.py,v 1.1 2026/02/17 15:10:08 wiz Exp $

Fix build with setuptools 82.
https://github.com/python-xlib/python-xlib/issues/286

--- setup.py.orig	2026-02-17 15:06:10.418245753 +0000
+++ setup.py
@@ -1,12 +1,9 @@
 # Distutils script for python-xlib
 
-from pkg_resources import parse_requirements
 from setuptools import (__version__ as setuptools_version, setup)
 
 
 # Check setuptools is recent enough to support `setup.cfg`.
-setuptools_require = next(parse_requirements('setuptools>=30.3.0'))
-assert setuptools_version in setuptools_require, '{} is required'.format(setuptools_require)
 
 
 setup(
