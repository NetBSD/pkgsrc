$NetBSD: patch-third__party_blink_renderer_platform_wtf_math__extras.h,v 1.1 2025/02/06 09:58:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/math_extras.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/platform/wtf/math_extras.h
@@ -128,6 +128,10 @@ constexpr float Grad2turn(float g) {
   return g * (1.0f / 400.0f);
 }
 
+#if defined(OS_FREEBSD)
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Winvalid-constexpr"
+#endif
 constexpr double RoundHalfTowardsPositiveInfinity(double value) {
   return std::floor(value + 0.5);
 }
@@ -135,6 +139,9 @@ constexpr double RoundHalfTowardsPositiv
 constexpr float RoundHalfTowardsPositiveInfinity(float value) {
   return std::floor(value + 0.5f);
 }
+#if defined(OS_FREEBSD)
+#pragma clang diagnostic pop
+#endif
 
 // ClampTo() is implemented by templated helper classes (to allow for partial
 // template specialization) as well as several helper functions.
