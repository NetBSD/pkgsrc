$NetBSD: patch-chrome_browser_supervised__user_classify__url__navigation__throttle.cc,v 1.31 2026/10/23 15:05:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/classify_url_navigation_throttle.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/supervised_user/classify_url_navigation_throttle.cc
@@ -44,7 +44,7 @@ namespace supervised_user {
 namespace {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 bool ShouldShowReAuthInterstitial(
     content::NavigationHandle& navigation_handle) {
 #if BUILDFLAG(IS_ANDROID)
@@ -224,7 +224,7 @@ void ClassifyUrlNavigationThrottle::OnIn
     case InterstitialResultCallbackActions::kCancelWithInterstitial: {
       CHECK(navigation_handle());
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       if (ShouldShowReAuthInterstitial(*navigation_handle())) {
         // Show the re-authentication interstitial if the user signed out of
         // the content area, as parent's approval requires authentication.
