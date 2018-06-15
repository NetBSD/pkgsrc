$NetBSD: patch-Source_WebCore_platform_graphics_filters_FEMorphology.cpp,v 1.1 2018/06/15 09:17:02 jperkin Exp $

Avoid ambiguous function call.

--- Source/WebCore/platform/graphics/filters/FEMorphology.cpp.orig	2018-02-19 11:04:38.000000000 +0000
+++ Source/WebCore/platform/graphics/filters/FEMorphology.cpp
@@ -32,6 +32,8 @@
 #include <wtf/Vector.h>
 #include <wtf/text/TextStream.h>
 
+using std::sqrt;
+
 namespace WebCore {
 
 FEMorphology::FEMorphology(Filter& filter, MorphologyOperatorType type, float radiusX, float radiusY)
