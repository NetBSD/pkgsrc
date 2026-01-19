$NetBSD: patch-chrome_browser_supervised__user_classify__url__navigation__throttle.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/classify_url_navigation_throttle.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/supervised_user/classify_url_navigation_throttle.cc
@@ -41,7 +41,7 @@ namespace supervised_user {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool ShouldShowReAuthInterstitial(
     content::NavigationHandle& navigation_handle) {
   Profile* profile = Profile::FromBrowserContext(
@@ -208,7 +208,7 @@ void ClassifyUrlNavigationThrottle::OnIn
     }
     case InterstitialResultCallbackActions::kCancelWithInterstitial: {
       CHECK(navigation_handle());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (ShouldShowReAuthInterstitial(*navigation_handle())) {
         // Show the re-authentication interstitial if the user signed out of
         // the content area, as parent's approval requires authentication.
