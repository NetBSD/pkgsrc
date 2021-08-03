$NetBSD: patch-src_3rdparty_chromium_chrome_browser_media_webrtc_webrtc__event__log__uploader.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -36,7 +36,7 @@ constexpr size_t kExpectedMimeOverheadBy
 const char kProduct[] = "Chrome";
 #elif defined(OS_MACOSX)
 const char kProduct[] = "Chrome_Mac";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const char kProduct[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
