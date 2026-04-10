$NetBSD: patch-ui_gfx_paint__vector__icon.cc,v 1.2 2026/04/10 17:32:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/paint_vector_icon.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ ui/gfx/paint_vector_icon.cc
@@ -235,7 +235,7 @@ void PaintPath(Canvas* canvas,
         break;
 
       case H_LINE_TO: {
-        const SkPoint last_point = path.getLastPt().value_or({0, 0});
+        const SkPoint last_point = path.getLastPt().value_or(SkPoint{0, 0});
         path.lineTo(arg(0), last_point.fY);
         break;
       }
@@ -245,7 +245,7 @@ void PaintPath(Canvas* canvas,
         break;
 
       case V_LINE_TO: {
-        const SkPoint last_point = path.getLastPt().value_or({0, 0});
+        const SkPoint last_point = path.getLastPt().value_or(SkPoint{0, 0});
         path.lineTo(last_point.fX, arg(0));
         break;
       }
@@ -273,7 +273,7 @@ void PaintPath(Canvas* canvas,
         // details.
         // Note that |x1| and |y1| will correspond to the sole control point if
         // calculating a quadratic curve.
-        const SkPoint last_point = path.getLastPt().value_or({0, 0});
+        const SkPoint last_point = path.getLastPt().value_or(SkPoint{0, 0});
         SkScalar delta_x = 0;
         SkScalar delta_y = 0;
         if (IsCommandTypeCurve(previous_command_type)) {
