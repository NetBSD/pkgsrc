$NetBSD: patch-chrome_browser_ui_views_profiles_avatar__toolbar__button__state__manager.cc,v 1.9 2026/10/13 13:16:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.cc
@@ -2675,7 +2675,7 @@ void AvatarToolbarButtonStateManager::Ma
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButtonStateManager::MaybeShowSupervisedUserSignInIPH() {
   if (!base::FeatureList::IsEnabled(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature)) {
