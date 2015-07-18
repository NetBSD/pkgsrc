$NetBSD: patch-src_tools_bootstrap_bootstrap.pro,v 1.1 2015/07/18 11:11:53 adam Exp $

--- src/tools/bootstrap/bootstrap.pro.orig	2015-05-07 14:14:44.000000000 +0000
+++ src/tools/bootstrap/bootstrap.pro
@@ -103,7 +103,6 @@ else:unix:SOURCES += ../../corelib/tools
 else:win32:SOURCES += ../../corelib/tools/qlocale_win.cpp
 
 macx: {
-   QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.4 #enables weak linking for 10.4 (exported)
    SOURCES += ../../corelib/kernel/qcore_mac.cpp
    LIBS += -framework CoreServices -framework ApplicationServices
 }
