$NetBSD: patch-Source_WebCore_rendering_RenderBox.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

RenderBox.h:701:85: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/RenderBox.h.orig	2025-08-08 09:17:55.528471200 +0000
+++ Source/WebCore/rendering/RenderBox.h
@@ -706,7 +706,7 @@ protected:
 
     void computePreferredLogicalWidths(const Style::MinimumSize& minLogicalWidth, const Style::MaximumSize& maxLogicalWidth, LayoutUnit borderAndPaddingLogicalWidth);
 
-    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || isnan(aspectRatio); }
+    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || std::isnan(aspectRatio); }
 
     bool overflowChangesMayAffectLayout() const final;
 
