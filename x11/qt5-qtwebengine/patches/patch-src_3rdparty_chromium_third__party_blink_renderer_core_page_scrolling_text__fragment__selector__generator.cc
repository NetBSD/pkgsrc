$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_page_scrolling_text__fragment__selector__generator.cc,v 1.1 2024/06/02 11:34:20 markd Exp $

ICU75 fix - from ArchLinux

--- src/3rdparty/chromium/third_party/blink/renderer/core/page/scrolling/text_fragment_selector_generator.cc.orig	2023-05-05 08:39:51.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/page/scrolling/text_fragment_selector_generator.cc
@@ -15,6 +15,7 @@
 #include "third_party/blink/renderer/core/page/scrolling/text_fragment_anchor_metrics.h"
 #include "third_party/blink/renderer/core/page/scrolling/text_fragment_finder.h"
 #include "third_party/blink/renderer/platform/text/text_boundaries.h"
+#include "absl/base/attributes.h"
 
 namespace blink {
 
