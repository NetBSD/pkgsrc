$NetBSD: patch-setup.py,v 1.1 2020/05/18 13:34:30 wiz Exp $

Accept any ujson.
https://github.com/palantir/python-jsonrpc-server/issues/36

--- setup.py.orig	2020-01-19 16:34:33.000000000 +0000
+++ setup.py
@@ -34,7 +34,7 @@ setup(
     install_requires=[
         'future>=0.14.0; python_version<"3"',
         'futures; python_version<"3.2"',
-        'ujson<=1.35; platform_system!="Windows"',
+        'ujson',
     ],
 
     # List additional groups of dependencies here (e.g. development
