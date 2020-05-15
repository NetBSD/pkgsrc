$NetBSD: patch-setup.py,v 1.5 2020/05/15 08:32:34 adam Exp $

Allow newer versions.

--- setup.py.orig	2020-05-14 19:06:33.000000000 +0000
+++ setup.py
@@ -85,7 +85,7 @@ requirements = [
     "aiofiles>=0.3.0",
     "websockets>=7.0,<9.0",
     "multidict>=4.0,<5.0",
-    "httpx==0.11.1",
+    "httpx>=0.11.1",
 ]
 
 tests_require = [
