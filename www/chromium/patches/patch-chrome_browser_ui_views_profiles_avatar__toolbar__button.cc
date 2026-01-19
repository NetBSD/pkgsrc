$NetBSD: patch-chrome_browser_ui_views_profiles_avatar__toolbar__button.cc,v 1.13 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -407,7 +407,7 @@ void AvatarToolbarButton::MaybeShowProfi
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (!base::FeatureList::IsEnabled(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature)) {
