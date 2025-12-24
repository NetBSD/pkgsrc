$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_css_css__unresolved__color__value.cc,v 1.1 2025/12/24 15:58:52 wiz Exp $

In file included from gen/third_party/blink/renderer/core/core_jumbo_30.cc:17:
./../../../3rdparty/chromium/third_party/blink/renderer/core/css/css_unresolved_color_value.cc: In function 'double blink::cssvalue::ClampChannel(double)':
./../../../3rdparty/chromium/third_party/blink/renderer/core/css/css_unresolved_color_value.cc:21:8: error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?
   21 |   if (!isfinite(val)) {
      |        ^~~~~~~~
      |        std::isfinite

--- src/3rdparty/chromium/third_party/blink/renderer/core/css/css_unresolved_color_value.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/css/css_unresolved_color_value.cc
@@ -16,7 +16,7 @@ namespace blink::cssvalue {
 
 // Same clamping as in ColorFunctionParser::MakePerColorSpaceAdjustments().
 static double ClampChannel(double val) {
-  if (!isfinite(val)) {
+  if (!std::isfinite(val)) {
     return val > 0 ? 255.0 : 0;
   } else {
     return ClampTo<double>(val, 0.0, 255.0);
