$NetBSD: patch-src_3rdparty_chromium_ui_accessibility_accessibility__features.h,v 1.1 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/accessibility/accessibility_features.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/accessibility/accessibility_features.h
@@ -345,7 +345,7 @@ AX_BASE_EXPORT bool IsScreenAIOCREnabled
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kScreenAITestMode);
 AX_BASE_EXPORT bool IsScreenAITestModeEnabled();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables advanced partition allocation checks in ScreenAI service.
 // TODO(crbug.com/418199684): Remove when the bug is fixed.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(
@@ -372,7 +372,7 @@ AX_BASE_EXPORT BASE_DECLARE_FEATURE(kBlo
 AX_BASE_EXPORT bool IsBlockRootWindowAccessibleNameChangeEventEnabled();
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use the v3 version of the wasm tts engine component.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kWasmTtsComponentUpdaterV3Enabled);
 AX_BASE_EXPORT bool IsWasmTtsComponentUpdaterV3Enabled();
