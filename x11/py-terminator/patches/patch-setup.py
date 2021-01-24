$NetBSD: patch-setup.py,v 1.4 2021/01/24 11:15:07 kamil Exp $

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
@@ -246,4 +242,3 @@ setup(name=APP_NAME,
       package_data={'terminatorlib': ['preferences.glade', 'layoutlauncher.glade']},
       cmdclass={'build': BuildData, 'install_data': InstallData, 'uninstall': Uninstall},
       distclass=TerminatorDist)
-
