$NetBSD: patch-components_password__manager_core_browser_features_password__features.h,v 1.30 2026/10/16 15:30:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/features/password_features.h.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/password_manager/core/browser/features/password_features.h
@@ -204,7 +204,7 @@ BASE_DECLARE_FEATURE(kPreventPasswordMan
 // vault passphrase type.
 BASE_DECLARE_FEATURE(kRecordPasswordReadiness);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
