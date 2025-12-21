$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_streams_queue__with__sizes.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/core/streams/queue_with_sizes.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/streams/queue_with_sizes.cc
@@ -15,7 +15,7 @@ namespace {
 
 // https://streams.spec.whatwg.org/#is-finite-non-negative-number
 bool IsFiniteNonNegativeNumber(double v) {
-  return isfinite(v) && v >= 0;
+  return std::isfinite(v) && v >= 0;
 }
 
 }  // namespace
