$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fxcrt_fx__extension.h,v 1.1 2026/04/30 06:39:44 adam Exp $

Fix build: error: 'isnan' was not declared in this scope.

--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_extension.h.orig	2026-04-29 16:35:41.973748208 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_extension.h
@@ -131,17 +131,17 @@ bool FXSYS_SafeEQ(const T& lhs, const T& rhs) {
 // All NaNs are treated as equal to each other and greater than infinity.
 template <typename T>
 bool FXSYS_SafeEQ(const T& lhs, const T& rhs) {
-  return (isnan(lhs) && isnan(rhs)) ||
-         (!isnan(lhs) && !isnan(rhs) && lhs == rhs);
+  return (std::isnan(lhs) && std::isnan(rhs)) ||
+         (!std::isnan(lhs) && !std::isnan(rhs) && lhs == rhs);
 }
 
 template <typename T>
 bool FXSYS_SafeLT(const T& lhs, const T& rhs) {
-  if (isnan(lhs) && isnan(rhs)) {
+  if (std::isnan(lhs) && std::isnan(rhs)) {
     return false;
   }
-  if (isnan(lhs) || isnan(rhs)) {
-    return isnan(lhs) < isnan(rhs);
+  if (std::isnan(lhs) || std::isnan(rhs)) {
+    return std::isnan(lhs) < std::isnan(rhs);
   }
   return lhs < rhs;
 }
