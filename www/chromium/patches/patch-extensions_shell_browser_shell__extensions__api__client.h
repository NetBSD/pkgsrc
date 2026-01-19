$NetBSD: patch-extensions_shell_browser_shell__extensions__api__client.h,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/shell/browser/shell_extensions_api_client.h.orig	2026-01-07 00:50:30.000000000 +0000
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
