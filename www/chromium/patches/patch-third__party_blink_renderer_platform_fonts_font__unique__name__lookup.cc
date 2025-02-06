$NetBSD: patch-third__party_blink_renderer_platform_fonts_font__unique__name__lookup.cc,v 1.1 2025/02/06 09:58:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc
@@ -9,7 +9,7 @@
 #if BUILDFLAG(IS_ANDROID)
 #include "third_party/blink/public/mojom/font_unique_name_lookup/font_unique_name_lookup.mojom-blink.h"
 #include "third_party/blink/renderer/platform/fonts/android/font_unique_name_lookup_android.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/linux/font_unique_name_lookup_linux.h"
 #elif BUILDFLAG(IS_WIN)
 #include "third_party/blink/renderer/platform/fonts/win/font_unique_name_lookup_win.h"
@@ -24,7 +24,7 @@ std::unique_ptr<FontUniqueNameLookup>
 FontUniqueNameLookup::GetPlatformUniqueNameLookup() {
 #if BUILDFLAG(IS_ANDROID)
   return std::make_unique<FontUniqueNameLookupAndroid>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<FontUniqueNameLookupLinux>();
 #elif BUILDFLAG(IS_WIN)
   return std::make_unique<FontUniqueNameLookupWin>();
