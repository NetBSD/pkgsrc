$NetBSD: patch-setup.py,v 1.3 2020/07/22 06:36:22 wiz Exp $

Remove upper bound for click to make pkgsrc versions be accepted.

--- setup.py.orig	2020-06-09 12:14:43.000000000 +0000
+++ setup.py
@@ -11,7 +11,7 @@ from setuptools import Command, find_pac
 
 requirements = [
     # https://github.com/mitsuhiko/click/issues/200
-    'click>=5.0,<6.0',
+    'click>=5.0',
     'click-log>=0.3.0, <0.4.0',
 
     # https://github.com/pimutils/vdirsyncer/issues/478
