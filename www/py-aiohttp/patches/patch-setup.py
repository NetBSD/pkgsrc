$NetBSD: patch-setup.py,v 1.1 2021/02/06 20:41:34 leot Exp $

Bump chardet requirements, via:

 https://github.com/aio-libs/aiohttp/commit/b0ed732d0a637e43c72bb1a777d02776cde37376

--- setup.py.orig	2020-11-18 17:42:33.000000000 +0000
+++ setup.py
@@ -66,7 +66,7 @@ except IndexError:
 
 install_requires = [
     "attrs>=17.3.0",
-    "chardet>=2.0,<4.0",
+    "chardet>=2.0",
     "multidict>=4.5,<7.0",
     "async_timeout>=3.0,<4.0",
     "yarl>=1.0,<2.0",
