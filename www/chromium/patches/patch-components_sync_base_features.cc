$NetBSD: patch-components_sync_base_features.cc,v 1.9 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/base/features.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/sync/base/features.cc
@@ -68,7 +68,7 @@ BASE_FEATURE(kReplaceSyncPromosWithSignI
 );
 
 bool IsReplaceSyncPromosWithSignInPromosEnabled() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return base::FeatureList::IsEnabled(kReplaceSyncPromosWithSignInPromos);
