$NetBSD: patch-gfx_layers_composite_LayerManagerComposite.h,v 1.1 2017/02/05 15:41:58 martin Exp $

Backport of upstream commit 
	https://hg.mozilla.org/mozilla-central/rev/c1e18cb7926e

diff gfx/layers/composite/LayerManagerComposite.h.orig gfx/layers/composite/LayerManagerComposite.h
--- gfx/layers/composite/LayerManagerComposite.h.orig	2017-01-16 17:16:50.000000000 +0100
+++ gfx/layers/composite/LayerManagerComposite.h	2017-02-05 11:02:30.218363514 +0100
@@ -331,11 +331,6 @@ private:
 #endif
 
   /**
-   * Render paint and composite times above the frame.
-   */
-  void DrawPaintTimes(Compositor* aCompositor);
-
-  /**
    * We need to know our invalid region before we're ready to render.
    */
   void InvalidateDebugOverlay(nsIntRegion& aInvalidRegion, const gfx::IntRect& aBounds);
@@ -391,9 +386,16 @@ private:
   bool mLastFrameMissedHWC;
 
   bool mWindowOverlayChanged;
-  RefPtr<PaintCounter> mPaintCounter;
   TimeDuration mLastPaintTime;
   TimeStamp mRenderStartTime;
+
+#ifdef USE_SKIA
+  /**
+   * Render paint and composite times above the frame.
+   */
+  void DrawPaintTimes(Compositor* aCompositor);
+  RefPtr<PaintCounter> mPaintCounter;
+#endif
 };
 
 /**

