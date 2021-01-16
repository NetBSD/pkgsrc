$NetBSD: patch-setup.py,v 1.1 2021/01/16 10:13:54 adam Exp $

Do not install tests.

--- setup.py.orig	2021-01-16 10:08:40.000000000 +0000
+++ setup.py
@@ -47,7 +47,7 @@ setup(
     license="BSD-3-Clause",
     description="Text Plugin for django CMS with CKEditor support",
     long_description=open("README.rst").read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
