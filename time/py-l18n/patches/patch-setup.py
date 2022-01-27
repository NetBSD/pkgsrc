$NetBSD: patch-setup.py,v 1.3 2022/01/27 08:20:26 wiz Exp $

We are not interested in building a wheel, so we do not
want to depend on py-wheel either.

--- setup.py.orig	2021-11-12 09:24:24.000000000 +0000
+++ setup.py
@@ -30,7 +30,6 @@ DEV_STATUS = {'pre': '2 - Pre-Alpha',
 CMD_PACKAGES = {
     'sdist': 'setuptools.command',
     'bdist': 'distutils.command',
-    'bdist_wheel': 'wheel',
     'bdist_egg': 'setuptools.command',
     'bdist_rpm': 'setuptools.command',
 }
