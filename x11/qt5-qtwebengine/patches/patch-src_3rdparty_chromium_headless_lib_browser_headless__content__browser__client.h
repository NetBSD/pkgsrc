$NetBSD: patch-src_3rdparty_chromium_headless_lib_browser_headless__content__browser__client.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.h.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.h
@@ -29,7 +29,7 @@ class HeadlessContentBrowserClient : pub
       override;
   content::GeneratedCodeCacheSettings GetGeneratedCodeCacheSettings(
       content::BrowserContext* context) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
