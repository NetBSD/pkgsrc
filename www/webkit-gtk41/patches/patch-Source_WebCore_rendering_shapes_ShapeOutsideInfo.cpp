$NetBSD: patch-Source_WebCore_rendering_shapes_ShapeOutsideInfo.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

ShapeOutsideInfo.cpp:140:16: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp.orig	2026-02-23 14:40:55.846298500 +0000
+++ Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp
@@ -257,7 +257,7 @@ Ref<const LayoutShape> makeShapeForShapeOutside(const 
 
     auto logicalMargin = [&] {
         auto shapeMargin = Style::evaluate<LayoutUnit>(style.shapeMargin(), containingBlock.contentBoxLogicalWidth(), Style::ZoomNeeded { }).toFloat();
-        return isnan(shapeMargin) ? 0.0f : shapeMargin;
+        return std::isnan(shapeMargin) ? 0.0f : shapeMargin;
     }();
 
     return WTF::switchOn(shapeOutside,
