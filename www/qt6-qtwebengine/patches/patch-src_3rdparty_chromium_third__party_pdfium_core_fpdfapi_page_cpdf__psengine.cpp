$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fpdfapi_page_cpdf__psengine.cpp,v 1.2 2026/04/30 06:39:44 adam Exp $

--- src/3rdparty/chromium/third_party/pdfium/core/fpdfapi/page/cpdf_psengine.cpp.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fpdfapi/page/cpdf_psengine.cpp
@@ -75,7 +75,7 @@ constexpr PDF_PSOpName kPsOpNames[] = {
 // Round half up is a nearest integer round with half-way numbers always rounded
 // up. Example: -5.5 rounds to -5.
 float RoundHalfUp(float f) {
-  if (isnan(f)) {
+  if (std::isnan(f)) {
     return 0;
   }
   if (f > std::numeric_limits<float>::max() - 0.5f) {
