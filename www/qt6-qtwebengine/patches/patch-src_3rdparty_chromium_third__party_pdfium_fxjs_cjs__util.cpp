$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_fxjs_cjs__util.cpp,v 1.1 2026/04/30 06:39:44 adam Exp $

Fix build: error: 'isnan' was not declared in this scope.

--- src/3rdparty/chromium/third_party/pdfium/fxjs/cjs_util.cpp.orig	2026-04-29 16:44:38.012543833 +0000
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/cjs_util.cpp
@@ -177,7 +177,7 @@ CJS_Result CJS_Util::printd(CJS_Runtime* pRuntime,
   }
 
   v8::Local<v8::Date> v8_date = params[1].As<v8::Date>();
-  if (v8_date.IsEmpty() || isnan(pRuntime->ToDouble(v8_date))) {
+  if (v8_date.IsEmpty() || std::isnan(pRuntime->ToDouble(v8_date))) {
     return CJS_Result::Failure(JSMessage::kSecondParamInvalidDateError);
   }
 
@@ -393,7 +393,7 @@ CJS_Result CJS_Util::scand(CJS_Runtime* pRuntime,
     dDate = CJS_PublicMethods::ParseDateUsingFormat(pRuntime->GetIsolate(),
                                                     sDate, sFormat, nullptr);
   }
-  if (isnan(dDate)) {
+  if (std::isnan(dDate)) {
     return CJS_Result::Success(pRuntime->NewUndefined());
   }
 
