$NetBSD: patch-Source_WebCore_rendering_shapes_ShapeOutsideInfo.cpp,v 1.1 2021/03/30 12:47:42 leot Exp $

Properly calls std::isnan()

--- Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp.orig	2021-02-26 09:57:14.000000000 +0000
+++ Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp
@@ -172,7 +172,7 @@ const Shape& ShapeOutsideInfo::computedS
     WritingMode writingMode = containingBlockStyle.writingMode();
     auto margin = [&] {
         auto shapeMargin = floatValueForLength(m_renderer.style().shapeMargin(), m_renderer.containingBlock() ? m_renderer.containingBlock()->contentWidth() : 0_lu);
-        return isnan(shapeMargin) ? 0.0f : shapeMargin;
+        return std::isnan(shapeMargin) ? 0.0f : shapeMargin;
     }();
     float shapeImageThreshold = style.shapeImageThreshold();
     const ShapeValue& shapeValue = *style.shapeOutside();
