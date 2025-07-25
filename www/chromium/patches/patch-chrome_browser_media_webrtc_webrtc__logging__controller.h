$NetBSD: patch-chrome_browser_media_webrtc_webrtc__logging__controller.h,v 1.4 2025/07/25 16:17:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/webrtc_logging_controller.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/media/webrtc/webrtc_logging_controller.h
@@ -133,7 +133,7 @@ class WebRtcLoggingController
                          size_t web_app_id,
                          const StartEventLoggingCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Ensures that the WebRTC Logs directory exists and then grants render
   // process access to the 'WebRTC Logs' directory, and invokes |callback| with
   // the ids necessary to create a DirectoryEntry object.
@@ -197,7 +197,7 @@ class WebRtcLoggingController
 
   content::BrowserContext* GetBrowserContext() const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Grants the render process access to the 'WebRTC Logs' directory, and
   // invokes |callback| with the ids necessary to create a DirectoryEntry
   // object. If the |logs_path| couldn't be created or found, |error_callback|
