$NetBSD: patch-setup.py,v 1.1 2021/12/06 14:56:43 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2013-12-17 04:07:27.000000000 +0000
+++ setup.py
@@ -36,5 +36,4 @@ more to learn about it.
       test_suite='nose.collector',
       include_package_data=True,
       zip_safe=True,
-      use_2to3=True,
       )
