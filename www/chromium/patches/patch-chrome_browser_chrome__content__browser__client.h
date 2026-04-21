$NetBSD: patch-chrome_browser_chrome__content__browser__client.h,v 1.18 2026/04/21 15:21:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_content_browser_client.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/chrome_content_browser_client.h
@@ -582,7 +582,7 @@ class ChromeContentBrowserClient : publi
       const GURL& site_url) override;
   std::unique_ptr<content::TracingDelegate> CreateTracingDelegate() override;
   bool IsSystemWideTracingEnabled() override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
