$NetBSD: patch-src_3rdparty_chromium_components_live__caption_caption__util.cc,v 1.1 2025/12/21 09:38:22 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/live_caption/caption_util.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/live_caption/caption_util.cc
@@ -136,7 +136,7 @@ bool IsLiveCaptionFeatureSupported() {
 std::string GetCaptionSettingsUrl() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chrome://os-settings/audioAndCaptions";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #elif BUILDFLAG(IS_WIN)
   return base::win::GetVersion() >= base::win::Version::WIN10
