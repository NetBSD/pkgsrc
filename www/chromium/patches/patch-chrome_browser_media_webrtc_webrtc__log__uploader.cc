$NetBSD: patch-chrome_browser_media_webrtc_webrtc__log__uploader.cc,v 1.2 2025/05/16 16:08:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -105,7 +105,7 @@ std::string GetLogUploadProduct() {
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
