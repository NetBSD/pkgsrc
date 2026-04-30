$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_fxjs_cjs__runtime.cpp,v 1.1 2026/04/30 06:39:44 adam Exp $

Fix build: error: 'isnan' was not declared in this scope.

--- src/3rdparty/chromium/third_party/pdfium/fxjs/cjs_runtime.cpp.orig	2026-04-29 16:46:05.607378958 +0000
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/cjs_runtime.cpp
@@ -236,7 +236,7 @@ v8::Local<v8::Value> CJS_Runtime::MaybeCoerceToNumber(
   }
 
   v8::Local<v8::Number> num = maybeNum.ToLocalChecked();
-  if (isnan(num->Value()) && !bAllowNaN) {
+  if (std::isnan(num->Value()) && !bAllowNaN) {
     return value;
   }
 
