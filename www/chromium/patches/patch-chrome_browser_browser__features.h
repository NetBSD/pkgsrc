$NetBSD: patch-chrome_browser_browser__features.h,v 1.5 2025/08/13 07:44:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browser_features.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/browser_features.h
@@ -38,7 +38,7 @@ BASE_DECLARE_FEATURE(kCertificateTranspa
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 BASE_DECLARE_FEATURE(kClearUserDataUponProfileDestruction);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProvider);
 #endif
@@ -101,7 +101,7 @@ BASE_DECLARE_FEATURE(kRestartNetworkServ
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProviderForEncryption);
 #endif
