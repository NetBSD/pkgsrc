$NetBSD: patch-setup.py,v 1.4 2023/11/01 18:20:50 adam Exp $

Do not install tests.

--- setup.py.orig	2023-11-01 18:18:34.277473378 +0000
+++ setup.py
@@ -59,7 +59,7 @@ setup(
     description='Adds an image plugin to django CMS',
     long_description=long_description,
     long_description_content_type='text/x-rst',
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
