$NetBSD: patch-Source_WebCore_platform_graphics_filters_arm_FELightingNEON.cpp,v 1.1 2015/03/24 14:30:29 joerg Exp $

--- Source/WebCore/platform/graphics/filters/arm/FELightingNEON.cpp.orig	2012-11-23 20:12:17.000000000 +0000
+++ Source/WebCore/platform/graphics/filters/arm/FELightingNEON.cpp
@@ -404,7 +404,7 @@ TOSTRING(neonDrawLighting) ":" NL
     "vmin.f32 " TMP2_D0 ", " TMP2_D0 ", " CONST_ONE_HI_D NL
     "vmul.f32 " TMP3_Q ", " COLOR_Q ", " TMP2_D0 "[1]" NL
     "vcvt.u32.f32 " TMP3_Q ", " TMP3_Q NL
-    "vmov.u32 r2, r3, " TMP3_S0 ", " TMP3_S1 NL
+    "vmov r2, r3, " TMP3_S0 ", " TMP3_S1 NL
     // The color values are stored in-place.
     "strb r2, [" PIXELS_R ", #-11]" NL
     "strb r3, [" PIXELS_R ", #-10]" NL
