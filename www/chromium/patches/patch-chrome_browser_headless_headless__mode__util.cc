$NetBSD: patch-chrome_browser_headless_headless__mode__util.cc,v 1.23 2026/08/09 06:31:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/headless/headless_mode_util.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/headless/headless_mode_util.cc
@@ -9,7 +9,7 @@
 // New headless mode is available on Linux, Windows and Mac platforms.
 // More platforms will be added later, so avoid function level clutter
 // by providing stub implementations at the end of the file.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 #include "base/check_deref.h"
 #include "base/command_line.h"
