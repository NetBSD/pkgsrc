$NetBSD: patch-setup.py,v 1.2 2019/01/18 08:15:07 adam Exp $

Allow newer versions.

--- setup.py.orig	2019-01-18 08:10:59.000000000 +0000
+++ setup.py
@@ -61,8 +61,8 @@ requirements = [
     uvloop,
     ujson,
     'aiofiles>=0.3.0',
-    'websockets>=6.0,<7.0',
-    'multidict>=4.0,<5.0',
+    'websockets>=6.0',
+    'multidict>=4.0',
 ]
 if strtobool(os.environ.get("SANIC_NO_UJSON", "no")):
     print("Installing without uJSON")
