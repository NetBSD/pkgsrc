$NetBSD: patch-qtwebkit_Source_WebKit2_Target.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Fix build from the lack of many headers, this is ugly hack
* Build libWebKit2 with libtool
* Install libWebKit2 libraries

--- qtwebkit/Source/WebKit2/Target.pri.orig	2013-11-27 01:01:51.000000000 +0000
+++ qtwebkit/Source/WebKit2/Target.pri
@@ -7,11 +7,16 @@
 TEMPLATE = lib
 TARGET = WebKit2
 
+QMAKE_EXTRA_TARGETS += fwheader_generator
+
 include(WebKit2.pri)
 
 WEBKIT += wtf javascriptcore webcore
 
-CONFIG += staticlib
+#CONFIG += staticlib
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 RESOURCES += $$PWD/WebKit2.qrc
 
