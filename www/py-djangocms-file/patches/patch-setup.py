$NetBSD: patch-setup.py,v 1.4 2023/10/10 16:50:55 adam Exp $

Do not install tests.

--- setup.py.orig	2023-07-03 23:34:23.000000000 +0000
+++ setup.py
@@ -53,7 +53,7 @@ setup(
     description='Adds file plugin to django CMS',
     long_description=open('README.rst').read(),
     long_description_content_type='text/x-rst',
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
