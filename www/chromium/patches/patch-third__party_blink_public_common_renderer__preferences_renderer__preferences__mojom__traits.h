$NetBSD: patch-third__party_blink_public_common_renderer__preferences_renderer__preferences__mojom__traits.h,v 1.2 2025/05/16 16:08:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2025-05-05 19:21:24.000000000 +0000
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -180,7 +180,7 @@ struct BLINK_COMMON_EXPORT
     return data.send_subresource_notification;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
