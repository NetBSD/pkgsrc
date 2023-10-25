$NetBSD: patch-setup.py,v 1.1 2023/10/25 19:40:36 markd Exp $

Don't pin to a single version
https://github.com/django-compressor/django-compressor/issues/1195

--- setup.py.orig	2023-01-22 12:40:08.000000000 +0000
+++ setup.py
@@ -163,7 +163,7 @@ setup(
     zip_safe=False,
     install_requires=[
         "django-appconf >= 1.0.3",
-        "rcssmin == 1.1.1",
-        "rjsmin == 1.2.1",
+        "rcssmin >= 1.1.1",
+        "rjsmin >= 1.2.1",
     ],
 )
