$NetBSD: patch-src_qmldevtools_qmldevtools.pro,v 1.1 2014/12/30 17:23:46 adam Exp $

* Create libQtQmlDevTools.so for qttools.

--- src/qmldevtools/qmldevtools.pro.orig	2014-09-11 10:48:29.000000000 +0000
+++ src/qmldevtools/qmldevtools.pro
@@ -1,7 +1,8 @@
-option(host_build)
 TARGET     = QtQmlDevTools
 QT         = core
-CONFIG += static no_module_headers internal_module qmldevtools_build
+CONFIG += no_module_headers qmldevtools_build
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 MODULE_INCLUDES = \
     \$\$QT_MODULE_INCLUDE_BASE \
