$NetBSD: patch-chrome_browser_ui_startup_bad__flags__prompt.cc,v 1.4 2025/07/25 16:17:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -95,7 +95,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnChromeURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
