$NetBSD: patch-components_live__caption_caption__util.h,v 1.5 2025/08/13 07:44:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/live_caption/caption_util.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/live_caption/caption_util.h
@@ -15,7 +15,7 @@ class PrefService;
 namespace captions {
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kCaptionSettingsUrl[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
