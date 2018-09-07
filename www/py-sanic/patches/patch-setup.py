$NetBSD: patch-setup.py,v 1.1 2018/09/07 11:30:47 adam Exp $

Allow newer versions.

--- setup.py.orig	2018-09-07 10:56:22.000000000 +0000
+++ setup.py
@@ -60,8 +60,8 @@ requirements = [
     uvloop,
     ujson,
     'aiofiles>=0.3.0',
-    'websockets>=5.0,<6.0',
-    'multidict>=4.0,<5.0',
+    'websockets>=5.0',
+    'multidict>=4.0',
 ]
 if strtobool(os.environ.get("SANIC_NO_UJSON", "no")):
     print("Installing without uJSON")
