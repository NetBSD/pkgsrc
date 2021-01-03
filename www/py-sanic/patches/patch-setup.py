$NetBSD: patch-setup.py,v 1.9 2021/01/03 22:41:44 adam Exp $

Allow newer versions.

--- setup.py.orig	2020-12-28 21:58:53.000000000 +0000
+++ setup.py
@@ -89,15 +89,15 @@ requirements = [
     "aiofiles>=0.6.0",
     "websockets>=8.1,<9.0",
     "multidict>=5.0,<6.0",
-    "httpx==0.15.4",
+    "httpx>=0.15.4",
 ]
 
 tests_require = [
-    "pytest==5.2.1",
+    "pytest>=5.2.1",
     "multidict>=5.0,<6.0",
-    "gunicorn==20.0.4",
+    "gunicorn>=20.0.4",
     "pytest-cov",
-    "httpcore==0.11.*",
+    "httpcore>=0.11.*",
     "beautifulsoup4",
     uvloop,
     ujson,
