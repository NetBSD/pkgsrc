$NetBSD: patch-setup.py,v 1.1 2018/03/24 17:06:44 joerg Exp $

--- setup.py.orig	2018-03-24 14:40:26.001382784 +0000
+++ setup.py
@@ -28,7 +28,7 @@ setup(
     license='BSD-3-Clause',
     packages=['pytest_django'],
     long_description=read('README.rst'),
-    setup_requires=['setuptools_scm==1.11.1'],
+    setup_requires=['setuptools_scm>=1.11.1'],
     install_requires=['pytest>=2.9'],
     classifiers=['Development Status :: 5 - Production/Stable',
                  'Framework :: Django',
