$NetBSD: patch-src_obconf-qt.cpp,v 1.1 2024/08/18 07:44:23 pin Exp $

Port to Qt6.

--- src/obconf-qt.cpp.orig	2024-01-14 11:02:54.000000000 +0000
+++ src/obconf-qt.cpp
@@ -24,7 +24,6 @@
 #include <QTranslator>
 #include <QLibraryInfo>
 #include <QLocale>
-#include <QX11Info>
 #include <QMessageBox>
 #include "maindialog.h"
 #include <X11/Xlib.h>
@@ -124,7 +123,8 @@ static gboolean get_all(Window win, Atom
   gint ret_size;
   gulong ret_items, bytes_left;
 
-  res = XGetWindowProperty(QX11Info::display(), win, prop, 0l, G_MAXLONG,
+  auto display = qApp->nativeInterface<QNativeInterface::QX11Application>()->display();
+  res = XGetWindowProperty(display, win, prop, 0l, G_MAXLONG,
                            FALSE, type, &ret_type, &ret_size,
                            &ret_items, &bytes_left, &xdata);
 
@@ -163,7 +163,8 @@ static gboolean prop_get_string_utf8(Win
   gchar* str;
   guint num;
 
-  if(get_all(win, prop, XInternAtom(QX11Info::display(), "UTF8_STRING", 0), 8, (guchar**)&raw, &num)) {
+  auto display = qApp->nativeInterface<QNativeInterface::QX11Application>()->display();
+  if(get_all(win, prop, XInternAtom(display, "UTF8_STRING", 0), 8, (guchar**)&raw, &num)) {
     str = g_strndup(raw, num); /* grab the first string from the list */
     g_free(raw);
 
@@ -180,18 +181,19 @@ static gboolean prop_get_string_utf8(Win
 
 int main(int argc, char** argv) {
   QApplication app(argc, argv);
-  app.setAttribute(Qt::AA_UseHighDpiPixmaps, true);
 
   // load translations
   QTranslator qtTranslator, translator;
 
   // install the translations built-into Qt itself
-  qtTranslator.load(QStringLiteral("qt_") + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
-  app.installTranslator(&qtTranslator);
+  if(qtTranslator.load(QStringLiteral("qt_") + QLocale::system().name(), QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
+    app.installTranslator(&qtTranslator);
+  }
 
   // install our own tranlations
-  translator.load(QStringLiteral("obconf-qt_") + QLocale::system().name(), QStringLiteral(PACKAGE_DATA_DIR) + QStringLiteral("/translations"));
-  app.installTranslator(&translator);
+  if(translator.load(QStringLiteral("obconf-qt_") + QLocale::system().name(), QStringLiteral(PACKAGE_DATA_DIR) + QStringLiteral("/translations"))) {
+    app.installTranslator(&translator);
+  }
 
   // load configurations
 
@@ -204,12 +206,17 @@ int main(int argc, char** argv) {
 
   paths = obt_paths_new();
   parse_i = obt_xml_instance_new();
-  int screen = QX11Info::appScreen();
-  rrinst = RrInstanceNew(QX11Info::display(), screen);
+
+  auto x11NativeInterface = qApp->nativeInterface<QNativeInterface::QX11Application>();
+  auto display = x11NativeInterface->display();
+  auto appRootWindow = XDefaultRootWindow(x11NativeInterface->display());
+
+  int screen = DefaultScreen(display);
+  rrinst = RrInstanceNew(display, screen);
   if(!obc_config_file) {
     gchar* p;
-    if(prop_get_string_utf8(QX11Info::appRootWindow(screen),
-                            XInternAtom(QX11Info::display(), "_OB_CONFIG_FILE", 0), &p)) {
+    if(prop_get_string_utf8(appRootWindow,
+                            XInternAtom(display, "_OB_CONFIG_FILE", 0), &p)) {
       obc_config_file = g_filename_from_utf8(p, -1, NULL, NULL, NULL);
       g_free(p);
     }
