$NetBSD: patch-setup.py,v 1.1 2018/12/16 14:04:55 adam Exp $

Exclude tests.

--- setup.py.orig	2018-12-16 13:07:21.000000000 +0000
+++ setup.py
@@ -41,7 +41,7 @@ setup(
     license='BSD',
     description='Adds audio plugin to django CMS.',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
