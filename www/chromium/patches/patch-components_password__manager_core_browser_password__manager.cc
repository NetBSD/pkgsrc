$NetBSD: patch-components_password__manager_core_browser_password__manager.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/password_manager/core/browser/password_manager.cc
@@ -611,12 +611,12 @@ void PasswordManager::RegisterProfilePre
   registry->RegisterListPref(prefs::kPasswordManagerPromoCardsList);
 #endif  // BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(prefs::kPasswordManagerBlocklist);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
   registry->RegisterBooleanPref(prefs::kPasswordSharingEnabled, true);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kRelaunchChromeBubbleDismissedCounter,
                                 0);
 #endif
@@ -629,7 +629,7 @@ void PasswordManager::RegisterProfilePre
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kDeletingUndecryptablePasswordsEnabled,
                                 true);
 #endif
@@ -659,7 +659,7 @@ void PasswordManager::RegisterLocalPrefs
   registry->RegisterBooleanPref(prefs::kOsPasswordBlank, false);
   registry->RegisterBooleanPref(prefs::kIsBiometricAvailable, false);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kHadBiometricsAvailable, false);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS)
   registry->RegisterListPref(prefs::kLocalPasswordHashDataList,
