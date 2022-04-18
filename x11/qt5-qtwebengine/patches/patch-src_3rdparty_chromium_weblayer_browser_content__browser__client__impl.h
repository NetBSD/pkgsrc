$NetBSD: patch-src_3rdparty_chromium_weblayer_browser_content__browser__client__impl.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.h
@@ -116,7 +116,7 @@ class ContentBrowserClientImpl : public 
   void RenderProcessWillLaunch(content::RenderProcessHost* host) override;
   scoped_refptr<content::QuotaPermissionContext> CreateQuotaPermissionContext()
       override;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
