$NetBSD: patch-chrome_browser_media_webrtc_webrtc__log__uploader.cc,v 1.22 2026/07/06 13:06:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -97,7 +97,7 @@ std::string GetLogUploadProduct(WebRtcLo
   const char product[] = "Chrome";
 #elif BUILDFLAG(IS_MAC)
   const char product[] = "Chrome_Mac";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
