$NetBSD: patch-src_plugins_platforminputcontexts_compose_compose.pro,v 1.2 2018/01/17 19:30:47 markd Exp $

PR pkg/48553

--- src/plugins/platforminputcontexts/compose/compose.pro.orig	2017-05-26 12:43:31.000000000 +0000
+++ src/plugins/platforminputcontexts/compose/compose.pro
@@ -9,6 +9,8 @@ SOURCES += $$PWD/qcomposeplatforminputco
 HEADERS += $$PWD/qcomposeplatforminputcontext.h \
            $$PWD/generator/qtablegenerator.h \
 
+DEFINES += X11BASE=\\\"$$(X11BASE)\\\"
+
 # libxkbcommon
 !qtConfig(xkbcommon-system) {
     include(../../../3rdparty/xkbcommon.pri)
