$NetBSD: patch-chrome_browser_ui_views_profiles_profile__picker__view.cc,v 1.30 2026/10/16 15:30:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -93,7 +93,7 @@
 #include "chrome/browser/renderer_host/chrome_render_widget_host_view_mac_history_swiping_control.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
