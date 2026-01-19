$NetBSD: patch-third__party_blink_public_common_renderer__preferences_renderer__preferences.h,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/public/common/renderer_preferences/renderer_preferences.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences.h
@@ -66,7 +66,7 @@ struct BLINK_COMMON_EXPORT RendererPrefe
   UserAgentOverride user_agent_override;
   std::string accept_languages;
   bool send_subresource_notification{false};
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::string system_font_family_name;
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -88,7 +88,7 @@ struct BLINK_COMMON_EXPORT RendererPrefe
 #if BUILDFLAG(IS_OZONE)
   bool selection_clipboard_buffer_available{false};
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool middle_click_paste_allowed{true};
 #endif
   bool plugin_fullscreen_allowed{true};
