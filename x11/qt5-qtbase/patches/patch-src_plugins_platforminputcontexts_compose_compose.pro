$NetBSD: patch-src_plugins_platforminputcontexts_compose_compose.pro,v 1.1 2014/12/30 17:23:46 adam Exp $

PR pkg/48553

--- src/plugins/platforminputcontexts/compose/compose.pro.orig	2014-09-11 10:48:06.000000000 +0000
+++ src/plugins/platforminputcontexts/compose/compose.pro
@@ -16,6 +16,8 @@ SOURCES += $$PWD/main.cpp \
 HEADERS += $$PWD/qcomposeplatforminputcontext.h \
            $$PWD/generator/qtablegenerator.h \
 
+DEFINES += X11BASE=\\\"$$(X11BASE)\\\"
+
 # libxkbcommon
 contains(QT_CONFIG, xkbcommon-qt): {
     # dont't need x11 dependency for compose key plugin
