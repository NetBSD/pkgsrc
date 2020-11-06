$NetBSD: patch-Source_WebKit_UIProcess_CoordinatedGraphics_DrawingAreaProxyCoordinatedGraphics.cpp,v 1.1 2020/11/06 22:21:35 leot Exp $

Backport upstream changeset 269325.

[WinCairo/PlayStation] ICU 68.1 no longer exposes FALSE and TRUE
macros by default ​https://bugs.webkit.org/show_bug.cgi?id=218522

--- Source/WebKit/UIProcess/CoordinatedGraphics/DrawingAreaProxyCoordinatedGraphics.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/CoordinatedGraphics/DrawingAreaProxyCoordinatedGraphics.cpp
@@ -402,7 +402,7 @@ DrawingAreaProxyCoordinatedGraphics::Dra
 int DrawingAreaProxyCoordinatedGraphics::DrawingMonitor::webViewDrawCallback(DrawingAreaProxyCoordinatedGraphics::DrawingMonitor* monitor)
 {
     monitor->didDraw();
-    return FALSE;
+    return false;
 }
 
 void DrawingAreaProxyCoordinatedGraphics::DrawingMonitor::start(WTF::Function<void(CallbackBase::Error)>&& callback)
