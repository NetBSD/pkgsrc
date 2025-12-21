$NetBSD: patch-src_3rdparty_chromium_components_password__manager_core_common_password__manager__pref__names.h,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/password_manager/core/common/password_manager_pref_names.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/components/password_manager/core/common/password_manager_pref_names.h
@@ -324,7 +324,7 @@ inline constexpr char kPasswordManagerPr
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
