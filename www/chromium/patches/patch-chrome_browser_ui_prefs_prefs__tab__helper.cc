$NetBSD: patch-chrome_browser_ui_prefs_prefs__tab__helper.cc,v 1.7 2025/10/16 19:43:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/prefs/prefs_tab_helper.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/prefs/prefs_tab_helper.cc
@@ -64,7 +64,7 @@
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
+    BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS) || BUILDFLAG(IS_BSD)
 // If a font name in prefs default values starts with a comma, consider it's a
 // comma-separated font list and resolve it to the first available font.
 #define PREFS_FONT_LIST 1
