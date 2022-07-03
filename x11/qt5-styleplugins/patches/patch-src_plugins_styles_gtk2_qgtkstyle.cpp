$NetBSD: patch-src_plugins_styles_gtk2_qgtkstyle.cpp,v 1.1 2022/07/03 20:43:53 pin Exp $

Fix setting background palette

--- src/plugins/styles/gtk2/qgtkstyle.cpp.orig	2017-03-11 09:23:02.000000000 +0000
+++ src/plugins/styles/gtk2/qgtkstyle.cpp
@@ -440,7 +440,11 @@ void QGtkStyle::polish(QApplication *app
     // not supported as these should be entirely determined by
     // current Gtk settings
     if (app->desktopSettingsAware() && d->isThemeAvailable()) {
+    #if QT_VERSION < QT_VERSION_CHECK(5, 15, 0)
         QApplicationPrivate::setSystemPalette(standardPalette());
+    #else
+        QApplication::setPalette(standardPalette());
+    #endif
         QApplicationPrivate::setSystemFont(d->getThemeFont());
         d->applyCustomPaletteHash();
         if (!d->isKDE4Session())
