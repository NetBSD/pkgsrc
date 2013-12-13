$NetBSD: patch-qtbase_src_tools_bootstrap_bootstrap.pro,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Create shared library .so file fo libQt5Bootstrap.la.

--- qtbase/src/tools/bootstrap/bootstrap.pro.orig	2013-11-27 01:01:11.000000000 +0000
+++ qtbase/src/tools/bootstrap/bootstrap.pro
@@ -1,4 +1,4 @@
-option(host_build)
+#option(host_build)
 
 TARGET = QtBootstrap
 QT =
