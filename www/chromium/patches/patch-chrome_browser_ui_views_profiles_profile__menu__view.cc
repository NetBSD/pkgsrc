$NetBSD: patch-chrome_browser_ui_views_profiles_profile__menu__view.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_menu_view.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_menu_view.cc
@@ -112,7 +112,7 @@
 #include "ui/views/accessibility/view_accessibility.h"
 #include "ui/views/widget/widget.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
 
@@ -591,7 +591,7 @@ void ProfileMenuView::SetMenuTitleForAcc
     case signin_util::SignedInState::kSignedOut:
     case signin_util::SignedInState::kWebOnlySignedIn: {
       std::string profile_user_display_name, profile_user_email;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       profile_user_display_name = profile().GetPrefs()->GetString(
           enterprise_signin::prefs::kProfileUserDisplayName);
       profile_user_email = profile().GetPrefs()->GetString(
