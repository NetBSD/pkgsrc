$NetBSD: patch-src_3rdparty_chromium_chrome_browser_media_webrtc_webrtc__log__uploader.cc,v 1.1 2025/12/21 09:38:19 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -110,7 +110,7 @@ std::string GetLogUploadProduct() {
   const char product[] = "Chrome_Mac";
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #if !defined(ADDRESS_SANITIZER)
   const char product[] = "Chrome_Linux";
 #else
