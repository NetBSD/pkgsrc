$NetBSD: patch-chrome_browser_ui_views_profiles_profile__menu__coordinator.cc,v 1.32 2026/11/19 19:45:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_menu_coordinator.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_menu_coordinator.cc
@@ -95,7 +95,7 @@ void ProfileMenuCoordinator::ShowWithPro
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHProfileSwitchFeature,
           FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserUserEducationInterface::From(GetBrowser())
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature,
