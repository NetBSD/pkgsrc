$NetBSD: patch-src_platformsupport_platformsupport.pro,v 1.3 2019/08/09 17:41:39 adam Exp $

Fix building xkbcommon when other libraries are not available.

--- src/platformsupport/platformsupport.pro.orig	2019-08-08 18:28:51.325203043 +0000
+++ src/platformsupport/platformsupport.pro
@@ -11,7 +11,7 @@ SUBDIRS = \
 qtConfig(freetype)|darwin|win32: \
     SUBDIRS += fontdatabases
 
-qtConfig(evdev)|qtConfig(tslib)|qtConfig(libinput)|qtConfig(integrityhid) {
+qtConfig(evdev)|qtConfig(tslib)|qtConfig(libinput)|qtConfig(integrityhid)|qtConfig(xkbcommon) {
     SUBDIRS += input
     input.depends += devicediscovery
 }
