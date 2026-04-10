$NetBSD: patch-chrome_browser_ui_window__sizer_window__sizer.cc,v 1.17 2026/04/10 17:31:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -226,7 +226,7 @@ void WindowSizer::GetBrowserWindowBounds
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
