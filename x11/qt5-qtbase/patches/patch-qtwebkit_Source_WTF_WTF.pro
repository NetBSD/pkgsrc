$NetBSD: patch-qtwebkit_Source_WTF_WTF.pro,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Libtoolized
* Install libWTF shared library

--- qtwebkit/Source/WTF/WTF.pro.orig	2013-11-27 01:01:20.000000000 +0000
+++ qtwebkit/Source/WTF/WTF.pro
@@ -8,7 +8,10 @@ TARGET = WTF
 
 include(WTF.pri)
 
-CONFIG += staticlib
+#CONFIG += staticlib
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 VPATH += $$PWD/wtf
 
