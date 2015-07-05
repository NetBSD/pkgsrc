$NetBSD: patch-setup.py,v 1.1 2015/07/05 12:41:26 joerg Exp $

--- setup.py.orig	2015-07-05 10:18:01.000000000 +0000
+++ setup.py
@@ -8,8 +8,8 @@ from setuptools import find_packages, se
 
 setup(
     name='vdirsyncer',
-    use_scm_version=True,
-    setup_requires=['setuptools_scm'],
+    version='0.5.2',
+    setup_requires=['setuptools'],
     author='Markus Unterwaditzer',
     author_email='markus@unterwaditzer.net',
     url='https://github.com/untitaker/vdirsyncer',
