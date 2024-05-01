$NetBSD: patch-qwtconfig.pri,v 1.3 2024/05/01 12:45:32 adam Exp $

Don't hardcode PREFIX.

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
