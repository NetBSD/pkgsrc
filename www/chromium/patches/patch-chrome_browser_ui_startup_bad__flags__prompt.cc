$NetBSD: patch-chrome_browser_ui_startup_bad__flags__prompt.cc,v 1.26 2026/09/22 13:41:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -121,7 +121,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kAllowlistedExtensionID,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/40078530
     switches::kEnableSpeechDispatcher,
