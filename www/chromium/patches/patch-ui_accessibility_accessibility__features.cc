$NetBSD: patch-ui_accessibility_accessibility__features.cc,v 1.28 2026/10/13 13:16:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/accessibility_features.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ ui/accessibility/accessibility_features.cc
@@ -476,7 +476,7 @@ bool IsScreenAITestModeEnabled() {
   return base::FeatureList::IsEnabled(::features::kScreenAITestMode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kScreenAIPartitionAllocAdvancedChecksEnabled,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
@@ -517,7 +517,7 @@ bool IsMacAccessibilityTextOperationEnab
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsEngineAutoInstallDisabled,
              base::FEATURE_DISABLED_BY_DEFAULT);
 bool IsWasmTtsEngineAutoInstallDisabled() {
