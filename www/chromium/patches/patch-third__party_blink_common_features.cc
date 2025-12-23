$NetBSD: patch-third__party_blink_common_features.cc,v 1.9 2025/12/23 13:22:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/common/features.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ third_party/blink/common/features.cc
@@ -588,7 +588,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
 BASE_FEATURE(kDevToolsImprovedNetworkError, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1946,7 +1946,7 @@ BASE_FEATURE(kPrefetchFontLookupTables,
 // currently out of scope.
 BASE_FEATURE(kPreloadingEagerHoverHeuristics,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
