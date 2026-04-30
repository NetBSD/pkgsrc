$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_fxjs_cjs__publicmethods.cpp,v 1.2 2026/04/30 06:39:44 adam Exp $

use std::isnan()

--- src/3rdparty/chromium/third_party/pdfium/fxjs/cjs_publicmethods.cpp.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/cjs_publicmethods.cpp
@@ -459,7 +459,7 @@ double CJS_PublicMethods::ParseDateUsing
 
   if (status == fxjs::ConversionStatus::kBadDate) {
     dRet = JS_DateParse(isolate, value);
-    if (!isnan(dRet)) {
+    if (!std::isnan(dRet)) {
       return dRet;
     }
   }
@@ -951,7 +951,7 @@ CJS_Result CJS_PublicMethods::AFDate_For
                                  nullptr);
   }
 
-  if (isnan(dDate)) {
+  if (std::isnan(dDate)) {
     WideString swMsg = WideString::Format(
         JSGetStringFromID(JSMessage::kParseDateError).c_str(), sFormat.c_str());
     AlertIfPossible(pEvent, WideString::FromASCII("AFDate_FormatEx"), swMsg);
@@ -994,7 +994,7 @@ double CJS_PublicMethods::ParseDateAsGMT
   int nYear = StringToFloat(wsArray[7].AsStringView());
   double dRet = FX_MakeDate(FX_MakeDay(nYear, nMonth - 1, nDay),
                             FX_MakeTime(nHour, nMin, nSec, 0));
-  if (isnan(dRet)) {
+  if (std::isnan(dRet)) {
     dRet = JS_DateParse(isolate, strValue);
   }
 
@@ -1028,7 +1028,7 @@ CJS_Result CJS_PublicMethods::AFDate_Key
   WideString sFormat = pRuntime->ToWideString(params[0]);
   double dRet = ParseDateUsingFormat(pRuntime->GetIsolate(), strValue, sFormat,
                                      &bWrongFormat);
-  if (bWrongFormat || isnan(dRet)) {
+  if (bWrongFormat || std::isnan(dRet)) {
     WideString swMsg = WideString::Format(
         JSGetStringFromID(JSMessage::kParseDateError).c_str(), sFormat.c_str());
     AlertIfPossible(pEvent, WideString::FromASCII("AFDate_KeystrokeEx"), swMsg);
@@ -1306,7 +1306,7 @@ CJS_Result CJS_PublicMethods::AFParseDat
   WideString sFormat = pRuntime->ToWideString(params[1]);
   double dDate =
       ParseDateUsingFormat(pRuntime->GetIsolate(), sValue, sFormat, nullptr);
-  if (isnan(dDate)) {
+  if (std::isnan(dDate)) {
     WideString swMsg = WideString::Format(
         JSGetStringFromID(JSMessage::kParseDateError).c_str(), sFormat.c_str());
     AlertIfPossible(pRuntime->GetCurrentEventContext(),
@@ -1326,7 +1326,7 @@ CJS_Result CJS_PublicMethods::AFSimple(
   WideString sFunction = pRuntime->ToWideString(params[0]);
   double arg1 = pRuntime->ToDouble(params[1]);
   double arg2 = pRuntime->ToDouble(params[2]);
-  if (isnan(arg1) || isnan(arg2)) {
+  if (std::isnan(arg1) || std::isnan(arg2)) {
     return CJS_Result::Failure(JSMessage::kValueError);
   }
 
