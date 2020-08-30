$NetBSD: patch-qwtconfig.pri,v 1.1 2020/08/30 08:05:57 tnn Exp $

Don't hardcode PREFIX.

--- qwtconfig.pri.orig	2019-01-02 17:21:31.556467499 +0100
+++ qwtconfig.pri	2019-10-25 18:51:20.912266571 +0200
@@ -19,7 +19,7 @@
 QWT_INSTALL_PREFIX = $$[QT_INSTALL_PREFIX]
 
 unix {
-    QWT_INSTALL_PREFIX    = /usr/local/qwt-$$QWT_VERSION
+    QWT_INSTALL_PREFIX    = $$(PREFIX)/qwt-$$QWT_VERSION
     # QWT_INSTALL_PREFIX = /usr/local/qwt-$$QWT_VERSION-qt-$$QT_VERSION
 }
 
@@ -42,14 +42,14 @@
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
