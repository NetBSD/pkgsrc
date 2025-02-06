$NetBSD: patch-chrome_browser_supervised__user_classify__url__navigation__throttle.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/classify_url_navigation_throttle.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/supervised_user/classify_url_navigation_throttle.cc
@@ -219,7 +219,7 @@ void ClassifyUrlNavigationThrottle::OnIn
     case SupervisedUserNavigationThrottle::kCancelWithInterstitial: {
       CHECK(navigation_handle());
 // LINT.IfChange(cancel_with_interstitial)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (ShouldShowReAuthInterstitial(*navigation_handle(), is_main_frame)) {
         // Show the re-authentication interstitial if the user signed out of
         // the content area, as parent's approval requires authentication.
