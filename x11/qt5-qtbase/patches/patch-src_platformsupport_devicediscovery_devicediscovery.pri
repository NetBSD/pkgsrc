$NetBSD: patch-src_platformsupport_devicediscovery_devicediscovery.pri,v 1.1 2015/10/26 19:03:59 adam Exp $

Add missing header; required when libQt5PlatformSupport is a shared library.

--- src/platformsupport/devicediscovery/devicediscovery.pri.orig	2015-10-25 19:25:35.000000000 +0000
+++ src/platformsupport/devicediscovery/devicediscovery.pri
@@ -15,4 +15,5 @@ linux {
     }
 } else {
     SOURCES += $$PWD/qdevicediscovery_dummy.cpp
+    HEADERS += $$PWD/qdevicediscovery_dummy_p.h
 }
