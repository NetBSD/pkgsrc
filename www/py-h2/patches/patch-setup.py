$NetBSD: patch-setup.py,v 1.1 2016/02/16 13:49:56 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2016-02-05 14:50:35.000000000 +0000
+++ setup.py
@@ -57,10 +57,10 @@ setup(
         'Programming Language :: Python :: Implementation :: PyPy',
     ],
     install_requires=[
-        'hyperframe>=3.1, <4',
-        'hpack>=2.0, <3',
+        'hyperframe>=3.1',
+        'hpack>=2.0',
     ],
     extras_require={
-        ':python_version == "2.7" or python_version == "3.3"': ['enum34>=1.0.4, <1.1'],
+        ':python_version == "2.7" or python_version == "3.3"': ['enum34>=1.0.4'],
     }
 )
