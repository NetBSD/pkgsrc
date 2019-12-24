$NetBSD: patch-src_plugins_platforms_cocoa_qiosurfacegraphicsbuffer.mm,v 1.1 2019/12/24 06:20:42 dbj Exp $

Fix Darwin build on builds before macosx 10.13

--- src/plugins/platforms/cocoa/qiosurfacegraphicsbuffer.mm.orig	2019-06-13 04:18:18.000000000 +0000
+++ src/plugins/platforms/cocoa/qiosurfacegraphicsbuffer.mm
@@ -45,6 +45,12 @@
 #include <CoreGraphics/CoreGraphics.h>
 #include <IOSurface/IOSurface.h>
 
+// kIOReturnSuccess is only available on 10.13 and above
+// however, IOSurfaceLock has been around longer
+#ifndef kIOSurfaceSuccess
+#define kIOSurfaceSuccess kIOReturnSuccess
+#endif
+
 // CGColorSpaceCopyPropertyList is available on 10.12 and above,
 // but was only added in the 10.14 SDK, so declare it just in case.
 extern "C" CFPropertyListRef CGColorSpaceCopyPropertyList(CGColorSpaceRef space);
