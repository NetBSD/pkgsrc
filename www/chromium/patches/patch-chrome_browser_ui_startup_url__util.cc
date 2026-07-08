$NetBSD: patch-chrome_browser_ui_startup_url__util.cc,v 1.3 2026/07/08 13:42:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/url_util.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/ui/startup/url_util.cc
@@ -13,7 +13,7 @@
 #include "url/gurl.h"
 #include "url/url_constants.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_util.h"
 #endif
 
@@ -59,7 +59,7 @@ bool ValidateLaunchUrlWebUnsafe(const GU
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
   bool url_scheme_is_chrome = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // In Headless mode, allow any URL pattern that matches chrome:// scheme if
   // the user explicitly allowed it.
   if (headless::IsHeadlessMode() && url.SchemeIs(content::kChromeUIScheme)) {
