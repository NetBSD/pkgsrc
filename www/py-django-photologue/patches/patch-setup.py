$NetBSD: patch-setup.py,v 1.3 2026/02/17 15:17:46 wiz Exp $

Fix build with setuptools 82.
https://github.com/richardbarran/django-photologue/issues/229

--- setup.py.orig	2026-02-17 15:15:39.604404938 +0000
+++ setup.py
@@ -1,15 +1,9 @@
 # /usr/bin/env python
-from pkg_resources import parse_requirements
 from setuptools import find_packages, setup
 
 import photologue
 
 
-def get_requirements(source):
-    with open(source) as f:
-        return sorted({str(req) for req in parse_requirements(f.read())})
-
-
 setup(
     name="django-photologue",
     version=photologue.__version__,
@@ -33,5 +27,4 @@ setup(
                  'Programming Language :: Python :: 3.5',
                  'Programming Language :: Python :: 3.6',
                  'Topic :: Utilities'],
-    install_requires=get_requirements('requirements.txt'),
 )
