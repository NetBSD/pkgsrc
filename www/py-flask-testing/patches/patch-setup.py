$NetBSD: patch-setup.py,v 1.1 2017/12/12 10:07:27 adam Exp $

Allow newer py-twill.

--- setup.py.orig	2017-12-12 10:03:22.000000000 +0000
+++ setup.py
@@ -23,7 +23,7 @@ install_requires = [
 ]
 
 if sys.version_info[0] < 3:
-    tests_require.append('twill==0.9.1')
+    tests_require.append('twill>=0.9.1')
 
 if sys.version_info < (2, 6):
     tests_require.append('simplejson')
