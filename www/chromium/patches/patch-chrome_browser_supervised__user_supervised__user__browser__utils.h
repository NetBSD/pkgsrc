$NetBSD: patch-chrome_browser_supervised__user_supervised__user__browser__utils.h,v 1.6 2025/09/08 13:24:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_browser_utils.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_browser_utils.h
@@ -52,7 +52,7 @@ std::string GetAccountGivenName(Profile&
 // of the user.
 void AssertChildStatusOfTheUser(Profile* profile, bool is_child);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the html content of the reauthentication interstitial for blocked
 // sites. This interstitial is associated with the given NavigationHandle.
 std::string CreateReauthenticationInterstitialForBlockedSites(
