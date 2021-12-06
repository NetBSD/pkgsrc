$NetBSD: patch-setup.py,v 1.2 2021/12/06 14:41:21 wiz Exp $

Remove hardcoded version limits.

--- setup.py.orig	2021-10-05 12:14:00.000000000 +0000
+++ setup.py
@@ -16,7 +16,7 @@ if not (2,7) <= sys.version_info[:2] < (
 
 tests_require = [
     'pytest<4.7' if sys.version_info[:2] < (3,0) else 'pytest',
-    'dnspython==1.16.0' if sys.version_info[:2] < (3,0) else 'dnspython>=2.0.0',
+    'dnspython',
     'pycountry<19' if sys.version_info < (3,0) else 'pycountry']
 
 setup_requires = [
