$NetBSD: patch-setup.py,v 1.1 2020/08/18 01:01:56 joerg Exp $

--- setup.py.orig	2020-08-18 00:55:43.861248992 +0000
+++ setup.py
@@ -23,8 +23,8 @@ from setuptools import setup
 
 version = '1.4.1'
 
-if platform.system() in ('Linux','Unix'):
-    man1pages = [('share/man/man1', [
+if True:
+    man1pages = [('@PKGMANDIR@/man1', [
            'csv2ods/csv2ods.1',
            'mailodf/mailodf.1',
            'odf2xhtml/odf2xhtml.1',
