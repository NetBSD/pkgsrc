$NetBSD: patch-chrome_browser_ui_views_user__education_browser__user__education__service.cc,v 1.31 2026/10/23 15:05:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -321,7 +321,7 @@ CreateNavigationAction(GURL target) {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void NavigateToSettingsPage(ContextPtr ctx,
                             user_education::FeaturePromoHandle promo_handle) {
   BrowserWindowInterface* const browser = GetBrowser(ctx);
@@ -1566,7 +1566,7 @@ void MaybeRegisterChromeFeaturePromos(
                 "Triggered when a shared tab becomes the active tab.")));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1895,7 +1895,7 @@ void MaybeRegisterChromeFeaturePromos(
               "Omnibox Everywhere.")));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -2748,7 +2748,7 @@ void MaybeRegisterChromeNewBadges(user_e
       user_education::Metadata(158, "xinlongyi@google.com",
                                "Shown on the Skills item in the app menu.")));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry.RegisterFeature(user_education::NewBadgeSpecification(
       switches::kCrossDeviceSigninFromDesktop,
       user_education::Metadata(
