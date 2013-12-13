$NetBSD: patch-qtwebkit_Source_ThirdParty_ANGLE_Target.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Libtoolized
* Install libANGLE library

--- qtwebkit/Source/ThirdParty/ANGLE/Target.pri.orig	2013-11-27 01:01:50.000000000 +0000
+++ qtwebkit/Source/ThirdParty/ANGLE/Target.pri
@@ -9,7 +9,10 @@ TARGET = ANGLE
 
 include(ANGLE.pri)
 
-CONFIG += staticlib
+#CONFIG += staticlib
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 INCLUDEPATH += \
     $$SOURCE_DIR/src \
