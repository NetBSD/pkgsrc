$NetBSD: patch-services_network_public_cpp_features.cc,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/public/cpp/features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/network/public/cpp/features.cc
@@ -93,7 +93,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIso
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 BASE_FEATURE(kDnsOverHttpsUpgrade,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -361,7 +361,7 @@ BASE_FEATURE(kAvoidResourceRequestCopies
 // https://github.com/WICG/document-isolation-policy
 BASE_FEATURE(kDocumentIsolationPolicy,
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
