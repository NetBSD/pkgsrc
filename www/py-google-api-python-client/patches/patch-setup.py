$NetBSD: patch-setup.py,v 1.1 2022/01/27 11:57:26 wiz Exp $

Relax restrictions.

--- setup.py.orig	2021-07-27 10:49:04.000000000 +0000
+++ setup.py
@@ -42,7 +42,7 @@ install_requires = [
     # Until this issue is closed
     # https://github.com/googleapis/google-cloud-python/issues/10566
     "google-api-core>=1.21.0,<3.0.0dev",
-    "uritemplate>=3.0.0,<4dev",
+    "uritemplate>=3.0.0",
 ]
 
 package_root = os.path.abspath(os.path.dirname(__file__))
