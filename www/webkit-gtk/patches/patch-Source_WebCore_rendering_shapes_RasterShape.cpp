$NetBSD: patch-Source_WebCore_rendering_shapes_RasterShape.cpp,v 1.1 2017/04/13 16:58:14 jperkin Exp $

Avoid ambiguous function call.

--- Source/WebCore/rendering/shapes/RasterShape.cpp.orig	2016-04-11 06:18:44.000000000 +0000
+++ Source/WebCore/rendering/shapes/RasterShape.cpp
@@ -142,7 +142,7 @@ const RasterShapeIntervals& RasterShape:
         return *m_intervals;
 
     int shapeMarginInt = clampToPositiveInteger(ceil(shapeMargin()));
-    int maxShapeMarginInt = std::max(m_marginRectSize.width(), m_marginRectSize.height()) * sqrt(2);
+    int maxShapeMarginInt = std::max(m_marginRectSize.width(), m_marginRectSize.height()) * sqrt((double)2);
     if (!m_marginIntervals)
         m_marginIntervals = m_intervals->computeShapeMarginIntervals(std::min(shapeMarginInt, maxShapeMarginInt));
 
