$NetBSD: patch-src_3rdparty_chromium_components_password__manager_core_common_password__manager__pref__names.h,v 1.2 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/password_manager/core/common/password_manager_pref_names.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/password_manager/core/common/password_manager_pref_names.h
@@ -59,7 +59,7 @@ inline constexpr char kCredentialProvide
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 // Boolean pref controlled by the DeletingUndecryptablePasswordsEnabled policy.
 // If set to false it blocks deleting undecryptable passwords, otherwise the
 // deletion can happen.
@@ -285,7 +285,7 @@ inline constexpr char kAutofillableCrede
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
