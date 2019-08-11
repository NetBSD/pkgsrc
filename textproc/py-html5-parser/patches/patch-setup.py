$NetBSD: patch-setup.py,v 1.1 2019/08/11 18:16:40 adam Exp $

Do not use -O3.

--- setup.py.orig	2019-08-11 18:10:55.000000000 +0000
+++ setup.py
@@ -19,7 +19,7 @@ if True:
 del sys.path[0]
 
 src_files = tuple(chain(*map(lambda x: find_c_files(x)[0], SRC_DIRS)))
-cargs = ('/O2' if iswindows else '-O3').split()
+cargs = []
 if not iswindows:
     cargs.extend('-std=c99 -fvisibility=hidden'.split())
 
