$NetBSD: patch-src_plugins_platforms_cocoa_qcocoahelpers.h,v 1.1 2017/11/13 17:36:11 minskim Exp $

Fix build error with macOS 10.13 SDK
https://bugreports.qt.io/browse/QTBUG-63401

--- src/plugins/platforms/cocoa/qcocoahelpers.h.orig	2015-10-13 04:35:27.000000000 +0000
+++ src/plugins/platforms/cocoa/qcocoahelpers.h
@@ -78,7 +78,7 @@ QColor qt_mac_toQColor(CGColorRef color)
 // Creates a mutable shape, it's the caller's responsibility to release.
 HIMutableShapeRef qt_mac_QRegionToHIMutableShape(const QRegion &region);
 
-OSStatus qt_mac_drawCGImage(CGContextRef inContext, const CGRect *inBounds, CGImageRef inImage);
+void qt_mac_drawCGImage(CGContextRef inContext, const CGRect *inBounds, CGImageRef inImage);
 
 QChar qt_mac_qtKey2CocoaKey(Qt::Key key);
 Qt::Key qt_mac_cocoaKey2QtKey(QChar keyCode);
