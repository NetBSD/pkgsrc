$NetBSD: patch-src_3rdparty_chromium_ui_accessibility_accessibility__features.cc,v 1.1 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/accessibility/accessibility_features.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/accessibility/accessibility_features.cc
@@ -518,7 +518,7 @@ bool IsScreenAITestModeEnabled() {
   return base::FeatureList::IsEnabled(::features::kScreenAITestMode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kScreenAIPartitionAllocAdvancedChecksEnabled,
              "ScreenAIPartitionAllocAdvancedChecksEnabled",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -560,7 +560,7 @@ bool IsBlockRootWindowAccessibleNameChan
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsComponentUpdaterV3Enabled,
              "WasmTtsComponentUpdaterV3Enabled",
              base::FEATURE_DISABLED_BY_DEFAULT);
