$NetBSD: patch-components_password__manager_core_browser_features_password__features.h,v 1.19 2026/05/10 15:29:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/features/password_features.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/password_manager/core/browser/features/password_features.h
@@ -201,7 +201,7 @@ BASE_DECLARE_FEATURE(kReduceRequirements
 // This flag is only for the prototype version.
 BASE_DECLARE_FEATURE(kPasswordCheckupPrototype);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
