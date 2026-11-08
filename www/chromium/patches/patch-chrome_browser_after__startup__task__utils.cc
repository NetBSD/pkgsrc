$NetBSD: patch-chrome_browser_after__startup__task__utils.cc,v 1.32 2026/11/08 15:38:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/after_startup_task_utils.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/after_startup_task_utils.cc
@@ -125,7 +125,7 @@ void SetBrowserStartupIsComplete(Startup
   GetStartupCompleteFlag().Set();
   base::UmaHistogramEnumeration("Startup.BrowserStartupCompleteReason", reason);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
