$NetBSD: patch-setup.py,v 1.3 2016/04/21 11:17:26 jperkin Exp $

Use the right path for man-pages in pkgsrc.

Install the man pages in the right directory.

--- setup.py.orig	2015-09-08 15:27:00.000000000 +0000
+++ setup.py
@@ -205,10 +205,7 @@ class Test(Command):
     raise SystemExit(errno)
 
 
-if platform.system() in ['FreeBSD', 'OpenBSD']:
-  man_dir = 'man'
-else:
-  man_dir = 'share/man'
+man_dir = '@PKGMANDIR@'
 
 setup(name=APP_NAME.capitalize(),
       version=APP_VERSION,
@@ -248,4 +245,3 @@ setup(name=APP_NAME.capitalize(),
       cmdclass={'build': BuildData, 'install_data': InstallData, 'uninstall': Uninstall, 'test':Test},
       distclass=TerminatorDist
      )
-
