$NetBSD: patch-qwtconfig.pri,v 1.2 2020/08/30 08:19:06 tnn Exp $

Don't hardcode PREFIX.
Ship the pkg-config file. Needed by gnuradio-qtgui.

--- qwtconfig.pri.orig	2020-06-01 16:48:07.325112226 +0000
+++ qwtconfig.pri
@@ -19,7 +19,7 @@ QWT_VERSION      = $${QWT_VER_MAJ}.$${QW
 QWT_INSTALL_PREFIX = $$[QT_INSTALL_PREFIX]
 
 unix {
-    QWT_INSTALL_PREFIX    = /usr/local/qwt-$$QWT_VERSION
+    QWT_INSTALL_PREFIX    = $$(PREFIX)/qwt-$$QWT_VERSION
     # QWT_INSTALL_PREFIX = /usr/local/qwt-$$QWT_VERSION-qt-$$QT_VERSION
 }
 
@@ -42,14 +42,14 @@ QWT_INSTALL_LIBS      = $${QWT_INSTALL_P
 # runtime environment of designer/creator.
 ######################################################################
 
-QWT_INSTALL_PLUGINS   = $${QWT_INSTALL_PREFIX}/plugins/designer
+#QWT_INSTALL_PLUGINS   = $${QWT_INSTALL_PREFIX}/plugins/designer
 
 # linux distributors often organize the Qt installation
 # their way and QT_INSTALL_PREFIX doesn't offer a good
 # path. Also QT_INSTALL_PREFIX is only one of the default
 # search paths of the designer - not the Qt creator
 
-#QWT_INSTALL_PLUGINS   = $$[QT_INSTALL_PREFIX]/plugins/designer
+QWT_INSTALL_PLUGINS   = $$[QT_INSTALL_PREFIX]/plugins/designer
 
 ######################################################################
 # Features
@@ -171,5 +171,5 @@ macx:!static:CONFIG(qt_framework, qt_fra
 
 unix {
 
-    #QWT_CONFIG     += QwtPkgConfig
+    QWT_CONFIG     += QwtPkgConfig
 }
