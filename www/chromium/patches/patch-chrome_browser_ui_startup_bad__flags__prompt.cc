$NetBSD: patch-chrome_browser_ui_startup_bad__flags__prompt.cc,v 1.23 2026/07/08 13:42:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -115,7 +115,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnExtensionURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/40078530
     switches::kEnableSpeechDispatcher,
