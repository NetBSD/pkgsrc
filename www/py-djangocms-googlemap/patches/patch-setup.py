$NetBSD: patch-setup.py,v 1.1 2018/11/20 18:44:03 adam Exp $

Do not install tests.

--- setup.py.orig	2018-11-20 18:13:56.000000000 +0000
+++ setup.py
@@ -40,7 +40,7 @@ setup(
     license='BSD',
     description='Adds Google Maps plugins to django CMS.',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
