$NetBSD: patch-setup.py,v 1.1 2018/03/02 15:36:47 bsiegert Exp $

Accept any newer gflags version. Python 2.6 compatibility is irrelevant.
--- setup.py.orig	2018-01-16 22:17:29.000000000 +0000
+++ setup.py
@@ -36,7 +36,7 @@ REQUIRED_PACKAGES = [
 
 CLI_PACKAGES = [
     'google-apputils>=0.4.0',
-    'python-gflags==3.0.6',  # Starting version 3.0.7 py26 is not supported.
+    'python-gflags>=3.0.6',
 ]
 
 TESTING_PACKAGES = [
