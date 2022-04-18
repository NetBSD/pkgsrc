$NetBSD: patch-src_3rdparty_chromium_headless_lib_headless__content__main__delegate.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/headless/lib/headless_content_main_delegate.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/headless_content_main_delegate.h
@@ -57,7 +57,7 @@ class HEADLESS_EXPORT HeadlessContentMai
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
