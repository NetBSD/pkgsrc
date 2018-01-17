$NetBSD: patch-src_designer_src_plugins_plugins.pro,v 1.1 2018/01/17 19:30:48 markd Exp $

Don't build webkit dependent parts even if webkit detected.

--- src/designer/src/plugins/plugins.pro.orig	2017-06-23 12:03:39.000000000 +0000
+++ src/designer/src/plugins/plugins.pro
@@ -1,6 +1,6 @@
 TEMPLATE = subdirs
 
 # qtHaveModule(opengl): SUBDIRS += tools/view3d
-qtHaveModule(webkitwidgets): SUBDIRS += qwebview
+#qtHaveModule(webkitwidgets): SUBDIRS += qwebview
 win32: qtHaveModule(axcontainer): SUBDIRS += activeqt
 qtHaveModule(quickwidgets): SUBDIRS += qquickwidget
