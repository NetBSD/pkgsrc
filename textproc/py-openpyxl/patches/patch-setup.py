$NetBSD: patch-setup.py,v 1.1 2018/11/23 11:42:17 adam Exp $

Prefer lxml to et_xmlfile.

--- setup.py.orig	2018-11-23 11:39:16.000000000 +0000
+++ setup.py
@@ -59,7 +59,7 @@ setup(
     license=__license__,
     python_requires=">=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*",
     install_requires=[
-        'jdcal', 'et_xmlfile',
+        'jdcal', 'lxml',
         ],
     project_urls={
         'Documentation': 'https://openpyxl.readthedocs.io/en/stable/',
