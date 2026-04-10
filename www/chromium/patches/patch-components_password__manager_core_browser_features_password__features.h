$NetBSD: patch-components_password__manager_core_browser_features_password__features.h,v 1.17 2026/04/10 17:31:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/features/password_features.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/password_manager/core/browser/features/password_features.h
@@ -188,7 +188,7 @@ BASE_DECLARE_FEATURE(kReduceRequirements
 // Triggers password change glow invoking Glic from settings.
 BASE_DECLARE_FEATURE(kPasswordCheckup);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
