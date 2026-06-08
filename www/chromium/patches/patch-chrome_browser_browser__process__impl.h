$NetBSD: patch-chrome_browser_browser__process__impl.h,v 1.21 2026/06/08 13:12:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browser_process_impl.h.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/browser_process_impl.h
@@ -436,7 +436,7 @@ class BrowserProcessImpl : public Browse
 
   std::unique_ptr<BatteryMetrics> battery_metrics_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::RepeatingTimer autoupdate_timer_;
 
   // Gets called by autoupdate timer to see if browser needs restart and can be
