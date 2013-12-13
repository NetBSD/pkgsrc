$NetBSD: patch-qttools_src_designer_src_uitools_uitools.pro,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Libtoolized and build as shared library

--- qttools/src/designer/src/uitools/uitools.pro.orig	2013-11-27 01:01:52.000000000 +0000
+++ qttools/src/designer/src/uitools/uitools.pro
@@ -1,5 +1,5 @@
 TARGET = QtUiTools
-CONFIG += static
+CONFIG += 
 QT = core
 
 QMAKE_DOCS = $$PWD/doc/qtuitools.qdocconf
