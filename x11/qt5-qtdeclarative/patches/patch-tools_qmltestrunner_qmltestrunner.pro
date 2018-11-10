$NetBSD: patch-tools_qmltestrunner_qmltestrunner.pro,v 1.1 2018/11/10 19:33:47 bsiegert Exp $

Add missing dependency to fix build.
--- tools/qmltestrunner/qmltestrunner.pro.orig	2018-09-11 11:45:18.000000000 +0000
+++ tools/qmltestrunner/qmltestrunner.pro
@@ -1,6 +1,6 @@
 SOURCES += main.cpp
 
-QT += qml qmltest
+QT += qml qmltest quick
 CONFIG += no_import_scan
 
 QMAKE_TARGET_DESCRIPTION = QML Test Runner
