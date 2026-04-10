$NetBSD: patch-chrome_browser_media_webrtc_webrtc__logging__controller.h,v 1.17 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/webrtc_logging_controller.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/media/webrtc/webrtc_logging_controller.h
@@ -147,7 +147,7 @@ class WebRtcLoggingController
 
   base::RepeatingCallback<void(const std::string&)> GetLogMessageCallback();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Ensures that the WebRTC Logs directory exists and then grants render
   // process access to the 'WebRTC Logs' directory, and invokes |callback| with
   // the ids necessary to create a DirectoryEntry object.
@@ -226,7 +226,7 @@ class WebRtcLoggingController
   bool CheckCanOperationProceed(GenericDoneCallback& callback);
   bool CheckCanOperationProceed(UploadDoneCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Grants the render process access to the 'WebRTC Logs' directory, and
   // invokes |callback| with the ids necessary to create a DirectoryEntry
   // object. If the |logs_path| couldn't be created or found, |error_callback|
