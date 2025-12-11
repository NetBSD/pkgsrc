$NetBSD: patch-chrome_browser_ui_startup_startup__tab__provider.cc,v 1.11 2025/12/11 09:13:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/startup_tab_provider.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/ui/startup/startup_tab_provider.cc
@@ -66,7 +66,7 @@
 #include "extensions/common/manifest_handlers/chrome_url_overrides_handler.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_util.h"
 #endif
 
@@ -124,7 +124,7 @@ bool ValidateUrl(const GURL& url) {
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
   bool url_scheme_is_chrome = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // In Headless mode, allow any URL pattern that matches chrome:// scheme if
   // the user explicitly allowed it.
   if (headless::IsHeadlessMode() && url.SchemeIs(content::kChromeUIScheme)) {
