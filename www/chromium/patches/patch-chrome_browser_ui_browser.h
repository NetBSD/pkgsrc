$NetBSD: patch-chrome_browser_ui_browser.h,v 1.20 2026/06/01 10:09:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser.h.orig	2026-05-26 20:39:02.000000000 +0000
+++ chrome/browser/ui/browser.h
@@ -256,7 +256,7 @@ class Browser : public TabStripModelObse
     std::optional<int64_t> display_id;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // When the browser window is shown, the desktop environment is notified
     // using this ID.  In response, the desktop will stop playing the "waiting
     // for startup" animation (if any).
