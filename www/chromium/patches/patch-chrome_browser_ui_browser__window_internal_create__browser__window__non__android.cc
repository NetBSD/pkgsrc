$NetBSD: patch-chrome_browser_ui_browser__window_internal_create__browser__window__non__android.cc,v 1.1 2026/09/22 13:41:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_window/internal/create_browser_window_non_android.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/browser_window/internal/create_browser_window_non_android.cc
@@ -46,7 +46,7 @@ BrowserWindowCreateParams BrowserWindowC
 #if BUILDFLAG(IS_CHROMEOS)
   clone.display_id = display_id;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   clone.startup_id = startup_id;
 #endif
 #if BUILDFLAG(IS_OZONE)
