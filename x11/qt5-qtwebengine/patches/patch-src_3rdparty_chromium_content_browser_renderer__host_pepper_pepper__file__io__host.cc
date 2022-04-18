$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_pepper_pepper__file__io__host.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/pepper/pepper_file_io_host.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/pepper/pepper_file_io_host.cc
@@ -438,7 +438,7 @@ void PepperFileIOHost::OnLocalFileOpened
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
     base::File::Error error_code) {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Quarantining a file before its contents are available is only supported on
   // Windows and Linux.
   if (!FileOpenForWrite(open_flags_) || error_code != base::File::FILE_OK) {
@@ -459,7 +459,7 @@ void PepperFileIOHost::OnLocalFileOpened
 #endif
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void PepperFileIOHost::OnLocalFileQuarantined(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
