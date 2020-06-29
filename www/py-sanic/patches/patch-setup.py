$NetBSD: patch-setup.py,v 1.6 2020/06/29 14:29:20 adam Exp $

Allow newer versions.

--- setup.py.orig	2020-06-28 10:14:53.000000000 +0000
+++ setup.py
@@ -81,7 +81,7 @@ requirements = [
     "aiofiles>=0.3.0",
     "websockets>=8.1,<9.0",
     "multidict>=4.0,<5.0",
-    "httpx==0.11.1",
+    "httpx>=0.11.1",
 ]
 
 tests_require = [
