$NetBSD: patch-extensions_shell_browser_shell__extensions__api__client.h,v 1.19 2026/05/10 15:29:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/shell/browser/shell_extensions_api_client.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ extensions/shell/browser/shell_extensions_api_client.h
@@ -42,14 +42,14 @@ class ShellExtensionsAPIClient : public 
       content::BrowserContext* browser_context) const override;
   std::unique_ptr<DisplayInfoProvider> CreateDisplayInfoProvider()
       const override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   FileSystemDelegate* GetFileSystemDelegate() override;
 #endif
   MessagingDelegate* GetMessagingDelegate() override;
   FeedbackPrivateDelegate* GetFeedbackPrivateDelegate() override;
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<FileSystemDelegate> file_system_delegate_;
 #endif
   std::unique_ptr<MessagingDelegate> messaging_delegate_;
