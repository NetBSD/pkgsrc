$NetBSD: patch-setup.py,v 1.1 2021/01/16 09:24:52 adam Exp $

Do not install tests.

--- setup.py.orig	2021-01-16 09:06:44.000000000 +0000
+++ setup.py
@@ -43,7 +43,7 @@ setup(
     license='BSD-3-Clause',
     description='Adds pretty CSS styles for the django CMS admin interface.',
     long_description=open('README.rst').read(),
-    packages=find_packages(exclude=['preview']),
+    packages=find_packages(exclude=['preview', 'tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
