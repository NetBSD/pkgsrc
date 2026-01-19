$NetBSD: patch-third__party_blink_renderer_core_dom_tree__scope.h,v 1.7 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/dom/tree_scope.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/core/dom/tree_scope.h
@@ -28,6 +28,7 @@
 #define THIRD_PARTY_BLINK_RENDERER_CORE_DOM_TREE_SCOPE_H_
 
 #include "third_party/blink/renderer/core/core_export.h"
+#include "third_party/blink/renderer/core/css/css_style_sheet.h"
 #include "third_party/blink/renderer/core/dom/tree_ordered_map.h"
 #include "third_party/blink/renderer/core/html/forms/radio_button_group_scope.h"
 #include "third_party/blink/renderer/platform/bindings/exception_state.h"
