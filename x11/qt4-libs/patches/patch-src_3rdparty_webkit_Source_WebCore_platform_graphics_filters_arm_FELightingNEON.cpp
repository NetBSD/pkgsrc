$NetBSD: patch-src_3rdparty_webkit_Source_WebCore_platform_graphics_filters_arm_FELightingNEON.cpp,v 1.1 2015/03/24 14:28:53 joerg Exp $

--- src/3rdparty/webkit/Source/WebCore/platform/graphics/filters/arm/FELightingNEON.cpp.orig	2015-03-18 10:18:46.000000000 +0000
+++ src/3rdparty/webkit/Source/WebCore/platform/graphics/filters/arm/FELightingNEON.cpp
@@ -398,7 +398,7 @@ TOSTRING(neonDrawLighting) ":" NL
     "vmin.f32 " TMP2_D0 ", " TMP2_D0 ", " CONST_ONE_HI_D NL
     "vmul.f32 " TMP3_Q ", " COLOR_Q ", " TMP2_D0 "[1]" NL
     "vcvt.u32.f32 " TMP3_Q ", " TMP3_Q NL
-    "vmov.u32 r2, r3, " TMP3_S0 ", " TMP3_S1 NL
+    "vmov r2, r3, " TMP3_S0 ", " TMP3_S1 NL
     // The color values are stored in-place.
     "strb r2, [" PIXELS_R ", #-11]" NL
     "strb r3, [" PIXELS_R ", #-10]" NL
