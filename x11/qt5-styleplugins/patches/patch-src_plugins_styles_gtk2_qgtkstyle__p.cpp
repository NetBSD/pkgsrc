$NetBSD: patch-src_plugins_styles_gtk2_qgtkstyle__p.cpp,v 1.1 2022/07/03 20:43:53 pin Exp $

Fix build against Qt 5.15

--- src/plugins/styles/gtk2/qgtkstyle_p.cpp.orig	2017-03-11 09:23:02.000000000 +0000
+++ src/plugins/styles/gtk2/qgtkstyle_p.cpp
@@ -508,7 +508,9 @@ void QGtkStyleUpdateScheduler::updateThe
       if (oldTheme != QGtkStylePrivate::getThemeName()) {
           oldTheme = QGtkStylePrivate::getThemeName();
           QPalette newPalette = qApp->style()->standardPalette();
+      #if QT_VERSION < QT_VERSION_CHECK(5, 15, 0)
           QApplicationPrivate::setSystemPalette(newPalette);
+      #endif
           QApplication::setPalette(newPalette);
           if (!QGtkStylePrivate::instances.isEmpty()) {
               QGtkStylePrivate::instances.last()->initGtkWidgets();
