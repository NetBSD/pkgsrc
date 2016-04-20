$NetBSD: patch-setup.py,v 1.2 2016/04/20 16:10:14 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2016-04-13 11:17:13.000000000 +0000
+++ setup.py
@@ -61,10 +61,10 @@ setup(
         'Programming Language :: Python :: Implementation :: PyPy',
     ],
     install_requires=[
-        'hyperframe>=3.1, <5, !=4.0.0',
-        'hpack>=2.0, <3',
+        'hyperframe>=3.1',
+        'hpack>=2.0',
     ],
     extras_require={
-        ':python_version == "2.7" or python_version == "3.3"': ['enum34>=1.0.4, <2'],
+        ':python_version == "2.7" or python_version == "3.3"': ['enum34>=1.0.4'],
     }
 )
