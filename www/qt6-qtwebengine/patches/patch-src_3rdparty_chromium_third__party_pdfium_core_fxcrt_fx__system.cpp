$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fxcrt_fx__system.cpp,v 1.1 2026/04/30 06:39:44 adam Exp $

Fix build: error: 'isnan' was not declared in this scope.

--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_system.cpp.orig	2026-04-29 16:40:36.565129416 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_system.cpp
@@ -99,7 +99,7 @@ int FXSYS_roundf(float f) {
 }  // namespace
 
 int FXSYS_roundf(float f) {
-  if (isnan(f)) {
+  if (std::isnan(f)) {
     return 0;
   }
   if (f < static_cast<float>(std::numeric_limits<int>::min())) {
@@ -112,7 +112,7 @@ int FXSYS_round(double d) {
 }
 
 int FXSYS_round(double d) {
-  if (isnan(d)) {
+  if (std::isnan(d)) {
     return 0;
   }
   if (d < static_cast<double>(std::numeric_limits<int>::min())) {
