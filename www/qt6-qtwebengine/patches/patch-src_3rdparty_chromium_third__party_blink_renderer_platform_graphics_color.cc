$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_graphics_color.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

In platform_jumbo_33.cc <cmath> included before <math.h>

--- src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/color.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/color.cc
@@ -203,7 +203,7 @@ Color Color::FromColorSpace(ColorSpace c
     result.alpha_ = 0.0f;
   }
 
-  if (IsLightnessFirstComponent(color_space) && !isnan(result.param0_)) {
+  if (IsLightnessFirstComponent(color_space) && !std::isnan(result.param0_)) {
     // param0_ is lightness which cannot be negative or above 100%.
     // lab/lch have lightness in the range [0, 100].
     // oklab/okch have lightness in the range [0, 1].
@@ -970,10 +970,10 @@ String Color::ColorSpaceToString(Color::
 
 static String ColorParamToString(float param, int precision = 6) {
   StringBuilder result;
-  if (!isfinite(param)) {
+  if (!std::isfinite(param)) {
     // https://www.w3.org/TR/css-values-4/#calc-serialize
     result.Append("calc(");
-    if (isinf(param)) {
+    if (std::isinf(param)) {
       // "Infinity" gets capitalized, so we can't use AppendNumber().
       (param < 0) ? result.Append("-infinity") : result.Append("infinity");
     } else {
@@ -997,7 +997,7 @@ String Color::SerializeAsCanvasColor() c
 
 String Color::SerializeLegacyColorAsCSSColor() const {
   StringBuilder result;
-  if (IsOpaque() && isfinite(alpha_)) {
+  if (IsOpaque() && std::isfinite(alpha_)) {
     result.Append("rgb(");
   } else {
     result.Append("rgba(");
@@ -1386,10 +1386,10 @@ static float ResolveNonFiniteChannel(flo
                                      float negative_infinity_substitution,
                                      float positive_infinity_substitution) {
   // Finite values should be unchanged, even if they are out-of-gamut.
-  if (isfinite(value)) {
+  if (std::isfinite(value)) {
     return value;
   } else {
-    if (isnan(value)) {
+    if (std::isnan(value)) {
       return 0.0f;
     } else {
       if (value < 0) {
@@ -1415,7 +1415,7 @@ void Color::ResolveNonFiniteValues() {
   }
 
   // Chroma cannot be negative.
-  if (IsChromaSecondComponent(color_space_) && isinf(param1_) &&
+  if (IsChromaSecondComponent(color_space_) && std::isinf(param1_) &&
       param1_ < 0.0f) {
     param1_ = 0.0f;
   }
@@ -1428,9 +1428,9 @@ void Color::ResolveNonFiniteValues() {
   }
 
   // Parsed values are `calc(NaN)` but computed values are 0 for NaN.
-  param0_ = isnan(param0_) ? 0.0f : param0_;
-  param1_ = isnan(param1_) ? 0.0f : param1_;
-  param2_ = isnan(param2_) ? 0.0f : param2_;
+  param0_ = std::isnan(param0_) ? 0.0f : param0_;
+  param1_ = std::isnan(param1_) ? 0.0f : param1_;
+  param2_ = std::isnan(param2_) ? 0.0f : param2_;
   alpha_ = ResolveNonFiniteChannel(alpha_, 0.0f, 1.0f);
 }
 
