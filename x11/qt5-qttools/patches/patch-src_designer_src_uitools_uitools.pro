$NetBSD: patch-src_designer_src_uitools_uitools.pro,v 1.1 2014/12/30 17:23:47 adam Exp $

* Libtoolized and build as shared library

--- src/designer/src/uitools/uitools.pro.orig	2013-11-27 01:01:52.000000000 +0000
+++ src/designer/src/uitools/uitools.pro
@@ -1,5 +1,5 @@
 TARGET = QtUiTools
-CONFIG += static
+CONFIG += 
 QT = core
 
 QMAKE_DOCS = $$PWD/doc/qtuitools.qdocconf
