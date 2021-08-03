$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_pepper_pepper__file__io__host.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/pepper/pepper_file_io_host.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/pepper/pepper_file_io_host.cc
@@ -433,7 +433,7 @@ void PepperFileIOHost::OnLocalFileOpened
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
     base::File::Error error_code) {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // Quarantining a file before its contents are available is only supported on
   // Windows and Linux.
   if (!FileOpenForWrite(open_flags_) || error_code != base::File::FILE_OK) {
@@ -454,7 +454,7 @@ void PepperFileIOHost::OnLocalFileOpened
 #endif
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 void PepperFileIOHost::OnLocalFileQuarantined(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
