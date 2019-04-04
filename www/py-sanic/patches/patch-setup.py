$NetBSD: patch-setup.py,v 1.3 2019/04/04 12:25:38 adam Exp $

Allow newer versions.

--- setup.py.orig	2019-03-23 02:52:58.000000000 +0000
+++ setup.py
@@ -81,8 +81,8 @@ requirements = [
     uvloop,
     ujson,
     "aiofiles>=0.3.0",
-    "websockets>=6.0,<7.0",
-    "multidict>=4.0,<5.0",
+    "websockets>=6.0",
+    "multidict>=4.0",
 ]
 
 tests_require = [
