$NetBSD: patch-setup.py,v 1.8 2020/10/27 23:07:42 adam Exp $

Allow newer versions.

--- setup.py.orig	2020-10-25 13:09:05.000000000 +0000
+++ setup.py
@@ -80,8 +80,8 @@ requirements = [
     ujson,
     "aiofiles>=0.3.0",
     "websockets>=8.1,<9.0",
-    "multidict==5.0.0",
-    "httpx==0.15.4",
+    "multidict>=5.0.0",
+    "httpx>=0.15.4",
 ]
 
 tests_require = [
