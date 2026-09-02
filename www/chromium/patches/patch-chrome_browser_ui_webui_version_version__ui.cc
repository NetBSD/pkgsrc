$NetBSD: patch-chrome_browser_ui_webui_version_version__ui.cc,v 1.2 2026/09/02 13:13:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/version/version_ui.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/webui/version/version_ui.cc
@@ -209,7 +209,7 @@ int VersionUI::VersionProcessorVariation
   return IDS_VERSION_UI_64BIT;
 #endif  // defined(ARCH_CPU_X86)
 #endif  // defined(ARCH_CPU_ARM64)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_X86_64)
   return IDS_VERSION_UI_64BIT_INTEL;
 #elif defined(ARCH_CPU_ARM64)
