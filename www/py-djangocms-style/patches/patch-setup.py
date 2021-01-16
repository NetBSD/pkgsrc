$NetBSD: patch-setup.py,v 1.3 2021/01/16 10:12:50 adam Exp $

Do not install tests.

--- setup.py.orig	2021-01-16 10:02:35.000000000 +0000
+++ setup.py
@@ -45,7 +45,7 @@ setup(
     license='BSD-3-Clause',
     description='Adds style plugin to django CMS',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
