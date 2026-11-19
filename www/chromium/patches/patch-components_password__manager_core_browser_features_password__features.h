$NetBSD: patch-components_password__manager_core_browser_features_password__features.h,v 1.33 2026/11/19 19:45:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/features/password_features.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/password_manager/core/browser/features/password_features.h
@@ -182,7 +182,7 @@ BASE_DECLARE_FEATURE(kPasswordManualFall
 BASE_DECLARE_FEATURE(kPasswordSaveInContextErrorResolution);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables resolution of Trusted Vault encryption errors directly within the
 // sign-in autofill dropdown.
 BASE_DECLARE_FEATURE(kPasswordSignInInContextErrorResolution);
@@ -201,7 +201,7 @@ BASE_DECLARE_FEATURE(kPreventPasswordMan
 // vault passphrase type.
 BASE_DECLARE_FEATURE(kRecordPasswordReadiness);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
