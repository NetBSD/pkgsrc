$NetBSD: patch-setup.py,v 1.1 2018/02/26 12:09:18 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2017-12-31 17:19:40.000000000 +0000
+++ setup.py
@@ -47,10 +47,10 @@ setup(
         'Programming Language :: Python :: Implementation :: PyPy',
     ],
     install_requires=[
-        'h11 ~= 0.7.0',  # means: 0.7.x where x >= 0
+        'h11>=0.7.0',
     ],
     extras_require={
         ':python_version == "2.7" or python_version == "3.3"':
-            ['enum34>=1.0.4, <2'],
+            ['enum34>=1.0.4'],
     }
 )
