$NetBSD: patch-Source_WebCore_platform_graphics_cpu_arm_filters_FELightingNEON.cpp,v 1.2 2020/03/21 19:42:37 nia Exp $

Use unified syntax on ARM.

--- Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp.orig	2014-12-05 16:24:49.000000000 +0000
+++ Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp
@@ -404,7 +404,7 @@ TOSTRING(neonDrawLighting) ":" NL
     "vmin.f32 " TMP2_D0 ", " TMP2_D0 ", " CONST_ONE_HI_D NL
     "vmul.f32 " TMP3_Q ", " COLOR_Q ", " TMP2_D0 "[1]" NL
     "vcvt.u32.f32 " TMP3_Q ", " TMP3_Q NL
-    "vmov.u32 r2, r3, " TMP3_S0 ", " TMP3_S1 NL
+    "vmov r2, r3, " TMP3_S0 ", " TMP3_S1 NL
     // The color values are stored in-place.
     "strb r2, [" PIXELS_R ", #-11]" NL
     "strb r3, [" PIXELS_R ", #-10]" NL
