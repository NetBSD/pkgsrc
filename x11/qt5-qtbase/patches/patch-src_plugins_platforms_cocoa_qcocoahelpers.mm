$NetBSD: patch-src_plugins_platforms_cocoa_qcocoahelpers.mm,v 1.1 2017/11/13 17:36:11 minskim Exp $

Fix build error with macOS 10.13 SDK
https://bugreports.qt.io/browse/QTBUG-63401

--- src/plugins/platforms/cocoa/qcocoahelpers.mm.orig	2015-10-13 04:35:27.000000000 +0000
+++ src/plugins/platforms/cocoa/qcocoahelpers.mm
@@ -668,15 +668,8 @@ NSRect qt_mac_flipRect(const QRect &rect
     return NSMakeRect(rect.x(), flippedY, rect.width(), rect.height());
 }
 
-OSStatus qt_mac_drawCGImage(CGContextRef inContext, const CGRect *inBounds, CGImageRef inImage)
+void qt_mac_drawCGImage(CGContextRef inContext, const CGRect *inBounds, CGImageRef inImage)
 {
-    // Verbatim copy if HIViewDrawCGImage (as shown on Carbon-Dev)
-    OSStatus err = noErr;
-
-    require_action(inContext != NULL, InvalidContext, err = paramErr);
-    require_action(inBounds != NULL, InvalidBounds, err = paramErr);
-    require_action(inImage != NULL, InvalidImage, err = paramErr);
-
     CGContextSaveGState( inContext );
     CGContextTranslateCTM (inContext, 0, inBounds->origin.y + CGRectGetMaxY(*inBounds));
     CGContextScaleCTM(inContext, 1, -1);
@@ -684,10 +677,6 @@ OSStatus qt_mac_drawCGImage(CGContextRef
     CGContextDrawImage(inContext, *inBounds, inImage);
 
     CGContextRestoreGState(inContext);
-InvalidImage:
-InvalidBounds:
-InvalidContext:
-        return err;
 }
 
 Qt::MouseButton cocoaButton2QtButton(NSInteger buttonNum)
