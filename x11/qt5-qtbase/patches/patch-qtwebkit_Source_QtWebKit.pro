$NetBSD: patch-qtwebkit_Source_QtWebKit.pro,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Make all libraries as shared, I am not sure...

--- qtwebkit/Source/QtWebKit.pro.orig	2013-11-27 01:01:51.000000000 +0000
+++ qtwebkit/Source/QtWebKit.pro
@@ -5,7 +5,7 @@
 # -------------------------------------------------------------------
 
 TEMPLATE = subdirs
-CONFIG += ordered
+CONFIG += ordered force_static_libs_as_shared
 
 api.file = api.pri
 SUBDIRS += api
