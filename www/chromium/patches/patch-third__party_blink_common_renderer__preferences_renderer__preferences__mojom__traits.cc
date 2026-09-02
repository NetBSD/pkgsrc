$NetBSD: patch-third__party_blink_common_renderer__preferences_renderer__preferences__mojom__traits.cc,v 1.25 2026/09/02 13:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -47,7 +47,7 @@ bool StructTraits<blink::mojom::Renderer
 
   out->use_custom_colors = data.use_custom_colors();
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   out->use_overlay_scrollbar = data.use_overlay_scrollbar();
 #endif
 
@@ -78,7 +78,7 @@ bool StructTraits<blink::mojom::Renderer
 
   out->send_subresource_notification = data.send_subresource_notification();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
@@ -108,7 +108,7 @@ bool StructTraits<blink::mojom::Renderer
   out->selection_clipboard_buffer_available =
       data.selection_clipboard_buffer_available();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   out->middle_click_paste_allowed = data.middle_click_paste_allowed();
 #endif
   out->plugin_fullscreen_allowed = data.plugin_fullscreen_allowed();
