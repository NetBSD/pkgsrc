$NetBSD: patch-chrome_browser_glic_host_glic__page__handler.cc,v 1.4 2026/04/10 17:31:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/host/glic_page_handler.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/glic/host/glic_page_handler.cc
@@ -179,7 +179,7 @@ mojom::FormFactor GetGlicFormFactor(ui::
 constexpr mojom::Platform kPlatform = mojom::Platform::kMacOS;
 #elif BUILDFLAG(IS_WIN)
 constexpr mojom::Platform kPlatform = mojom::Platform::kWindows;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr mojom::Platform kPlatform = mojom::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
 constexpr mojom::Platform kPlatform = mojom::Platform::kChromeOS;
