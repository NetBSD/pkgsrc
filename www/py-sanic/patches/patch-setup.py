$NetBSD: patch-setup.py,v 1.4 2020/01/08 21:03:21 adam Exp $

Allow newer versions.

--- setup.py.orig	2020-01-02 21:35:13.000000000 +0000
+++ setup.py
@@ -84,7 +84,7 @@ requirements = [
     "aiofiles>=0.3.0",
     "websockets>=7.0,<9.0",
     "multidict>=4.0,<5.0",
-    "httpx==0.9.3",
+    "httpx>=0.9.3",
 ]
 
 tests_require = [
