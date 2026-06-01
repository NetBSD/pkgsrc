$NetBSD: patch-chrome_browser_screen__ai_screen__ai__install__state.cc,v 1.20 2026/06/01 10:09:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -30,7 +30,7 @@ bool IsDeviceCompatible() {
   // TODO(crbug.com/381256355): Update when ScreenAI library is compatible with
   // older CPUs.
   static const bool device_compatible = base::CPU().has_sse42();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the library is only built for X86 CPUs.
   static constexpr bool device_compatible = false;
 #else
