$NetBSD: patch-setup.py,v 1.1 2018/03/13 10:04:49 adam Exp $

Do not install tests.

--- setup.py.orig	2018-03-13 09:58:20.000000000 +0000
+++ setup.py
@@ -11,7 +11,7 @@ setup(
     description = 'DjangoCMS image gallery plugin with drag&drop '
                   'reordering in admin, support for thumbnails and '
                   'jQueryTOOLS overlay.',
-    packages=find_packages(),
+    packages=['cmsplugin_gallery'],
     provides=['cmsplugin_gallery', ],
     include_package_data=True,
     install_requires = ['django-inline-ordering>=0.1.1', 'easy-thumbnails',]
