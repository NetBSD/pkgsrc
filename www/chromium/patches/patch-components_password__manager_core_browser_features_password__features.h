$NetBSD: patch-components_password__manager_core_browser_features_password__features.h,v 1.15 2026/02/15 09:04:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/features/password_features.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/password_manager/core/browser/features/password_features.h
@@ -171,7 +171,7 @@ BASE_DECLARE_FEATURE(kPasswordManagerLog
 // classifications.
 BASE_DECLARE_FEATURE(kProactivelyDownloadModelForPasswordChange);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
