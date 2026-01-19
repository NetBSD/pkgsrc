$NetBSD: patch-ui_accessibility_accessibility__features.cc,v 1.13 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/accessibility_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/accessibility/accessibility_features.cc
@@ -505,7 +505,7 @@ bool IsScreenAITestModeEnabled() {
   return base::FeatureList::IsEnabled(::features::kScreenAITestMode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kScreenAIPartitionAllocAdvancedChecksEnabled,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
@@ -540,7 +540,7 @@ bool IsBlockRootWindowAccessibleNameChan
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsEngineAutoInstallDisabled,
              base::FEATURE_DISABLED_BY_DEFAULT);
 bool IsWasmTtsEngineAutoInstallDisabled() {
