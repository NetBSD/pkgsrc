$NetBSD: patch-src_3rdparty_chromium_chrome_browser_media_webrtc_webrtc__logging__controller.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_logging_controller.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_logging_controller.cc
@@ -23,7 +23,7 @@
 #include "content/public/browser/browser_context.h"
 #include "content/public/browser/render_process_host.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/public/browser/child_process_security_policy.h"
 #include "storage/browser/file_system/isolated_context.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -272,7 +272,7 @@ void WebRtcLoggingController::StartEvent
       web_app_id, callback);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void WebRtcLoggingController::GetLogsDirectory(
     LogsDirectoryCallback callback,
     LogsDirectoryErrorCallback error_callback) {
