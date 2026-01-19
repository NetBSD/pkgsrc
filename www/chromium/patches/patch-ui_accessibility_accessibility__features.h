$NetBSD: patch-ui_accessibility_accessibility__features.h,v 1.13 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/accessibility_features.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/accessibility/accessibility_features.h
@@ -391,7 +391,7 @@ AX_BASE_EXPORT bool IsScreenAIOCREnabled
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kScreenAITestMode);
 AX_BASE_EXPORT bool IsScreenAITestModeEnabled();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables advanced partition allocation checks in ScreenAI service.
 // TODO(crbug.com/418199684): Remove when the bug is fixed.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(
@@ -418,7 +418,7 @@ AX_BASE_EXPORT BASE_DECLARE_FEATURE(kBlo
 AX_BASE_EXPORT bool IsBlockRootWindowAccessibleNameChangeEventEnabled();
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Disable the wasm tts engine component to use dev version local extension
 // files.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kWasmTtsEngineAutoInstallDisabled);
