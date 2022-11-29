$NetBSD: patch-setup.py,v 1.3 2022/11/29 10:20:57 adam Exp $

Prefer lxml to et_xmlfile; the latter is a subset of the former.

--- setup.py.orig	2022-03-08 15:06:53.000000000 +0000
+++ setup.py
@@ -76,7 +76,7 @@ setup(
     license=__license__,
     python_requires=f">={__python__}",
     install_requires=[
-        'et_xmlfile',
+        'lxml',
         ],
     project_urls={
         'Documentation': 'https://openpyxl.readthedocs.io/en/stable/',
