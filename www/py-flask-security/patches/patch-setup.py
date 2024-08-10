$NetBSD: patch-setup.py,v 1.1 2024/08/10 09:42:15 wiz Exp $

Remove unused dependencies.

--- setup.py.orig	2024-08-10 09:39:31.992535597 +0000
+++ setup.py
@@ -41,8 +41,6 @@ for reqs in extras_require.values():
     extras_require['all'].extend(reqs)
 
 setup_requires = [
-    'Babel>=1.3',
-    'pytest-runner>=2.6.2',
 ]
 
 install_requires = [
