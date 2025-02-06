$NetBSD: patch-components_live__caption_caption__util.cc,v 1.1 2025/02/06 09:58:00 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/live_caption/caption_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/live_caption/caption_util.cc
@@ -139,7 +139,7 @@ std::string GetCaptionSettingsUrl() {
   return "chrome://os-settings/audioAndCaptions";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #endif  // BUILDFLAG(IS_LINUX)
 
