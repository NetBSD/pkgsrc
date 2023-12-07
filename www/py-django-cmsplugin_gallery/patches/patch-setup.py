$NetBSD: patch-setup.py,v 1.4 2023/12/07 17:43:51 adam Exp $

Do not install tests.

--- setup.py.orig	2022-04-20 15:48:34.000000000 +0000
+++ setup.py
@@ -48,7 +48,7 @@ setup(
                   'jQueryTOOLS overlay.',
     long_description=readme + "\n\n" + history,
     long_description_content_type="text/markdown",
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     provides=['cmsplugin_gallery', ],
     include_package_data=True,
     install_requires = ['django-cms>=3.9.0', 'django-inline-ordering==1.0.2',
