$NetBSD: patch-setup.py,v 1.1 2017/07/11 09:18:01 adam Exp $

Allow newer py-nose versions.

--- /tmp/pkgsrc/www/py-WebTest/work/WebTest-2.0.27/setup.py.orig	2017-07-11 08:25:23.000000000 +0000
+++ /tmp/pkgsrc/www/py-WebTest/work/WebTest-2.0.27/setup.py
@@ -15,7 +15,7 @@ install_requires = [
 ]
 
 tests_require = [
-    'nose<1.3.0', 'coverage', 'mock',
+    'nose', 'coverage', 'mock',
     'PasteDeploy', 'WSGIProxy2', 'pyquery'
 ]
 
