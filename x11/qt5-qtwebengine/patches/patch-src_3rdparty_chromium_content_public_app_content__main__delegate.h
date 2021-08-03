$NetBSD: patch-src_3rdparty_chromium_content_public_app_content__main__delegate.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/app/content_main_delegate.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/public/app/content_main_delegate.h
@@ -60,7 +60,7 @@ class CONTENT_EXPORT ContentMainDelegate
   // Called right before the process exits.
   virtual void ProcessExiting(const std::string& process_type) {}
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Tells the embedder that the zygote process is starting, and allows it to
   // specify one or more zygote delegates if it wishes by storing them in
   // |*delegates|.
