$NetBSD: patch-ui_accessibility_accessibility__features.cc,v 1.24 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/accessibility_features.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/accessibility/accessibility_features.cc
@@ -498,7 +498,7 @@ bool IsScreenAITestModeEnabled() {
   return base::FeatureList::IsEnabled(::features::kScreenAITestMode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kScreenAIPartitionAllocAdvancedChecksEnabled,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
@@ -539,7 +539,7 @@ bool IsMacAccessibilityTextOperationEnab
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsEngineAutoInstallDisabled,
              base::FEATURE_DISABLED_BY_DEFAULT);
 bool IsWasmTtsEngineAutoInstallDisabled() {
