$NetBSD: patch-chrome_browser_ui_views_profiles_profile__picker__view.cc,v 1.24 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -87,7 +87,7 @@
 #include "chrome/browser/global_keyboard_shortcuts_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
