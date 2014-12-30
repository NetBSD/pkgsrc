$NetBSD: patch-Source_QtWebKit.pro,v 1.1 2014/12/30 17:23:47 adam Exp $

* Make all libraries as shared
* Do not build examples

--- Source/QtWebKit.pro.orig	2014-09-11 10:48:24.000000000 +0000
+++ Source/QtWebKit.pro
@@ -5,7 +5,7 @@
 # -------------------------------------------------------------------
 
 TEMPLATE = subdirs
-CONFIG += ordered
+CONFIG += ordered force_static_libs_as_shared
 
 api.file = api.pri
 SUBDIRS += api
@@ -39,8 +39,4 @@ build?(webkit1) {
         SUBDIRS += tests
     }
 
-    examples.file = WebKit/qt/examples/examples.pro
-    examples.CONFIG += no_default_target
-    examples.makefile = Makefile
-    SUBDIRS += examples
 }
