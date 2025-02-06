$NetBSD: patch-content_browser_webui_web__ui__main__frame__observer.h,v 1.1 2025/02/06 09:58:06 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/webui/web_ui_main_frame_observer.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/webui/web_ui_main_frame_observer.h
@@ -44,7 +44,7 @@ class CONTENT_EXPORT WebUIMainFrameObser
 
 // TODO(crbug.com/40149439) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On official Google builds, capture and report JavaScript error messages on
   // WebUI surfaces back to Google. This allows us to fix JavaScript errors and
   // exceptions.
@@ -60,7 +60,7 @@ class CONTENT_EXPORT WebUIMainFrameObser
   void ReadyToCommitNavigation(NavigationHandle* navigation_handle) override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void MaybeEnableWebUIJavaScriptErrorReporting(
       NavigationHandle* navigation_handle);
 
