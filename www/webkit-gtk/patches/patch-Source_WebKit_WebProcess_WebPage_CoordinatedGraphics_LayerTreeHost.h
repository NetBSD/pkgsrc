$NetBSD: patch-Source_WebKit_WebProcess_WebPage_CoordinatedGraphics_LayerTreeHost.h,v 1.1 2019/12/14 15:09:42 leot Exp $

Remove unused definition.

Fixes the build when `opengl' option is disabled.

--- Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/LayerTreeHost.h.orig	2019-11-06 08:09:11.000000000 +0000
+++ Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/LayerTreeHost.h
@@ -212,7 +212,6 @@ inline void LayerTreeHost::scheduleLayer
 inline void LayerTreeHost::cancelPendingLayerFlush() { }
 inline void LayerTreeHost::setRootCompositingLayer(WebCore::GraphicsLayer*) { }
 inline void LayerTreeHost::setViewOverlayRootLayer(WebCore::GraphicsLayer*) { }
-inline void LayerTreeHost::invalidate() { }
 inline void LayerTreeHost::scrollNonCompositedContents(const WebCore::IntRect&) { }
 inline void LayerTreeHost::forceRepaint() { }
 inline bool LayerTreeHost::forceRepaintAsync(CallbackID) { return false; }
