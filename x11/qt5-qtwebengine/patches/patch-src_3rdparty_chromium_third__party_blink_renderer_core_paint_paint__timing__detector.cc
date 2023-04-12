$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_paint_paint__timing__detector.cc,v 1.1 2023/04/12 19:24:06 adam Exp $

https://github.com/macports/macports-ports/pull/16605

--- src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_timing_detector.cc.orig	2023-04-11 15:18:45.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_timing_detector.cc
@@ -320,7 +320,12 @@ FloatRect PaintTimingDetector::BlinkSpac
   // May be nullptr in tests.
   if (!widget)
     return float_rect;
+#ifdef __APPLE__
+  CGRect r = float_rect;
+  return FloatRect(widget->BlinkSpaceToDIPs(gfx::RectF(r)));
+#else
   return FloatRect(widget->BlinkSpaceToDIPs(gfx::RectF(float_rect)));
+#endif
 }
 
 FloatRect PaintTimingDetector::CalculateVisualRect(
