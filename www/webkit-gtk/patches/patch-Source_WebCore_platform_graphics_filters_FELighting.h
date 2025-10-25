$NetBSD: patch-Source_WebCore_platform_graphics_filters_FELighting.h,v 1.1 2025/10/25 14:45:27 tsutsui Exp $

- add forward declaration for ARM_NEON && !ENABLE_UNIFIED_BUILDS case

--- Source/WebCore/platform/graphics/filters/FELighting.h.orig	2025-10-25 02:54:05.885956119 +0000
+++ Source/WebCore/platform/graphics/filters/FELighting.h
@@ -35,6 +35,7 @@
 
 namespace WebCore {
 
+struct LightingData;
 struct FELightingPaintingDataForNeon;
 
 class FELighting : public FilterEffect {
