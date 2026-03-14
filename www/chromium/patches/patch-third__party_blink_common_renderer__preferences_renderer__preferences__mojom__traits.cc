$NetBSD: patch-third__party_blink_common_renderer__preferences_renderer__preferences__mojom__traits.cc,v 1.16 2026/03/14 12:40:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -78,7 +78,7 @@ bool StructTraits<blink::mojom::Renderer
 
   out->send_subresource_notification = data.send_subresource_notification();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
@@ -117,7 +117,7 @@ bool StructTraits<blink::mojom::Renderer
   out->selection_clipboard_buffer_available =
       data.selection_clipboard_buffer_available();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   out->middle_click_paste_allowed = data.middle_click_paste_allowed();
 #endif
   out->plugin_fullscreen_allowed = data.plugin_fullscreen_allowed();
