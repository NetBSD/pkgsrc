$NetBSD: patch-chrome_browser_glic_host_glic__web__client__handler.cc,v 1.2 2026/11/08 15:38:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/host/glic_web_client_handler.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/glic/host/glic_web_client_handler.cc
@@ -139,7 +139,7 @@ namespace glic {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableGlicAiAvatarRing, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
@@ -1292,7 +1292,7 @@ class GlicWebClientHandler
 #else
     result->local_profile_name =
         base::UTF16ToUTF8(entry->GetLocalProfileName());
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     result->has_avatar_ring =
         base::FeatureList::IsEnabled(kEnableGlicAiAvatarRing) &&
         ShouldShowAvatarGradientRing(profile_);
