$NetBSD: patch-chrome_browser_ui_views_profiles_profile__menu__view__base.cc,v 1.3 2025/07/07 09:23:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -464,7 +464,7 @@ void ProfileMenuViewBase::SetProfileIden
       kIdentityImageBorder,
       /*has_dotted_ring=*/false);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
