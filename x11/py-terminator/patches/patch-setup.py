$NetBSD: patch-setup.py,v 1.5 2024/08/10 11:33:31 wiz Exp $

Use the right path for man-pages in pkgsrc.

Install the man pages in the right directory.

--- setup.py.orig	2021-01-04 15:50:10.000000000 +0000
+++ setup.py
@@ -186,11 +186,7 @@ class InstallData(install_data):
 
     return data_files
 
-
-if platform.system() in ['FreeBSD', 'OpenBSD']:
-  man_dir = 'man'
-else:
-  man_dir = 'share/man'
+man_dir = '@PKGMANDIR@'
 
 test_deps = [
     'pytest'
@@ -232,7 +228,6 @@ setup(name=APP_NAME,
           'terminatorlib.plugins',
       ],
       setup_requires=[
-          'pytest-runner',
       ],
       install_requires=[
           'pycairo',
