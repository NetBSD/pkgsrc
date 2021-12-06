$NetBSD: patch-setup.py,v 1.1 2021/12/06 15:17:57 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2020-09-11 06:47:40.000000000 +0000
+++ setup.py
@@ -44,9 +44,6 @@ extra = dict(
     ],
 )
 
-if python_version >= 3.0:
-    extra["use_2to3"] = True
-
 # -- NICE-TO-HAVE:
 # # FILE: setup.cfg -- Use pytest-runner (ptr) as test runner.
 # [aliases]
