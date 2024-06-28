$NetBSD: patch-setup.py,v 1.2 2024/06/28 09:58:11 adam Exp $

Don't pin to a single version
https://github.com/django-compressor/django-compressor/issues/1195

--- setup.py.orig	2024-06-16 17:24:41.000000000 +0000
+++ setup.py
@@ -164,7 +164,7 @@ setup(
     install_requires=[
         "Django >= 4.2",
         "django-appconf >= 1.0.3",
-        "rcssmin == 1.1.2",
-        "rjsmin == 1.2.2",
+        "rcssmin >= 1.1.2",
+        "rjsmin >= 1.2.2",
     ],
 )
