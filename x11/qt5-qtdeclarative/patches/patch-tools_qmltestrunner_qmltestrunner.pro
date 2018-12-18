$NetBSD: patch-tools_qmltestrunner_qmltestrunner.pro,v 1.2 2018/12/18 09:57:18 adam Exp $

Add missing dependency to fix build.

--- tools/qmltestrunner/qmltestrunner.pro.orig	2018-09-11 11:45:18.000000000 +0000
+++ tools/qmltestrunner/qmltestrunner.pro
@@ -1,6 +1,6 @@
 SOURCES += main.cpp
 
-QT += qml qmltest
+QT += qml qmltest quick
 CONFIG += no_import_scan
 
 QMAKE_TARGET_DESCRIPTION = QML Test Runner
