$NetBSD: patch-chrome_browser_after__startup__task__utils.cc,v 1.24 2026/08/09 06:31:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/after_startup_task_utils.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/after_startup_task_utils.cc
@@ -112,7 +112,7 @@ void SetBrowserStartupIsComplete() {
                        TRACE_EVENT_SCOPE_GLOBAL, "BrowserCount", browser_count);
   GetStartupCompleteFlag().Set();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
