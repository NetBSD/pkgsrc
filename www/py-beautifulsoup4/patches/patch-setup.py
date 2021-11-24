$NetBSD: patch-setup.py,v 1.1 2021/11/24 11:38:11 wiz Exp $

option not supported any longer.

--- setup.py.orig	2020-10-03 15:31:00.000000000 +0000
+++ setup.py
@@ -30,7 +30,6 @@ setup(
         'lxml' : [ 'lxml'],
         'html5lib' : ['html5lib'],
     },
-    use_2to3 = True,
     classifiers=["Development Status :: 5 - Production/Stable",
                  "Intended Audience :: Developers",
                  "License :: OSI Approved :: MIT License",
