$NetBSD: patch-Source_api.pri,v 1.1 2014/12/30 17:23:48 adam Exp $

OS X also requires dummy object file, otherwise 'ar' would fail.

--- Source/api.pri.orig	2014-11-17 12:03:52.000000000 +0000
+++ Source/api.pri
@@ -102,7 +102,7 @@ load(qt_module)
     }
 }
 
-qnx {
+macx|qnx {
     # see: https://bugs.webkit.org/show_bug.cgi?id=93460
     # the gcc 4.4.2 used in the qnx bbndk cannot cope with
     # the linkage step of libQtWebKit, adding a dummy .cpp
