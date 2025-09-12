$NetBSD: patch-chrome_browser_browser__features.cc,v 1.7 2025/09/12 16:02:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browser_features.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/browser_features.cc
@@ -80,7 +80,7 @@ BASE_FEATURE(kClearUserDataUponProfileDe
              "ClearUserDataUponProfileDestruction",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables usage of os_crypt_async::SecretPortalKeyProvider.  Once
 // `kSecretPortalKeyProviderUseForEncryption` is enabled, this flag cannot be
 // disabled without losing data.
@@ -99,7 +99,7 @@ BASE_FEATURE(kUseFreedesktopSecretKeyPro
 // the browser exits.
 BASE_FEATURE(kDestroyProfileOnBrowserClose,
              "DestroyProfileOnBrowserClose",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -241,7 +241,7 @@ BASE_FEATURE(kSandboxExternalProtocolBlo
              "SandboxExternalProtocolBlockedWarning",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If true, encrypt new data with the key provided by SecretPortalKeyProvider.
 // Otherwise, it will only decrypt existing data.
 BASE_FEATURE(kSecretPortalKeyProviderUseForEncryption,
