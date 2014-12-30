$NetBSD: patch-Source_WebKit_qt_examples_platformplugin_platformplugin.pro,v 1.1 2014/12/30 17:23:48 adam Exp $

* Fix unprivileged build,
  https://bugs.webkit.org/show_bug.cgi?id=117077

--- Source/WebKit/qt/examples/platformplugin/platformplugin.pro.orig	2013-11-27 01:01:40.000000000 +0000
+++ Source/WebKit/qt/examples/platformplugin/platformplugin.pro
@@ -20,7 +20,8 @@ load(mobilityconfig, true)
     }
 }
 
-DESTDIR = $$[QT_INSTALL_PLUGINS]/webkit
+target.path = $$[QT_INSTALL_PLUGINS]/webkit
+INSTALLS += target
 
 SOURCES += \
     WebPlugin.cpp \
