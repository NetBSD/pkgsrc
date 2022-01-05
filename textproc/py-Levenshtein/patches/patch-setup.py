$NetBSD: patch-setup.py,v 1.1 2022/01/05 10:01:08 wiz Exp $

setuptools not needed
https://github.com/ztane/python-Levenshtein/issues/79

--- setup.py.orig	2021-02-01 12:03:07.000000000 +0000
+++ setup.py
@@ -39,7 +39,6 @@ setup(name='python-Levenshtein',
       zip_safe=False,
       ext_modules = [extLevensthein],
       install_requires=[
-          'setuptools',
           # -*- Extra requirements: -*-
       ],
       entry_points="""
