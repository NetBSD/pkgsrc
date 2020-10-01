$NetBSD: patch-setup.py,v 1.7 2020/10/01 06:53:12 adam Exp $

Allow newer versions.

--- setup.py.orig	2020-09-30 14:40:18.000000000 +0000
+++ setup.py
@@ -81,7 +81,7 @@ requirements = [
     "aiofiles>=0.3.0",
     "websockets>=8.1,<9.0",
     "multidict>=4.0,<5.0",
-    "httpx==0.15.4",
+    "httpx>=0.15.4",
 ]
 
 tests_require = [
