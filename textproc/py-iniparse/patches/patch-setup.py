$NetBSD: patch-setup.py,v 1.1 2020/06/18 21:45:06 adam Exp $

Skip data_files as they conflict between Python versions.

--- setup.py.orig	2020-06-18 21:41:34.000000000 +0000
+++ setup.py
@@ -34,12 +34,5 @@ use.''',
       ],
       packages = ['iniparse'],
       install_requires=['six'],
-      data_files = [
-        ('share/doc/iniparse-%s' % VERSION, ['README.md', 'LICENSE-PSF',
-                                             'LICENSE', 'Changelog',
-                                             'html/index.html',
-                                             'html/style.css',
-                                             ]),
-      ],
 )
 
