$NetBSD: patch-src_3rdparty_chromium_content_public_app_content__main__delegate.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/public/app/content_main_delegate.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/public/app/content_main_delegate.h
@@ -49,7 +49,7 @@ class CONTENT_EXPORT ContentMainDelegate
   // Called right before the process exits.
   virtual void ProcessExiting(const std::string& process_type) {}
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Tells the embedder that the zygote process is starting, and allows it to
   // specify one or more zygote delegates if it wishes by storing them in
   // |*delegates|.
