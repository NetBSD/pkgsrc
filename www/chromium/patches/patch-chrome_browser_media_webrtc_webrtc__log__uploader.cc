$NetBSD: patch-chrome_browser_media_webrtc_webrtc__log__uploader.cc,v 1.21 2026/06/08 13:12:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -95,7 +95,7 @@ std::string GetLogUploadProduct(WebRtcLo
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
