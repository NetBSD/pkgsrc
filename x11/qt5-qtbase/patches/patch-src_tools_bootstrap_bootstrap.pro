$NetBSD: patch-src_tools_bootstrap_bootstrap.pro,v 1.1 2014/12/30 17:23:46 adam Exp $

* Create shared library .so file fo libQt5Bootstrap.la.

--- src/tools/bootstrap/bootstrap.pro.orig	2013-11-27 01:01:11.000000000 +0000
+++ src/tools/bootstrap/bootstrap.pro
@@ -1,4 +1,4 @@
-option(host_build)
+#option(host_build)
 
 TARGET = QtBootstrap
 QT =
