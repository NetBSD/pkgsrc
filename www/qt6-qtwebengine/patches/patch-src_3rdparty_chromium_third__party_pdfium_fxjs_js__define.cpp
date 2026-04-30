$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_fxjs_js__define.cpp,v 1.1 2026/04/30 06:39:44 adam Exp $

Fix build: error: 'isfinite' was not declared in this scope.

--- src/3rdparty/chromium/third_party/pdfium/fxjs/js_define.cpp.orig	2026-04-29 16:47:11.805638499 +0000
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/js_define.cpp
@@ -59,7 +59,7 @@ double JS_DateParse(v8::Isolate* pIsolate, const WideS
   }
 
   double date = value.As<v8::Number>()->Value();
-  return isfinite(date) ? FX_LocalTime(date) : date;
+  return std::isfinite(date) ? FX_LocalTime(date) : date;
 }
 
 v8::LocalVector<v8::Value> ExpandKeywordParams(
