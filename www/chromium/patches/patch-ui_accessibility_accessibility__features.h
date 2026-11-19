$NetBSD: patch-ui_accessibility_accessibility__features.h,v 1.32 2026/11/19 19:46:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/accessibility_features.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ ui/accessibility/accessibility_features.h
@@ -391,7 +391,7 @@ AX_BASE_EXPORT BASE_DECLARE_FEATURE(kMac
 AX_BASE_EXPORT bool IsMacAccessibilityTextOperationEnabled();
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Disable the wasm tts engine component to use dev version local extension
 // files.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kWasmTtsEngineAutoInstallDisabled);
