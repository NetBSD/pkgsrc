$NetBSD: patch-third__party_blink_public_common_renderer__preferences_renderer__preferences.h,v 1.1 2025/02/06 09:58:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/public/common/renderer_preferences/renderer_preferences.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences.h
@@ -65,7 +65,7 @@ struct BLINK_COMMON_EXPORT RendererPrefe
   UserAgentOverride user_agent_override;
   std::string accept_languages;
   bool send_subresource_notification{false};
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::string system_font_family_name;
 #endif
 #if BUILDFLAG(IS_WIN)
