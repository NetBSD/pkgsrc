$NetBSD: patch-setup.py,v 1.6 2024/08/10 11:39:13 wiz Exp $

Use the right path for man-pages in pkgsrc.

--- setup.py.orig	2024-05-30 02:19:25.000000000 +0000
+++ setup.py
@@ -175,10 +175,7 @@ class InstallData(install_data):
     return data_files
 
 
-if platform.system() in ['OpenBSD']:
-  man_dir = 'man'
-else:
-  man_dir = 'share/man'
+man_dir = '@PKGMANDIR@'
 
 test_deps = [
     'pytest'
