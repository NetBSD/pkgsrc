$NetBSD: patch-third__party_blink_renderer_core_dom_tree__scope.h,v 1.1 2025/10/16 19:43:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/dom/tree_scope.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ third_party/blink/renderer/core/dom/tree_scope.h
@@ -29,6 +29,7 @@
 
 #include "third_party/blink/renderer/bindings/core/v8/v8_observable_array_css_style_sheet.h"
 #include "third_party/blink/renderer/core/core_export.h"
+#include "third_party/blink/renderer/core/css/css_style_sheet.h"
 #include "third_party/blink/renderer/core/dom/tree_ordered_map.h"
 #include "third_party/blink/renderer/core/html/forms/radio_button_group_scope.h"
 #include "third_party/blink/renderer/core/layout/hit_test_request.h"
