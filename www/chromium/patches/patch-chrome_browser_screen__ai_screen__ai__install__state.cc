$NetBSD: patch-chrome_browser_screen__ai_screen__ai__install__state.cc,v 1.1 2025/02/06 09:57:50 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -16,7 +16,7 @@
 #include "services/screen_ai/public/cpp/utilities.h"
 #include "ui/accessibility/accessibility_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #include "base/files/file_util.h"
 #endif
@@ -26,7 +26,7 @@ const int kScreenAICleanUpDelayInDays = 
 const char kMinExpectedVersion[] = "124.2";
 
 bool IsDeviceCompatible() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
