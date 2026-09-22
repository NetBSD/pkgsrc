$NetBSD: patch-Source_WebCore_rendering_RenderBox.h,v 1.2 2026/09/22 12:27:03 wiz Exp $

RenderBox.h:701:85: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/RenderBox.h.orig	2026-07-27 08:28:18.880559400 +0000
+++ Source/WebCore/rendering/RenderBox.h
@@ -661,7 +661,7 @@ class RenderBox : public RenderBoxModelObject { (prote
 
     void constrainIntrinsicLogicalWidthsByMinMax(LayoutUnit& minIntrinsicLogicalWidth, LayoutUnit& maxIntrinsicLogicalWidth) const;
 
-    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || isnan(aspectRatio); }
+    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || std::isnan(aspectRatio); }
 
     LayoutUnit fillAvailableMeasure(LayoutUnit availableLogicalWidth) const;
     LayoutUnit fillAvailableMeasure(LayoutUnit availableLogicalWidth, LayoutUnit& marginStart, LayoutUnit& marginEnd) const;
