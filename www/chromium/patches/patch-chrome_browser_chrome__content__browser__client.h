$NetBSD: patch-chrome_browser_chrome__content__browser__client.h,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_content_browser_client.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/chrome_content_browser_client.h
@@ -584,7 +584,7 @@ class ChromeContentBrowserClient : publi
       const GURL& site_url) override;
   std::unique_ptr<content::TracingDelegate> CreateTracingDelegate() override;
   bool IsSystemWideTracingEnabled() override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
