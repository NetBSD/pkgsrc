$NetBSD: patch-chrome_browser_browser__features.cc,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browser_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/browser_features.cc
@@ -70,7 +70,7 @@ BASE_FEATURE(kCertVerificationNetworkTim
 BASE_FEATURE(kClearUserDataUponProfileDestruction,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables usage of os_crypt_async::SecretPortalKeyProvider.  Once
 // `kSecretPortalKeyProviderUseForEncryption` is enabled, this flag cannot be
 // disabled without losing data.
@@ -80,7 +80,7 @@ BASE_FEATURE(kDbusSecretPortal, base::FE
 // Destroy profiles when their last browser window is closed, instead of when
 // the browser exits.
 BASE_FEATURE(kDestroyProfileOnBrowserClose,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -180,7 +180,7 @@ BASE_FEATURE(kSandboxExternalProtocolBlo
 BASE_FEATURE(kSandboxExternalProtocolBlockedWarning,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If true, encrypt new data with the key provided by SecretPortalKeyProvider.
 // Otherwise, it will only decrypt existing data.
 BASE_FEATURE(kSecretPortalKeyProviderUseForEncryption,
