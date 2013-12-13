$NetBSD: patch-qtwebkit_Source_WebKit_WebKit1.pro,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Build libWebKit libraries with libtool
* Install libWebKit libraries

--- qtwebkit/Source/WebKit/WebKit1.pro.orig	2013-11-27 01:01:39.000000000 +0000
+++ qtwebkit/Source/WebKit/WebKit1.pro
@@ -16,7 +16,10 @@ QT += gui
 # defined by the logic in qt_module.prf as it should
 DEFINES += QT_BUILD_WEBKIT_LIB
 
-CONFIG += staticlib
+#CONFIG += staticlib
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 SOURCES += \
     $$PWD/qt/Api/qhttpheader.cpp \
