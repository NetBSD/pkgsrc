$NetBSD: patch-setup.py,v 1.1 2021/12/06 14:59:35 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2012-06-21 22:59:59.000000000 +0000
+++ setup.py
@@ -2,8 +2,6 @@ import os
 import sys
 
 extra = {}
-if sys.version_info >= (3, 0):
-    extra.update(use_2to3=True)
 
 try:
     from setuptools import setup, find_packages
