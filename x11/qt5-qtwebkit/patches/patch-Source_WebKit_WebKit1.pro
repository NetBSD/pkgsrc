$NetBSD: patch-Source_WebKit_WebKit1.pro,v 1.1 2014/12/30 17:23:48 adam Exp $

* Build libWebKit libraries with libtool
* Install libWebKit libraries

--- Source/WebKit/WebKit1.pro.orig	2013-11-27 01:01:39.000000000 +0000
+++ Source/WebKit/WebKit1.pro
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
