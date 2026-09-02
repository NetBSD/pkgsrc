$NetBSD: patch-chrome_browser_ui_views_toolbar_avatar__toolbar__button__interface.h,v 1.5 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/toolbar/avatar_toolbar_button_interface.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/toolbar/avatar_toolbar_button_interface.h
@@ -87,7 +87,7 @@ class AvatarToolbarButtonInterface {
   // Attempts showing the In-Product-Help for profile Switching.
   virtual void MaybeShowProfileSwitchIPH() = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Attempts showing the In-Product-Help when a supervised user signs-in in a
   // profile.
   virtual void MaybeShowSupervisedUserSignInIPH() = 0;
