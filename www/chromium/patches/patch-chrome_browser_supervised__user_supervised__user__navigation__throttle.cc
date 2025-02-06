$NetBSD: patch-chrome_browser_supervised__user_supervised__user__navigation__throttle.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_navigation_throttle.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_navigation_throttle.cc
@@ -213,7 +213,7 @@ void SupervisedUserNavigationThrottle::O
     case kCancelWithInterstitial: {
       CHECK(navigation_handle());
 // LINT.IfChange(cancel_with_interstitial)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (supervised_user::ShouldShowReAuthInterstitial(*navigation_handle(),
                                                         is_main_frame)) {
         // Show the re-authentication interstitial if the user signed out of
@@ -244,7 +244,7 @@ void SupervisedUserNavigationThrottle::O
 }
 
 namespace supervised_user {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 bool ShouldShowReAuthInterstitial(content::NavigationHandle& navigation_handle,
                                   bool is_main_frame) {
