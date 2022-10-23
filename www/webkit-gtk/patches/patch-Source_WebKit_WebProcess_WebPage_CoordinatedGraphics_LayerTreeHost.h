$NetBSD: patch-Source_WebKit_WebProcess_WebPage_CoordinatedGraphics_LayerTreeHost.h,v 1.3 2022/10/23 07:33:50 mcf Exp $

Fix build with -opengl.

Upstream: https://commits.webkit.org/254220@main

--- Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/LayerTreeHost.h.orig	Thu Jun 30 09:49:38 2022
+++ Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/LayerTreeHost.h
@@ -37,9 +37,6 @@
 #include <wtf/Forward.h>
 #include <wtf/OptionSet.h>
 #include <wtf/RunLoop.h>
-#if PLATFORM(GTK)
-#include <WebCore/CoordinatedGraphicsLayer.h>
-#endif
 
 #if USE(GRAPHICS_LAYER_TEXTURE_MAPPER)
 
@@ -48,6 +45,7 @@
 #else // USE(GRAPHICS_LAYER_TEXTURE_MAPPER)
 
 namespace WebCore {
+class CoordinatedGraphicsLayer;
 class IntRect;
 class IntSize;
 class GraphicsLayer;
@@ -241,6 +239,10 @@ inline void LayerTreeHost::didChangeViewportAttributes
 inline void LayerTreeHost::setIsDiscardable(bool) { }
 inline void LayerTreeHost::deviceOrPageScaleFactorChanged() { }
 inline RefPtr<WebCore::DisplayRefreshMonitor> LayerTreeHost::createDisplayRefreshMonitor(WebCore::PlatformDisplayID) { return nullptr; }
+#if PLATFORM(GTK)
+inline void LayerTreeHost::adjustTransientZoom(double, WebCore::FloatPoint) { }
+inline void LayerTreeHost::commitTransientZoom(double, WebCore::FloatPoint) { }
+#endif
 #endif
 
 } // namespace WebKit
