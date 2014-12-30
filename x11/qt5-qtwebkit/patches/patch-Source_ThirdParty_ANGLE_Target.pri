$NetBSD: patch-Source_ThirdParty_ANGLE_Target.pri,v 1.1 2014/12/30 17:23:47 adam Exp $

* Libtoolized
* Install libANGLE library

--- Source/ThirdParty/ANGLE/Target.pri.orig	2013-11-27 01:01:50.000000000 +0000
+++ Source/ThirdParty/ANGLE/Target.pri
@@ -9,7 +9,10 @@ TARGET = ANGLE
 
 include(ANGLE.pri)
 
-CONFIG += staticlib
+#CONFIG += staticlib
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 INCLUDEPATH += \
     $$SOURCE_DIR/src \
