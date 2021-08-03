$NetBSD: patch-src_3rdparty_chromium_headless_lib_headless__content__main__delegate.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/headless/lib/headless_content_main_delegate.h.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/headless_content_main_delegate.h
@@ -57,7 +57,7 @@ class HEADLESS_EXPORT HeadlessContentMai
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
