$NetBSD: patch-setup.py,v 1.1 2021/01/16 09:02:28 adam Exp $

Do not install tests.

--- setup.py.orig	2021-01-16 08:24:26.000000000 +0000
+++ setup.py
@@ -41,7 +41,7 @@ setup(
     license='BSD',
     description='Class based template tags for Django',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
