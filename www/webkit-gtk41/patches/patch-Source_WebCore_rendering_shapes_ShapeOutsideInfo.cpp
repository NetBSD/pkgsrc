$NetBSD: patch-Source_WebCore_rendering_shapes_ShapeOutsideInfo.cpp,v 1.2 2026/09/22 12:27:03 wiz Exp $

ShapeOutsideInfo.cpp:140:16: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp.orig	2026-07-24 08:02:55.428795600 +0000
+++ Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp
@@ -251,7 +251,7 @@ Ref<const LayoutShape> makeShapeForShapeOutside(const 
 
     auto logicalMargin = [&] {
         auto shapeMargin = Style::evaluate<LayoutUnit>(style.shapeMargin(), containingBlock.contentBoxLogicalWidth(), zoom).toFloat();
-        return isnan(shapeMargin) ? 0.0f : shapeMargin;
+        return std::isnan(shapeMargin) ? 0.0f : shapeMargin;
     }();
 
     return WTF::switchOn(shapeOutside,
