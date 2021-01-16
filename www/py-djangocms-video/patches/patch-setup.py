$NetBSD: patch-setup.py,v 1.3 2021/01/16 10:14:40 adam Exp $

Do not install tests.

--- setup.py.orig	2021-01-16 10:10:12.000000000 +0000
+++ setup.py
@@ -46,7 +46,7 @@ setup(
     license='BSD-3-Clause',
     description='Adds video plugin to django CMS.',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
