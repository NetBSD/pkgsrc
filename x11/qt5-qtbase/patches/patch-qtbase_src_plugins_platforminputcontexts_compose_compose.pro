$NetBSD: patch-qtbase_src_plugins_platforminputcontexts_compose_compose.pro,v 1.1 2014/01/28 08:46:14 ryoon Exp $

PR pkg/48553

--- qtbase/src/plugins/platforminputcontexts/compose/compose.pro.orig	2013-12-08 17:09:53.000000000 +0000
+++ qtbase/src/plugins/platforminputcontexts/compose/compose.pro
@@ -16,6 +16,8 @@ SOURCES += $$PWD/main.cpp \
 HEADERS += $$PWD/qcomposeplatforminputcontext.h \
            $$PWD/generator/qtablegenerator.h \
 
+DEFINES += X11BASE=\\\"$$(X11BASE)\\\"
+
 # libxkbcommon
 contains(QT_CONFIG, xkbcommon-qt): {
     include(../../../3rdparty/xkbcommon.pri)
