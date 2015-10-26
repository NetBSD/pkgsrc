$NetBSD: patch-src_tools_bootstrap_bootstrap.pro,v 1.2 2015/10/26 19:03:59 adam Exp $

* Create shared library .so file libQt5Bootstrap.la.

--- src/tools/bootstrap/bootstrap.pro.orig	2015-07-27 10:28:43.000000000 +0000
+++ src/tools/bootstrap/bootstrap.pro
@@ -1,4 +1,4 @@
-option(host_build)
+#option(host_build)
 
 TARGET = QtBootstrap
 QT =
