$NetBSD: patch-setup.py,v 1.2 2017/07/13 06:09:38 adam Exp $

Allow newer py-nose versions.

--- setup.py.orig	2017-07-11 08:25:23.000000000 +0000
+++ setup.py
@@ -15,7 +15,7 @@ install_requires = [
 ]
 
 tests_require = [
-    'nose<1.3.0', 'coverage', 'mock',
+    'nose', 'coverage', 'mock',
     'PasteDeploy', 'WSGIProxy2', 'pyquery'
 ]
 
