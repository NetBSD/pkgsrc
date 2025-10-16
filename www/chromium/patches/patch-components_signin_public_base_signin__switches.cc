$NetBSD: patch-components_signin_public_base_signin__switches.cc,v 1.7 2025/10/16 19:43:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/base/signin_switches.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/signin/public/base/signin_switches.cc
@@ -73,7 +73,7 @@ BASE_FEATURE(kSupportWebSigninAddSession
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the History Sync Opt-in on Desktop.
 BASE_FEATURE(kEnableHistorySyncOptin,
              "EnableHistorySyncOptin",
@@ -293,7 +293,7 @@ BASE_FEATURE(kSyncEnableBookmarksInTrans
 #endif  // BUILDFLAG(IS_IOS)
 );
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSignInPromoMaterialNextUI,
              "SignInPromoMaterialNextUI",
              base::FEATURE_DISABLED_BY_DEFAULT);
