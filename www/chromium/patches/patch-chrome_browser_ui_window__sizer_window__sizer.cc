$NetBSD: patch-chrome_browser_ui_window__sizer_window__sizer.cc,v 1.25 2026/09/02 13:13:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -224,7 +224,7 @@ void WindowSizer::GetBrowserWindowBounds
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
