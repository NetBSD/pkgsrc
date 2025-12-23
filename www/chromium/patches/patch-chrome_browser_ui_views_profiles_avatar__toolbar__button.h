$NetBSD: patch-chrome_browser_ui_views_profiles_avatar__toolbar__button.h,v 1.12 2025/12/23 13:22:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -96,7 +96,7 @@ class AvatarToolbarButton : public Toolb
   // Attempts showing the In-Product-Help for profile Switching.
   void MaybeShowProfileSwitchIPH();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   void MaybeShowSupervisedUserSignInIPH();
