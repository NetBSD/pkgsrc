$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fxcrt_css_cfx__cssdeclaration.cpp,v 1.1 2026/04/30 06:39:44 adam Exp $

Fix build: error: 'isfinite' was not declared in this scope.

--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/css/cfx_cssdeclaration.cpp.orig	2026-04-29 16:42:43.190151583 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/css/cfx_cssdeclaration.cpp
@@ -37,7 +37,7 @@ std::optional<CFX_CSSNumber> ParseCSSNumber(WideString
 
   size_t nUsedLen = 0;
   float value = FXSYS_wcstof(view, &nUsedLen);
-  if (nUsedLen == 0 || !isfinite(value)) {
+  if (nUsedLen == 0 || !std::isfinite(value)) {
     return std::nullopt;
   }
   view = view.Substr(nUsedLen);
