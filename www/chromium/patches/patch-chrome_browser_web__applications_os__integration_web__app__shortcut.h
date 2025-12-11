$NetBSD: patch-chrome_browser_web__applications_os__integration_web__app__shortcut.h,v 1.11 2025/12/11 09:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/web_app_shortcut.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.h
@@ -23,7 +23,7 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/os_integration/web_app_shortcut_linux.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -78,7 +78,7 @@ struct ShortcutInfo {
   // the installed PWA experience and thus the icons are not designed to be
   // displayed on an OS dock.
   bool is_diy_app = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::set<DesktopActionInfo> actions;
 #endif  // BUILDFLAG(IS_LINUX)
 
