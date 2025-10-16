$NetBSD: patch-chrome_browser_browser__features.h,v 1.8 2025/10/16 19:43:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browser_features.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/browser_features.h
@@ -41,7 +41,7 @@ BASE_DECLARE_FEATURE(kCertificateTranspa
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 BASE_DECLARE_FEATURE(kClearUserDataUponProfileDestruction);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProvider);
 #endif
@@ -91,7 +91,7 @@ BASE_DECLARE_FEATURE(kRestartNetworkServ
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProviderForEncryption);
 #endif
