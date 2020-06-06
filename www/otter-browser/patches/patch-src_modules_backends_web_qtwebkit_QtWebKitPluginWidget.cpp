$NetBSD: patch-src_modules_backends_web_qtwebkit_QtWebKitPluginWidget.cpp,v 1.1 2020/06/06 01:52:00 gutteridge Exp $

Fix build with Qt5 >= 5.15.

--- src/modules/backends/web/qtwebkit/QtWebKitPluginWidget.cpp.orig	2019-01-01 16:59:01.000000000 +0000
+++ src/modules/backends/web/qtwebkit/QtWebKitPluginWidget.cpp
@@ -22,6 +22,7 @@
 
 #include <QtGui/QMouseEvent>
 #include <QtGui/QPainter>
+#include <QtGui/QPainterPath>
 
 namespace Otter
 {
