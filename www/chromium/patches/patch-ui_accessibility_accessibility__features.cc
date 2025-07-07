$NetBSD: patch-ui_accessibility_accessibility__features.cc,v 1.2 2025/07/07 09:23:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/accessibility_features.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/accessibility/accessibility_features.cc
@@ -524,7 +524,7 @@ bool IsBlockRootWindowAccessibleNameChan
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsComponentUpdaterEnabled,
              "WasmTtsComponentUpdaterEnabled",
              base::FEATURE_ENABLED_BY_DEFAULT);
