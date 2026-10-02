$NetBSD: patch-chrome_browser_screen__ai_screen__ai__install__state.cc,v 1.28 2026/10/02 11:43:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -37,7 +37,7 @@ bool ScreenAIInstallState::IsDeviceCompa
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
   static const bool device_compatible = base::CPU().has_sse42();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the library is only built for X86 CPUs.
   static constexpr bool device_compatible = false;
 #else
