$NetBSD: patch-Source_WebCore_Target.pri,v 1.1 2014/12/30 17:23:47 adam Exp $

* Build libWebCore with libtool
* Install libWebCore libraries

--- Source/WebCore/Target.pri.orig	2013-11-27 01:01:46.000000000 +0000
+++ Source/WebCore/Target.pri
@@ -12,7 +12,8 @@ include(WebCore.pri)
 WEBKIT += wtf
 WEBKIT += javascriptcore
 
-CONFIG += staticlib
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 # Do it in the WebCore static lib to support force_static_libs_as_shared
 # since the QtWebKitWidgets lib wouldn't load QtWebKit in that case.
