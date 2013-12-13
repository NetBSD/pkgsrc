$NetBSD: patch-qtdeclarative_src_qmldevtools_qmldevtools.pro,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Create libQtQmlDevTools.so for qttools.

--- qtdeclarative/src/qmldevtools/qmldevtools.pro.orig	2013-11-27 01:02:16.000000000 +0000
+++ qtdeclarative/src/qmldevtools/qmldevtools.pro
@@ -1,7 +1,9 @@
-option(host_build)
 TARGET     = QtQmlDevTools
 QT         = core
-CONFIG += static no_module_headers internal_module
+CONFIG += no_module_headers
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 MODULE_INCLUDES = \
     \$\$QT_MODULE_INCLUDE_BASE \
