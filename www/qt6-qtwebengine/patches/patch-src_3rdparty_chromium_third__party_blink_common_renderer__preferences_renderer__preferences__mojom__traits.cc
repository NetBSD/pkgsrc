$NetBSD: patch-src_3rdparty_chromium_third__party_blink_common_renderer__preferences_renderer__preferences__mojom__traits.cc,v 1.1 2025/12/21 09:38:39 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -68,7 +68,7 @@ bool StructTraits<blink::mojom::Renderer
 
   out->send_subresource_notification = data.send_subresource_notification();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
