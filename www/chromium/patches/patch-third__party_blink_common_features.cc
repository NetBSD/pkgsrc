$NetBSD: patch-third__party_blink_common_features.cc,v 1.27 2026/10/23 15:05:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/common/features.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/blink/common/features.cc
@@ -1800,7 +1800,7 @@ BASE_FEATURE(kPrefetchFontLookupTables,
 // currently out of scope.
 BASE_FEATURE(kPreloadingEagerHoverHeuristics,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
