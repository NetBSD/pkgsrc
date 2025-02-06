$NetBSD: patch-chrome_browser_ui_views_profiles_profile__menu__view__base.cc,v 1.1 2025/02/06 09:57:54 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -693,7 +693,7 @@ void ProfileMenuViewBase::SetProfileIden
       image_model, management_badge, this,
       ProfileMenuViewBase::kIdentityImageSize, kIdentityImageBorder);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
