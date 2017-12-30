$NetBSD: patch-setup.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- setup.py.orig	2017-12-25 08:47:37.000000000 +0000
+++ setup.py
@@ -51,7 +51,7 @@ try:
         packages=find_packages(),
         install_requires=[
             "django-contrib-comments",
-            "django >= 1.8, < 1.11",
+            "django >= 1.8",
             "filebrowser_safe >= 0.4.6",
             "grappelli_safe >= 0.4.5",
             "tzlocal >= 1.0",
