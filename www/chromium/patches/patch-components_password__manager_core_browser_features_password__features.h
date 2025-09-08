$NetBSD: patch-components_password__manager_core_browser_features_password__features.h,v 1.6 2025/09/08 13:24:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/features/password_features.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/password_manager/core/browser/features/password_features.h
@@ -131,7 +131,7 @@ BASE_DECLARE_FEATURE(kPasswordManagerLog
 // Detects password reuse based on hashed password values.
 BASE_DECLARE_FEATURE(kReuseDetectionBasedOnPasswordHashes);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
