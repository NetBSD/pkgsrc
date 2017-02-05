$NetBSD: patch-gfx_layers_composite_LayerManagerComposite.cpp,v 1.3 2017/02/05 15:41:58 martin Exp $

Backport of upstream commit 
	https://hg.mozilla.org/mozilla-central/rev/c1e18cb7926e

diff gfx/layers/composite/LayerManagerComposite.cpp.orig gfx/layers/composite/LayerManagerComposite.cpp
--- gfx/layers/composite/LayerManagerComposite.cpp.orig	2017-01-16 17:16:50.000000000 +0100
+++ gfx/layers/composite/LayerManagerComposite.cpp	2017-02-05 10:58:20.873600806 +0100
@@ -12,7 +12,6 @@
 #include "CompositableHost.h"           // for CompositableHost
 #include "ContainerLayerComposite.h"    // for ContainerLayerComposite, etc
 #include "FPSCounter.h"                 // for FPSState, FPSCounter
-#include "PaintCounter.h"               // For PaintCounter
 #include "FrameMetrics.h"               // for FrameMetrics
 #include "GeckoProfiler.h"              // for profiler_set_frame_number, etc
 #include "ImageLayerComposite.h"        // for ImageLayerComposite
@@ -72,6 +71,10 @@
 #include "TextRenderer.h"               // for TextRenderer
 #include "mozilla/layers/CompositorBridgeParent.h"
 #include "TreeTraversal.h"              // for ForEachNode
+ 
+#ifdef USE_SKIA
+#include "PaintCounter.h"               // For PaintCounter
+#endif
 
 class gfxContext;
 
@@ -133,6 +136,10 @@ LayerManagerComposite::LayerManagerCompo
 {
   mTextRenderer = new TextRenderer(aCompositor);
   MOZ_ASSERT(aCompositor);
+
+#ifdef USE_SKIA
+  mPaintCounter = nullptr;
+#endif
 }
 
 LayerManagerComposite::~LayerManagerComposite()
@@ -151,8 +158,10 @@ LayerManagerComposite::Destroy()
     }
     mRoot = nullptr;
     mClonedLayerTreeProperties = nullptr;
-    mPaintCounter = nullptr;
     mDestroyed = true;
+#ifdef USE_SKIA
+    mPaintCounter = nullptr;
+#endif
   }
 }
 
@@ -564,7 +573,6 @@ LayerManagerComposite::InvalidateDebugOv
   bool drawFps = gfxPrefs::LayersDrawFPS();
   bool drawFrameCounter = gfxPrefs::DrawFrameCounter();
   bool drawFrameColorBars = gfxPrefs::CompositorDrawColorBars();
-  bool drawPaintTimes = gfxPrefs::AlwaysPaint();
 
   if (drawFps || drawFrameCounter) {
     aInvalidRegion.Or(aInvalidRegion, nsIntRect(0, 0, 256, 256));
@@ -572,11 +580,16 @@ LayerManagerComposite::InvalidateDebugOv
   if (drawFrameColorBars) {
     aInvalidRegion.Or(aInvalidRegion, nsIntRect(0, 0, 10, aBounds.height));
   }
+
+#ifdef USE_SKIA
+  bool drawPaintTimes = gfxPrefs::AlwaysPaint();
   if (drawPaintTimes) {
     aInvalidRegion.Or(aInvalidRegion, nsIntRect(PaintCounter::GetPaintRect()));
   }
+#endif
 }
 
+#ifdef USE_SKIA
 void
 LayerManagerComposite::DrawPaintTimes(Compositor* aCompositor)
 {
@@ -587,6 +600,7 @@ LayerManagerComposite::DrawPaintTimes(Co
   TimeDuration compositeTime = TimeStamp::Now() - mRenderStartTime;
   mPaintCounter->Draw(aCompositor, mLastPaintTime, compositeTime);
 }
+#endif
 
 static uint16_t sFrameCount = 0;
 void
@@ -595,7 +609,6 @@ LayerManagerComposite::RenderDebugOverla
   bool drawFps = gfxPrefs::LayersDrawFPS();
   bool drawFrameCounter = gfxPrefs::DrawFrameCounter();
   bool drawFrameColorBars = gfxPrefs::CompositorDrawColorBars();
-  bool drawPaintTimes = gfxPrefs::AlwaysPaint();
 
   TimeStamp now = TimeStamp::Now();
 
@@ -736,9 +749,12 @@ LayerManagerComposite::RenderDebugOverla
     sFrameCount++;
   }
 
+#ifdef USE_SKIA
+  bool drawPaintTimes = gfxPrefs::AlwaysPaint();
   if (drawPaintTimes) {
     DrawPaintTimes(mCompositor);
   }
+#endif
 }
 
 RefPtr<CompositingRenderTarget>
