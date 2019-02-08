$NetBSD: patch-setup.py,v 1.2 2019/02/08 10:48:38 adam Exp $

Prefer lxml to et_xmlfile.

--- setup.py.orig	2019-02-06 14:12:51.000000000 +0000
+++ setup.py
@@ -59,7 +59,7 @@ setup(
     license=__license__,
     python_requires=">=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*, !=3.4.*",
     install_requires=[
-        'jdcal', 'et_xmlfile',
+        'jdcal', 'lxml',
         ],
     project_urls={
         'Documentation': 'https://openpyxl.readthedocs.io/en/stable/',
