$NetBSD: patch-chrome_browser_ui_startup_startup__tab__provider.cc,v 1.22 2026/07/06 13:06:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/startup_tab_provider.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ chrome/browser/ui/startup/startup_tab_provider.cc
@@ -67,7 +67,7 @@
 #include "extensions/common/manifest_handlers/chrome_url_overrides_handler.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_util.h"
 #endif
 
