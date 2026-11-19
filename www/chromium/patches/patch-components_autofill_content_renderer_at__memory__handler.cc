$NetBSD: patch-components_autofill_content_renderer_at__memory__handler.cc,v 1.8 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/content/renderer/at_memory_handler.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/autofill/content/renderer/at_memory_handler.cc
@@ -66,7 +66,7 @@ bool IsPrintable(const WebKeyboardEvent&
   if (base::IsAsciiControl(event.text[0]) || event.text[1] != 0) {
     return false;
   }
-  if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) {
+  if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) {
     // On Linux and Windows, Alt+X is not printable.
     return !(event.GetModifiers() & blink::WebInputEvent::kAltKey);
   }
