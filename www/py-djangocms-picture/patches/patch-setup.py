$NetBSD: patch-setup.py,v 1.1 2018/11/20 18:47:52 adam Exp $

Do not install tests.

--- setup.py.orig	2018-11-13 09:10:16.000000000 +0000
+++ setup.py
@@ -42,7 +42,7 @@ setup(
     url='https://github.com/divio/djangocms-picture',
     license='BSD',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
