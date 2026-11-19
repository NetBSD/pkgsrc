$NetBSD: patch-chrome_browser_supervised__user_supervised__user__browser__utils.h,v 1.33 2026/11/19 19:45:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_browser_utils.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_browser_utils.h
@@ -47,14 +47,14 @@ ProfileSelections BuildProfileSelections
 std::string GetAccountGivenName(Profile& profile);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Returns the html content of the reauthentication interstitial for blocked
 // sites. This interstitial is associated with the given NavigationHandle.
 std::string CreateReauthenticationInterstitialForBlockedSites(
     content::NavigationHandle& navigation_handle);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitialForYouTube(
     content::NavigationHandle& navigation_handle);
 #endif
