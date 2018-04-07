$NetBSD: patch-setup.py,v 1.2 2018/04/07 20:09:37 adam Exp $

Do not install tests.

--- setup.py.orig	2018-03-14 18:01:43.000000000 +0000
+++ setup.py
@@ -11,7 +11,7 @@ setup(
     description = 'DjangoCMS image gallery plugin with drag&drop '
                   'reordering in admin, support for thumbnails and '
                   'jQueryTOOLS overlay.',
-    packages=find_packages(),
+    packages=['cmsplugin_gallery'],
     provides=['cmsplugin_gallery', ],
     include_package_data=True,
     install_requires = ['django-cms>=3.2.0', 'django-inline-ordering>=0.1.1', 'easy-thumbnails',]
