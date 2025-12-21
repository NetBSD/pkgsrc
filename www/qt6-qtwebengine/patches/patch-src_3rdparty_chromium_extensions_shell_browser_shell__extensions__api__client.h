$NetBSD: patch-src_3rdparty_chromium_extensions_shell_browser_shell__extensions__api__client.h,v 1.1 2025/12/21 09:38:29 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.h
@@ -34,14 +34,14 @@ class ShellExtensionsAPIClient : public 
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
