$NetBSD: patch-setup.py,v 1.2 2022/03/02 22:10:48 gutteridge Exp $

setuptools not needed.

Also remove the empty entry_points definition, as it causes different
behaviour between old and most recent py-setuptools, resulting in
unnecessary variation of PLIST entries.

https://github.com/ztane/python-Levenshtein/issues/79

--- setup.py.orig	2021-02-01 12:03:07.000000000 +0000
+++ setup.py
@@ -39,9 +39,6 @@ setup(name='python-Levenshtein',
       zip_safe=False,
       ext_modules = [extLevensthein],
       install_requires=[
-          'setuptools',
           # -*- Extra requirements: -*-
       ],
-      entry_points="""
-      """,
       )
