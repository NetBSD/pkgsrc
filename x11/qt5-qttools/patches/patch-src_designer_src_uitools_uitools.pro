$NetBSD: patch-src_designer_src_uitools_uitools.pro,v 1.2 2015/10/26 19:04:00 adam Exp $

* Libtoolized and build as shared library

--- src/designer/src/uitools/uitools.pro.orig	2015-10-13 04:38:12.000000000 +0000
+++ src/designer/src/uitools/uitools.pro
@@ -1,5 +1,5 @@
 TARGET = QtUiTools
-CONFIG += static
+CONFIG +=
 
 include(../lib/uilib/uilib.pri)
 
