$NetBSD: patch-src_modules_windows_web_StartPageWidget.cpp,v 1.1 2020/06/06 01:52:00 gutteridge Exp $

Fix build with Qt5 >= 5.15.

--- src/modules/windows/web/StartPageWidget.cpp.orig	2019-01-01 16:59:01.000000000 +0000
+++ src/modules/windows/web/StartPageWidget.cpp
@@ -41,6 +41,7 @@
 #include <QtGui/QGuiApplication>
 #include <QtGui/QMouseEvent>
 #include <QtGui/QPainter>
+#include <QtGui/QPainterPath>
 #include <QtGui/QPixmapCache>
 #include <QtWidgets/QDesktopWidget>
 #include <QtWidgets/QGridLayout>
