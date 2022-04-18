$NetBSD: patch-src_3rdparty_chromium_chrome_browser_media_webrtc_webrtc__event__log__uploader.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -40,7 +40,7 @@ const char kProduct[] = "Chrome";
 const char kProduct[] = "Chrome_Mac";
 #elif defined(OS_CHROMEOS)
 const char kProduct[] = "Chrome_ChromeOS";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const char kProduct[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
