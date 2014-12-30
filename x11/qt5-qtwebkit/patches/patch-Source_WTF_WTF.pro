$NetBSD: patch-Source_WTF_WTF.pro,v 1.1 2014/12/30 17:23:47 adam Exp $

* Install libWTF shared library

--- Source/WTF/WTF.pro.orig	2014-09-11 10:48:11.000000000 +0000
+++ Source/WTF/WTF.pro
@@ -8,7 +8,9 @@ TARGET = WTF
 
 include(WTF.pri)
 
-CONFIG += staticlib optimize_full
+CONFIG += optimize_full
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 VPATH += $$PWD/wtf
 
