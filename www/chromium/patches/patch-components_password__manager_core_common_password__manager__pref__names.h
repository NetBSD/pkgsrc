$NetBSD: patch-components_password__manager_core_common_password__manager__pref__names.h,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/common/password_manager_pref_names.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/password_manager/core/common/password_manager_pref_names.h
@@ -59,7 +59,7 @@ inline constexpr char kCredentialProvide
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 // Boolean pref controlled by the DeletingUndecryptablePasswordsEnabled policy.
 // If set to false it blocks deleting undecryptable passwords, otherwise the
 // deletion can happen.
@@ -217,7 +217,7 @@ inline constexpr char kProfileStoreDateL
 inline constexpr char kAccountStoreDateLastUsedForFilling[] =
     "password_manager.account_store_date_last_used_for_filling";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Integer indicating how many times user saw biometric authentication before
 // filling promo.
 inline constexpr char kBiometricAuthBeforeFillingPromoShownCounter[] =
@@ -253,7 +253,7 @@ inline constexpr char kPasswordManagerPr
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
@@ -286,7 +286,7 @@ inline constexpr char kLastNegativePassw
     "password_manager.last_negative_password_change_timestamp";
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // List of urls for which password manager is disabled/blocked.
 inline constexpr char kPasswordManagerBlocklist[] =
     "password_manager.password_manager_blocklist";
