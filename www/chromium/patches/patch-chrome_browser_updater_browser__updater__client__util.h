$NetBSD: patch-chrome_browser_updater_browser__updater__client__util.h,v 1.7 2026/07/06 13:06:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/updater/browser_updater_client_util.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ chrome/browser/updater/browser_updater_client_util.h
@@ -20,7 +20,7 @@ namespace updater {
 extern const char kUpdaterName[];
 extern const char kPrivilegedHelperName[];
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 // System level updater should only be used if the browser is owned by root.
 // During promotion, the browser will be changed to be owned by root and wheel.
