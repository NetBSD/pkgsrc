$NetBSD: patch-components_live__caption_caption__util.cc,v 1.9 2025/11/04 14:55:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/live_caption/caption_util.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ components/live_caption/caption_util.cc
@@ -139,7 +139,7 @@ bool IsHeadlessCaptionFeatureSupported()
 std::string GetCaptionSettingsUrl() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chrome://os-settings/audioAndCaptions";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #elif BUILDFLAG(IS_WIN)
   return base::win::GetVersion() >= base::win::Version::WIN10
