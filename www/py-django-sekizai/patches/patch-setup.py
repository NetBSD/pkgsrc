$NetBSD: patch-setup.py,v 1.1 2021/01/16 09:02:05 adam Exp $

Do not install tests.

--- setup.py.orig	2021-01-16 08:27:06.000000000 +0000
+++ setup.py
@@ -42,7 +42,7 @@ setup(
     license='BSD-3-Clause',
     description='Django Sekizai',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
