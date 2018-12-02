$NetBSD: patch-setup.py,v 1.1 2018/12/02 16:21:40 adam Exp $

Relax test requirements.

--- setup.py.orig	2018-12-02 16:17:06.000000000 +0000
+++ setup.py
@@ -33,9 +33,9 @@ if sys.argv[-1] == 'publish':
     sys.exit()
 
 tests_require = [
-    'pytest==3.7.1',
-    'pytest-cov==2.5.1',
-    'pytest-runner==4.2',
+    'pytest>=3.7.1',
+    'pytest-cov>=2.5.1',
+    'pytest-runner>=4.2',
 ]
 
 needs_pytest = set(('pytest', 'test', 'ptr')).intersection(sys.argv)
