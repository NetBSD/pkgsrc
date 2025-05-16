$NetBSD: patch-chrome_browser_ui_prefs_prefs__tab__helper.cc,v 1.1 2025/05/16 16:08:19 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/prefs/prefs_tab_helper.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/ui/prefs/prefs_tab_helper.cc
@@ -66,7 +66,7 @@
 #include <windows.h>
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If a font name in prefs default values starts with a comma, consider it's a
 // comma-separated font list and resolve it to the first available font.
 #define PREFS_FONT_LIST 1
