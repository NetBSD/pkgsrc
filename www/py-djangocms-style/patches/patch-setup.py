$NetBSD: patch-setup.py,v 1.1 2018/11/20 18:48:56 adam Exp $

Do not install tests.

--- setup.py.orig	2018-11-08 08:19:23.000000000 +0000
+++ setup.py
@@ -40,7 +40,7 @@ setup(
     url='https://github.com/divio/djangocms-style',
     license='BSD',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
