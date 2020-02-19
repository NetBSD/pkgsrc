$NetBSD: patch-setup.py,v 1.3 2020/02/19 11:09:52 adam Exp $

Do not install tests.

--- setup.py.orig	2018-05-03 10:53:37.000000000 +0000
+++ setup.py
@@ -11,7 +11,7 @@ setup(
     description = 'DjangoCMS image gallery plugin with drag&drop '
                   'reordering in admin, support for thumbnails and '
                   'jQueryTOOLS overlay.',
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     provides=['cmsplugin_gallery', ],
     include_package_data=True,
     install_requires = ['django-cms>=3.2.0', 'django-inline-ordering>=0.1.1',
