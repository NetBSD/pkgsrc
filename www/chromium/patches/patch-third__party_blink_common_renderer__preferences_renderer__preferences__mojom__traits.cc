$NetBSD: patch-third__party_blink_common_renderer__preferences_renderer__preferences__mojom__traits.cc,v 1.11 2025/12/11 09:13:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -78,7 +78,7 @@ bool StructTraits<blink::mojom::Renderer
 
   out->send_subresource_notification = data.send_subresource_notification();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
