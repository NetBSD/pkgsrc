$NetBSD: patch-setup.py,v 1.1 2020/02/23 23:59:04 joerg Exp $

Don't use obsolete parse_requirements.

--- setup.py.orig	2020-02-22 21:20:06.604663786 +0000
+++ setup.py
@@ -2,7 +2,6 @@
 import uuid
 import os
 from setuptools import setup, find_packages
-from pip.req import parse_requirements
 
 import photologue
 
@@ -44,5 +43,4 @@ setup(
                  'Programming Language :: Python :: 3.4',
                  'Programming Language :: Python :: 3.5',
                  'Topic :: Utilities'],
-    install_requires=get_requirements('requirements.txt'),
 )
