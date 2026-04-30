$NetBSD: patch-src_3rdparty_chromium_extensions_shell_browser_shell__extensions__api__client.cc,v 1.2 2026/04/30 06:39:40 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.cc
@@ -18,7 +18,7 @@
 #include "extensions/shell/browser/shell_extension_web_contents_observer.h"
 #include "extensions/shell/browser/shell_virtual_keyboard_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/shell/browser/api/file_system/shell_file_system_delegate.h"
 #endif
 
@@ -76,7 +76,7 @@ ShellExtensionsAPIClient::CreateDisplayI
   return std::make_unique<ShellDisplayInfoProvider>();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 FileSystemDelegate* ShellExtensionsAPIClient::GetFileSystemDelegate() {
   if (!file_system_delegate_)
     file_system_delegate_ = std::make_unique<ShellFileSystemDelegate>();
