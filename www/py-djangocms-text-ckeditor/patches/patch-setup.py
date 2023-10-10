$NetBSD: patch-setup.py,v 1.2 2023/10/10 17:01:31 adam Exp $

Do not install tests.

--- setup.py.orig	2023-10-03 16:31:00.000000000 +0000
+++ setup.py
@@ -63,7 +63,7 @@ setup(
     description='Text Plugin for django CMS with CKEditor support',
     long_description=long_description,
     long_description_content_type='text/x-rst',
-    packages=find_packages(exclude=['tests']),
+    packages=find_packages(exclude=['tests*']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
