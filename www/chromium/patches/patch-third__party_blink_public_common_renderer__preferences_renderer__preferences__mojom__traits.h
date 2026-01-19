$NetBSD: patch-third__party_blink_public_common_renderer__preferences_renderer__preferences__mojom__traits.h,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -185,7 +185,7 @@ struct BLINK_COMMON_EXPORT
     return data.send_subresource_notification;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
@@ -199,7 +199,7 @@ struct BLINK_COMMON_EXPORT
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool& middle_click_paste_allowed(
       const ::blink::RendererPreferences& data) {
     return data.middle_click_paste_allowed;
