$NetBSD: patch-src_3rdparty_chromium_services_network_public_cpp_features.cc,v 1.1 2025/12/21 09:38:37 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/network/public/cpp/features.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/services/network/public/cpp/features.cc
@@ -96,7 +96,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIso
 
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
              base::FEATURE_ENABLED_BY_DEFAULT);
