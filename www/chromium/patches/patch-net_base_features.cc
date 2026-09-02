$NetBSD: patch-net_base_features.cc,v 1.25 2026/09/02 13:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/features.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ net/base/features.cc
@@ -41,7 +41,7 @@ BASE_FEATURE(kDeriveConnectionTypeFromCa
 
 BASE_FEATURE(kAsyncDns,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -471,7 +471,7 @@ BASE_FEATURE(kReportingApiEnableEnterpri
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kSimdutfBase64Support,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
