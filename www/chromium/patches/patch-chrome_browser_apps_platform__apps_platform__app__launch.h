$NetBSD: patch-chrome_browser_apps_platform__apps_platform__app__launch.h,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/apps/platform_apps/platform_app_launch.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/apps/platform_apps/platform_app_launch.h
@@ -38,7 +38,7 @@ bool OpenExtensionApplicationWindow(Prof
 content::WebContents* OpenExtensionApplicationTab(Profile* profile,
                                                   const std::string& app_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Opens the deprecated Chrome Apps flow if |app_id| refers to a Chrome App and
 // Chrome Apps are deprecated on the |profile|. Returns true if that was the
 // case, or false otherwise.
