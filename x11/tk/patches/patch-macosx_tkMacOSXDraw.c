$NetBSD: patch-macosx_tkMacOSXDraw.c,v 1.3 2014/01/11 14:41:06 adam Exp $

Fix OS X screen refresh problem.

--- macosx/tkMacOSXDraw.c.orig	2014-01-11 12:56:24.000000000 +0000
+++ macosx/tkMacOSXDraw.c
@@ -1690,6 +1690,7 @@ TkMacOSXRestoreDrawingContext(
 {
     if (dcPtr->context) {
 	CGContextSynchronize(dcPtr->context);
+	[[dcPtr->view window] setViewsNeedDisplay:YES];
 	[[dcPtr->view window] enableFlushWindow];
 	if (dcPtr->focusLocked) {
 	    [dcPtr->view unlockFocus];
