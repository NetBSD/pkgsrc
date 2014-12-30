$NetBSD: patch-src_platformsupport_platformsupport.pro,v 1.1 2014/12/30 17:23:46 adam Exp $

* Libtoolized and make it shared library

--- src/platformsupport/platformsupport.pro.orig	2013-11-27 01:01:11.000000000 +0000
+++ src/platformsupport/platformsupport.pro
@@ -1,7 +1,7 @@
 TARGET     = QtPlatformSupport
 QT         = core-private gui-private
 
-CONFIG += static internal_module
+CONFIG += internal_module
 mac:LIBS_PRIVATE += -lz
 
 DEFINES += QT_NO_CAST_FROM_ASCII
