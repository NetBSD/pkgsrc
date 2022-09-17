$NetBSD: patch-setup.py,v 1.1 2022/09/17 21:26:31 wiz Exp $

Unrestrict dependency.

--- setup.py.orig	2022-03-17 15:42:48.000000000 +0000
+++ setup.py
@@ -27,7 +27,7 @@ setup(
         'python-dateutil',
         'pytz',
         # https://bitbucket.org/mrabarnett/mrab-regex/issues/314/import-error-no-module-named
-        'regex !=2019.02.19,!=2021.8.27,<2022.3.15',
+        'regex !=2019.02.19,!=2021.8.27',
         'tzlocal',
     ],
     entry_points={
