$NetBSD: patch-chrome_browser_ui_startup_bad__flags__prompt.cc,v 1.31 2026/10/23 15:05:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -126,7 +126,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kAllowlistedExtensionID,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/40078530
     switches::kEnableSpeechDispatcher,
