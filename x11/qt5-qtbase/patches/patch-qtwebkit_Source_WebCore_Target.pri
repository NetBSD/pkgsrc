$NetBSD: patch-qtwebkit_Source_WebCore_Target.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Build libWebCore with libtool
* Install libWebCore libraries

--- qtwebkit/Source/WebCore/Target.pri.orig	2013-11-27 01:01:46.000000000 +0000
+++ qtwebkit/Source/WebCore/Target.pri
@@ -12,7 +12,10 @@ include(WebCore.pri)
 WEBKIT += wtf
 WEBKIT += javascriptcore
 
-CONFIG += staticlib
+#CONFIG += staticlib
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 # Do it in the WebCore static lib to support force_static_libs_as_shared
 # since the QtWebKitWidgets lib wouldn't load QtWebKit in that case.
