$NetBSD: patch-net_base_features.cc,v 1.17 2026/04/10 17:31:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/features.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ net/base/features.cc
@@ -33,7 +33,7 @@ BASE_FEATURE(kCapReferrerToOriginOnCross
 
 BASE_FEATURE(kAsyncDns,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -302,7 +302,7 @@ inline constexpr auto kMigrateSessionsOn
 BASE_FEATURE(kMigrateSessionsOnNetworkChangeV2,
              kMigrateSessionsOnNetworkChangeV2Default);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAddressTrackerLinuxIsProxied, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -423,7 +423,7 @@ BASE_FEATURE(kReportingApiEnableEnterpri
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kSimdutfBase64Support,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
