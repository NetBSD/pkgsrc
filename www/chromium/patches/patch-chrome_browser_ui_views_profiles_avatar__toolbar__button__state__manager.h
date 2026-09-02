$NetBSD: patch-chrome_browser_ui_views_profiles_avatar__toolbar__button__state__manager.h,v 1.5 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h
@@ -272,7 +272,7 @@ class AvatarToolbarButtonStateManager
 
   // Shared IPH methods.
   void MaybeShowProfileSwitchIPH();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH();
   void MaybeShowSignInBenefitsIPH();
 #endif
