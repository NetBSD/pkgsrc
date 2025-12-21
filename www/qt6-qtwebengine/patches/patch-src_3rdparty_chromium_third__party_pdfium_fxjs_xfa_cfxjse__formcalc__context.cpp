$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_fxjs_xfa_cfxjse__formcalc__context.cpp,v 1.1 2025/12/21 09:38:43 markd Exp $

--- src/3rdparty/chromium/third_party/pdfium/fxjs/xfa/cfxjse_formcalc_context.cpp.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/xfa/cfxjse_formcalc_context.cpp
@@ -4162,7 +4162,7 @@ void CFXJSE_FormCalcContext::WordNum(
     bsLocale = ValueToUTF8String(info.GetIsolate(), localeValue);
   }
 
-  if (isnan(fNumber) || fNumber < 0.0f || fNumber > 922337203685477550.0f) {
+  if (std::isnan(fNumber) || fNumber < 0.0f || fNumber > 922337203685477550.0f) {
     info.GetReturnValue().Set(fxv8::NewStringHelper(info.GetIsolate(), "*"));
     return;
   }
