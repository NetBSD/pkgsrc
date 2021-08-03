$NetBSD: patch-src_3rdparty_chromium_chrome_browser_media_webrtc_webrtc__log__uploader.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2020-07-24 02:37:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -354,6 +354,8 @@ void WebRtcLogUploader::SetupMultipart(
 #else
   const char product[] = "Chrome_Linux_ASan";
 #endif
+#elif defined(OS_NETBSD)
+  const char product[] = "Chrome_NetBSD";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
