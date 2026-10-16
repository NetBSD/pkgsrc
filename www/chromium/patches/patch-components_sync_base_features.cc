$NetBSD: patch-components_sync_base_features.cc,v 1.6 2026/10/16 15:30:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/base/features.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/sync/base/features.cc
@@ -83,7 +83,7 @@ BASE_FEATURE(kReplaceSyncPromosWithSignI
 );
 
 BASE_FEATURE(kReplaceSyncPromosWithSigninPromosNewSignin,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
