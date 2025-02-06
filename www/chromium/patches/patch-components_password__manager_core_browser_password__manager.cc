$NetBSD: patch-components_password__manager_core_browser_password__manager.cc,v 1.1 2025/02/06 09:58:01 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/password_manager/core/browser/password_manager.cc
@@ -419,7 +419,7 @@ void PasswordManager::RegisterProfilePre
       prefs::kAutofillableCredentialsAccountStoreLoginDatabase, false);
 #endif  // BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)
   registry->RegisterBooleanPref(prefs::kPasswordSharingEnabled, true);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kRelaunchChromeBubbleDismissedCounter,
                                 0);
 #endif
@@ -432,7 +432,7 @@ void PasswordManager::RegisterProfilePre
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kDeletingUndecryptablePasswordsEnabled,
                                 true);
 #endif
