$NetBSD: patch-setup.py,v 1.4 2023/12/07 17:57:26 adam Exp $

Do not install tests.

--- setup.py.orig	2023-12-06 22:08:53.000000000 +0000
+++ setup.py
@@ -51,7 +51,7 @@ setup(
     license="BSD-3-Clause",
     description="Adds style plugin to django CMS",
     long_description=open("README.rst").read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
