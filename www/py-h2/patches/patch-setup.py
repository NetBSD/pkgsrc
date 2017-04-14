$NetBSD: patch-setup.py,v 1.3 2017/04/14 13:10:13 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2016-08-23 13:35:40.000000000 +0000
+++ setup.py
@@ -61,8 +61,8 @@ setup(
         'Programming Language :: Python :: Implementation :: PyPy',
     ],
     install_requires=[
-        'hyperframe>=3.1, <5, !=4.0.0',
-        'hpack>=2.2, <3',
+        'hyperframe>=3.1',
+        'hpack>=2.2',
     ],
     extras_require={
         ':python_version == "2.7" or python_version == "3.3"': ['enum34>=1.0.4, <2'],
