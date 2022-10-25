$NetBSD: patch-setup.py,v 1.3 2022/10/25 08:30:14 adam Exp $

Remove hardcoded version limits.
Remove setuptools_scm_git_archive from requirements.

--- setup.py.orig	2021-10-05 12:14:00.000000000 +0000
+++ setup.py
@@ -16,12 +16,11 @@ if not (2,7) <= sys.version_info[:2] < (
 
 tests_require = [
     'pytest<4.7' if sys.version_info[:2] < (3,0) else 'pytest',
-    'dnspython==1.16.0' if sys.version_info[:2] < (3,0) else 'dnspython>=2.0.0',
+    'dnspython',
     'pycountry<19' if sys.version_info < (3,0) else 'pycountry']
 
 setup_requires = [
     'setuptools_scm<6.0' if sys.version_info[:2] < (3,0) else 'setuptools_scm',
-    'setuptools_scm_git_archive',
 ]
 
 doctests = ['docs/htmlfill.txt', 'docs/Validator.txt',
