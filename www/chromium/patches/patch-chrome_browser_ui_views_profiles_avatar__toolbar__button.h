$NetBSD: patch-chrome_browser_ui_views_profiles_avatar__toolbar__button.h,v 1.15 2026/03/14 12:40:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -97,7 +97,7 @@ class AvatarToolbarButton : public Toolb
   // Attempts showing the In-Product-Help for profile Switching.
   void MaybeShowProfileSwitchIPH();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   void MaybeShowSupervisedUserSignInIPH();
