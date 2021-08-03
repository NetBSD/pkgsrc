$NetBSD: patch-src_3rdparty_chromium_chrome_browser_media_webrtc_webrtc__logging__controller.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_logging_controller.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_logging_controller.cc
@@ -24,7 +24,7 @@
 #include "content/public/browser/render_process_host.h"
 #include "services/service_manager/public/cpp/connector.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/public/browser/child_process_security_policy.h"
 #include "storage/browser/file_system/isolated_context.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -270,7 +270,7 @@ void WebRtcLoggingController::StartEvent
       web_app_id, callback);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void WebRtcLoggingController::GetLogsDirectory(
     const LogsDirectoryCallback& callback,
     const LogsDirectoryErrorCallback& error_callback) {
