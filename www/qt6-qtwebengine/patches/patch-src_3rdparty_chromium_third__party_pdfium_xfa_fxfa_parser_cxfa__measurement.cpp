$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_xfa_fxfa_parser_cxfa__measurement.cpp,v 1.1 2026/04/30 06:39:44 adam Exp $

Fix build: error: 'isfinite' was not declared in this scope.

--- src/3rdparty/chromium/third_party/pdfium/xfa/fxfa/parser/cxfa_measurement.cpp.orig	2026-04-29 16:48:37.889862708 +0000
+++ src/3rdparty/chromium/third_party/pdfium/xfa/fxfa/parser/cxfa_measurement.cpp
@@ -46,7 +46,7 @@ void CXFA_Measurement::SetString(WideStringView wsMeas
 
   size_t nUsedLen = 0;
   float fValue = FXSYS_wcstof(wsMeasure, &nUsedLen);
-  if (!isfinite(fValue)) {
+  if (!std::isfinite(fValue)) {
     fValue = 0.0f;
   }
   Set(fValue, GetUnitFromString(wsMeasure.Substr(nUsedLen)));
