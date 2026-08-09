$NetBSD: patch-chrome_browser_ui_views_profiles_avatar__toolbar__button.cc,v 1.23 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -460,7 +460,7 @@ void AvatarToolbarButton::MaybeShowProfi
   state_manager_.MaybeShowProfileSwitchIPH();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   state_manager_.MaybeShowSupervisedUserSignInIPH();
 }
