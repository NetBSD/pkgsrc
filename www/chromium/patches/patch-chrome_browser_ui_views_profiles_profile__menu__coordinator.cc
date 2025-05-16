$NetBSD: patch-chrome_browser_ui_views_profiles_profile__menu__coordinator.cc,v 1.1 2025/05/16 16:08:20 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_menu_coordinator.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_menu_coordinator.cc
@@ -50,7 +50,7 @@ void ProfileMenuCoordinator::Show(bool i
   browser.window()->NotifyFeaturePromoFeatureUsed(
       feature_engagement::kIPHProfileSwitchFeature,
       FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser.window()->NotifyFeaturePromoFeatureUsed(
       feature_engagement::kIPHSupervisedUserProfileSigninFeature,
       FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
